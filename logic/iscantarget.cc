#include "iscantarget.h"
#include "ifilesystemobject.h"
#include <boost/filesystem.hpp>
#include <boost/shared_ptr.hpp>

// will throw a runtime_error if the fileSystemObject is not readable, or given a priority less than 1
// TODO: figure out a better way to enforce numeric limits. Investigate boost's numeric_cast template.

IScanTarget::IScanTarget(boost::shared_ptr<IFileSystemObject> fileSystemObject, int64_t priority, bool recursive)
    : mFileSystemObject(fileSystemObject), mPriority(priority), mRecursive(recursive)
{
    if (!fileSystemObject->isReadable())
        throw std::runtime_error("Scan targets must be readable. Call fileSystemObject->isReadable first");

    if(priority<1)
        throw std::runtime_error("Scan target priority must be greater than 0");
}

// pure virtual destructors must be defined in the base class
// however, a pure virtual destructor in a class derived from a class
// with a pure virtual destructor does not need to define its pure virtual
// destructor, even if declared, as well as children of children of the abstract
// base class
IScanTarget::~IScanTarget()
{

}

bool IScanTarget::isReadable() const
{
    return mFileSystemObject->isReadable();

}

#ifdef __GNUC__                                     // pragma exists for GCC
#pragma GCC diagnostic push                         // save the current diagnostic state
#pragma GCC diagnostic ignored "-Waggregate-return" // ignore the aggregate-return warning
#endif
const std::string IScanTarget::getName() const
{
    return mFileSystemObject->getName();
}
#ifdef __GNUC__                                     // make sure were using gcc
#pragma GCC diagnostic pop                          // restore the old diagnostic state
#endif
