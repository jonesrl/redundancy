#include "ifilesystemobject.h"
#include <boost/filesystem.hpp>
#include <string>
#include <stdexcept>
#include <fstream>

// references can't be null, so there is no need to check
IFileSystemObject::IFileSystemObject(const std::string& name)
    : mName(name), mCanonicalizedName(""), mPath(name)
{
    if(name == "")
        throw std::runtime_error("FileSystemObject: name should not be empty");

}

// for base classes, this has to be defined even though it's pure virtual
// derived classes do not need to define it, unless overriding
IFileSystemObject::~IFileSystemObject()
{

}


bool IFileSystemObject::isReadable() const
{
    std::ifstream ifile(mName.c_str());
    bool accessible;
    if(ifile)
        accessible = true;
    else
        accessible = false;
    ifile.close();
    return accessible;
}
// the canonical() function in boost::filesystem will dereference symlinks
// to get the actual target, as well as remove extraneous dots and slashes
// I don't see a function in boost::filesystem that will just remove the extra
// dots and slashes, but not dereference symlinks
// make preferred will convert forward slashes to backslashes on windows, and does
// nothing on POSIX
// I think at this point the path should be stored in the generic format, and maybe get
// converted to a platform-native format at the display layer (see native vs. generic format
// in the boost::filesystem documentation
// see boost::system documentation for converting ec into a message suitable for an exception

// TODO: figure out how to handle unicode. The boost::filesystem::path class provides conversions
// using the ICU library, so I think this would be the appropriate place to do it
// NOTE: for canonical(p), p must exist, and must be readable

// It appears to me that in order to canonicalize a name
// 1) all of the path elements leading up to the name must exist and be readable
// 2) the name itself must exist
// - but - if 1) and 2) hold, then the name itself does not have to be readable
// for 1), if the parent directory of the item is readable, that would imply all directories
// leading up to it are also readable
#ifdef __GNUC__                                     // pragma exists for GCC
#pragma GCC diagnostic push                         // saves the current diagnostic state
#pragma GCC diagnostic ignored "-Waggregate-return" // ignores the aggregate-return warning
#endif
void IFileSystemObject::canonicalizeName()
{
    /* here's how to do it the non-throwing way
    boost::system::error_code ec;
    mNormalizedName = canonical(p, ec).generic_string();
    */
    boost::filesystem::path parent = mPath.parent_path();
    //empty parent means that mPath was root
    std::cout << "Parent path: " << parent.generic_string() << std::endl;
    mCanonicalizedName = boost::filesystem::canonical(mPath).generic_string();
}
#ifdef __GNUC__                                     // make sure were using gcc
#pragma GCC diagnostic pop                          // restore the old diagnostic state
#endif
// TODO: throw a runtime exception if this is called before normalizeName is called
// returning a const reference to prevent clients from modifying private data
// TODO: figure out under what conditions normalize() will return an empty string
//       there might be more cases than normalizing a non-existant path
// NOTE:if at some point the normalized name will need to outlive the containing file system object
// class, return smart pointer instead
const std::string& IFileSystemObject::getCanonicalizedName() const
{
    if(mCanonicalizedName == "")
        throw std::runtime_error("mCanonicalizedname is empty. call canonicalizedName() first");
    return mCanonicalizedName;
}

const std::string &IFileSystemObject::getName() const
{
    return mName;
}
