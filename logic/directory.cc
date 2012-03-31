#include <string>
#include <boost/filesystem.hpp>
#include <boost/system/error_code.hpp>
#include <unistd.h>
#include <sys/stat.h>
#include "directory.h"

Directory::Directory(const std::string &name) : IDirectory(name)
{
}

#ifdef __GNUC__                                     // pragma exists for GCC
#pragma GCC diagnostic push                         // save the current diagnostic state
#pragma GCC diagnostic ignored "-Waggregate-return" // ignore the aggregate-return warning
#endif
// determine if the process has execute permissions for the directory
// will throw if stat() fails for some reason (path too long, symlink loops, doesn't exist, etc. see: man 2 stat)
bool Directory::isExecutable() const
{
    // stat the directory
    struct stat buf;
    int error_code = stat(getName().c_str(), &buf);
    if (error_code == -1) {
       boost::system::error_code ec(errno,boost::system::system_category());
       throw boost::system::system_error(ec);
    }
    // get the user and group id (will not fail)
    uid_t process_user_id = geteuid();
    gid_t process_group_id = getegid();
    uid_t directory_user_id = buf.st_uid;
    gid_t directory_group_id = buf.st_gid;

    // if the user owns the directory, and the directory has user execute permissions, then it's executable
    if( (process_user_id == directory_user_id) && (S_IXUSR & buf.st_mode) )
        return true;
    // if the user is in the group that owns the directory, and the directory has group execute permissions, then it's
    // executable
    if( (process_group_id == directory_group_id) && (S_IXGRP & buf.st_mode))
        return true;
    // if the user is not the directory owner, and is not in the directory's group, but the directory has execute
    // permissions for others, then it's executable
    if( S_IXOTH & buf.st_mode)
        return true;
    // if none of the above apply, the directory is not executable by the process
    return false;

}
#ifdef __GNUC__                                     // make sure were using gcc
#pragma GCC diagnostic pop                          // restore the old diagnostic state
#endif
