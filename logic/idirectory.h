#ifndef IDIRECTORY_H
#define IDIRECTORY_H

#include <string>
#include "ifilesystemobject.h"

class IDirectory : public IFileSystemObject
{
public:
    IDirectory(const std::string& name);
    bool virtual isExecutable() const=0;
};

#endif // IDIRECTORY_H
