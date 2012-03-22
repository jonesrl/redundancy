#include "ifilesystemobject.h"
#include <boost/filesystem.hpp>
#include <string>
#include <stdexcept>

// references can't be null, so there is no need to check
// throws if the filename is empty, or if the file or directory does not exist
IFileSystemObject::IFileSystemObject(const std::string& name)
    : mName(name), mNormalizedName(""), mPath(name)
{
    if(name == "")
        throw std::runtime_error("FileSystemObject: name should not be empty");

}

// for base classes, this has to be defined even though it's pure virtual
// derived classes do not need to define it, unless overriding
IFileSystemObject::~IFileSystemObject()
{

}

bool IFileSystemObject::exists() const
{
    return boost::filesystem::exists(mPath);
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
// TODO: convert error_code into an exception that displays a nice message
// TODO: figure out how to handle unicode. The boost::filesystem::path class provides conversions
// using the ICU library, so I think this would be the appropriate place to do it
// NOTE: for canonical(p), p must exist, and must be readable

void IFileSystemObject::normalizeName()
{
    boost::filesystem::path p(mName);
    boost::system::error_code ec;
    mNormalizedName = canonical(p, ec).generic_string();

}

// TODO: throw a runtime exception if this is called before normalizeName is called
// returning a const reference to prevent clients from modifying private data
// NOTE:if at some point the normalized name will need to outlive the containing file system object
// class, return smart pointer instead
const std::string& IFileSystemObject::getNormalizedName() const
{
    return mNormalizedName;
}
