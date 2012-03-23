#ifndef FILE_H
#define FILE_H

#include "ifile.h"
#include <string>

class File : public IFile
{
public:
    File(const std::string& name);

};

#endif // FILE_H
