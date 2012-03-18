#include "filescantarget.h"
#include <string>

FileScanTarget::FileScanTarget(const std::string& targetName) : IFileScanTarget(targetName)
{

}

std::string FileScanTarget::getName() const
{
    return mTargetPathName;
}
