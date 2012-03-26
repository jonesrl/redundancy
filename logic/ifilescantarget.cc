#include <string>
#include "ifilescantarget.h"
#include "iscantarget.h"

IFileScanTarget::IFileScanTarget(boost::shared_ptr<IFile> file, int64_t priority, bool recursive)
    : IScanTarget(file, priority, recursive)
{

}


