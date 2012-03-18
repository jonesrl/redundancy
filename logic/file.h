#ifndef FILE_H
#define FILE_H

#include "ifilesystemobject.h"
#include <string>

class File : public IFileSystemObject
{
public:
    File(const std::string& name);

};

#endif // FILE_H
