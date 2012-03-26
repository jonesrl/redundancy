#ifndef IFILESCANTARGET_H
#define IFILESCANTARGET_H

#include <boost/shared_ptr.hpp>
#include "iscantarget.h"
#include "ifile.h"

#ifdef __GNUC__                                     // pragma exists for GCC
#pragma GCC diagnostic push                         // save the current diagnostic state
#pragma GCC diagnostic ignored "-Wpadded"           // ignore the Wpadded warning
#endif

class IFileScanTarget : public IScanTarget
{
public:
    IFileScanTarget(boost::shared_ptr<IFile> file, int64_t priority, bool recursive);

};

#ifdef __GNUC__                                     // make sure were using gcc
#pragma GCC diagnostic pop                          // restore the old diagnostic state
#endif

#endif // IFILESCANTARGET_H
