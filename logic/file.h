#ifndef FILE_H
#define FILE_H

#include <string>
#include "ifile.h"


class File : public IFile
{
public:
    File(const std::string& name);

};

#endif // FILE_H
