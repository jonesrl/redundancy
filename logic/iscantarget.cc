#include "iscantarget.h"
#include <string>
#include <boost/filesystem.hpp>

IScanTarget::IScanTarget(const std::string& targetPathName) : mTargetPathName(targetPathName)
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
bool IScanTarget::exists() const
{

    const boost::filesystem::path p(mTargetPathName);

    bool targetExists = boost::filesystem::exists(p);
    return targetExists;


}
