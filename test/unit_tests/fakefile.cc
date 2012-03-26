#include "fakefile.h"

FakeFile::FakeFile(const std::string& name) : IFile(name), mIsReadable(false)
{
}

bool FakeFile::isReadable() const
{
    return mIsReadable;
}
