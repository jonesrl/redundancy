#ifndef IFILE_H
#define IFILE_H

#include <string>
#include "ifilesystemobject.h"

class IFile : public IFileSystemObject
{
public:
    IFile(const std::string& name);
};

#endif // IFILE_H
