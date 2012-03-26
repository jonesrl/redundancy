#include <string>
#include <boost/shared_ptr.hpp>
#include "filescantarget.h"

#ifdef __GNUC__                                     // pragma exists for GCC
#pragma GCC diagnostic push                         // save the current diagnostic state
#pragma GCC diagnostic ignored "-Winline"           // ignore the Winline warning
#endif

FileScanTarget::FileScanTarget(boost::shared_ptr<IFile> file, int64_t priority, bool recursive)
    : IFileScanTarget(file, priority, recursive)
{
    if (mRecursive == true) {
        throw std::runtime_error("File scan targets may not be flagged as recursive");
    }

}

#ifdef __GNUC__                                     // make sure were using gcc
#pragma GCC diagnostic pop                          // restore the old diagnostic state
#endif
