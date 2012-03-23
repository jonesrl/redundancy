#include "filescantarget.h"
#include <string>
#include <boost/shared_ptr.hpp>

FileScanTarget::FileScanTarget(boost::shared_ptr<IFile> file) : IFileScanTarget(file)
{

}
