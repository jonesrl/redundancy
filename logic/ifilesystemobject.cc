#include <string>
#include <stdexcept>
#include <fstream>
#include <boost/filesystem.hpp>
#include "ifilesystemobject.h"

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

//NOTE: will this work on directories and links? If not use the file_status() function
//      which is a wrapper around stat(). Windows has a stat() function too I believe
bool IFileSystemObject::isReadable() const
{
    std::ifstream ifile(mName.c_str());
    bool readable;
    if(ifile)
        readable = true;
    else
        readable = false;
    ifile.close();
    return readable;
}

// NOTE: make preferred will convert forward slashes to backslashes on windows, and does
// nothing on POSIX
// I think at this point the path should be stored in the generic format, and maybe get
// converted to a platform-native format at the display layer (see native vs. generic format
// in the boost::filesystem documentation
// TODO: figure out how to handle unicode. The boost::filesystem::path class provides conversions
// using the ICU library, so I think this would be the appropriate place to do it
// TODO: figure out an exception hierarchy
// see boost::system documentation for converting ec into a message suitable for an exception
// filesystem_error inherits from system_error which inherits from runtime_error ( i think )
// to get useful info out of an error, try something like this -
// File f(pathName);
// try {
//    f.canonicalizeName();
// } catch(boost::filesystem::filesystem_error e) {
//    std::cerr << "caught filesystem error\n"
//              << "path1: " << e.path1() << std::endl
//              << "path2: " << e.path2() << std::endl
//              << "what: " << e.what() << std::endl
//              << "error code: " << e.code() << std::endl
//              << "error code message: " << e.code().message() << std::endl;
// }

#ifdef __GNUC__                                     // pragma exists for GCC
#pragma GCC diagnostic push                         // save the current diagnostic state
#pragma GCC diagnostic ignored "-Waggregate-return" // ignore the aggregate-return warning
#endif

// dereference links, remove extra dots and slashes, and convert to an absolute path
// will throw boost::filesystem::filesystem_error if the item does not exist
// or if it is not readable
void IFileSystemObject::canonicalizeName()
{
    /* here's how to do it the non-throwing way
    boost::system::error_code ec;
    mCanonicalizedName = canonical(p, ec).generic_string();
    */

    mCanonicalizedName = boost::filesystem::canonical(mPath).generic_string();
}
#ifdef __GNUC__                                     // make sure were using gcc
#pragma GCC diagnostic pop                          // restore the old diagnostic state
#endif

// TODO: figure out under what conditions canonicalize() will return an empty string
//       are there more cases where canonicalize() will return an empty string than giving it a non-existant path
const std::string IFileSystemObject::getCanonicalizedName() const
{
    if(mCanonicalizedName == "")
        throw std::runtime_error("mCanonicalizedname is empty. call canonicalizedName() first");

    return mCanonicalizedName;
}

const std::string IFileSystemObject::getName() const
{
    return mName;
}
