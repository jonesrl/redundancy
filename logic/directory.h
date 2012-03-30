#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include "idirectory.h"

class Directory : public IDirectory
{
public:
    Directory(const std::string& name);
};

#endif // DIRECTORY_H
