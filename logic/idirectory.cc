#include <string>

#include "idirectory.h"
#include "ifilesystemobject.h"

IDirectory::IDirectory(const std::string &name) : IFileSystemObject(name)
{
}
