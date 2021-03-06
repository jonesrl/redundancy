#ifndef FILESCANTARGET_H
#define FILESCANTARGET_H

#include <string>
#include <boost/shared_ptr.hpp>
#include "ifilescantarget.h"
#include "ifile.h"

#ifdef __GNUC__                                     // pragma exists for GCC
#pragma GCC diagnostic push                         // save the current diagnostic state
#pragma GCC diagnostic ignored "-Wpadded"           // ignore the Wpadded warning
#endif

class FileScanTarget : public IFileScanTarget
{
public:
    FileScanTarget(boost::shared_ptr<IFile> file, int64_t priority, bool recursive);
    ~FileScanTarget(){}
};

#ifdef __GNUC__                                     // make sure were using gcc
#pragma GCC diagnostic pop                          // restore the old diagnostic state
#endif
#endif // FILESCANTARGET_H
