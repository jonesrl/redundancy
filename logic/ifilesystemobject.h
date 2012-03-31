#ifndef IFILESYSTEMOBJECT_H
#define IFILESYSTEMOBJECT_H

#include <string>
#include <boost/filesystem.hpp>

class IFileSystemObject
{
public:
    IFileSystemObject(const std::string& name);
    virtual ~IFileSystemObject()=0;
    bool virtual isReadable() const;
    void virtual canonicalizeName();
    const std::string getCanonicalizedName() const;
    const std::string getName() const;
private:
    std::string mName;
    std::string mCanonicalizedName;
    boost::filesystem::path mPath;
};

#endif // IFILESYSTEMOBJECT_H
