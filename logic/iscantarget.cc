#include "iscantarget.h"
#include "ifilesystemobject.h"
#include <boost/filesystem.hpp>
#include <boost/shared_ptr.hpp>

IScanTarget::IScanTarget(boost::shared_ptr<IFileSystemObject> fileSystemObject)
    : mFileSystemObject(fileSystemObject)
{
}

// pure virtual destructors must be defined in the base class
// however, a pure virtual destructor in a class derived from a class
// with a pure virtual destructor does not need to define its pure virtual
// destructor, even if declared, as well as children of children of the abstract
// base class
IScanTarget::~IScanTarget()
{

}

//boost::filesystem::exists does not throw
bool IScanTarget::isReadable() const
{
    return mFileSystemObject->isReadable();

}

const std::string &IScanTarget::getName() const
{
    return mFileSystemObject->getName();
}
