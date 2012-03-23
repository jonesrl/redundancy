#ifndef IFILESYSTEMOBJECT_H
#define IFILESYSTEMOBJECT_H

#include <string>
#include <boost/filesystem.hpp>

class IFileSystemObject
{
public:
    IFileSystemObject(const std::string& name);
    virtual ~IFileSystemObject()=0;
    bool isReadable() const;
    void canonicalizeName();
    // NOTE: if the filesystemobject goes out of scope, will the caller of this function
    // be left holding a dangling reference? i think so, but I don't know exactly how this
    // will be used in the end yet, so keep this in mind.
    // returning a const reference so that the private variable can't be modified by the caller
    const std::string& getCanonicalizedName() const;
    const std::string& getName() const;
private:
    std::string mName;
    std::string mCanonicalizedName;
    boost::filesystem::path mPath;

};

#endif // IFILESYSTEMOBJECT_H
