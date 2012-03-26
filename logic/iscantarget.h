#ifndef ISCANTARGET_H
#define ISCANTARGET_H

#include <string>
#include <boost/shared_ptr.hpp>
#include "ifilesystemobject.h"

#ifdef __GNUC__                                     // pragma exists for GCC
#pragma GCC diagnostic push                         // save the current diagnostic state
#pragma GCC diagnostic ignored "-Wpadded"           // ignore the Wpadded warning
#endif

class IScanTarget
{
public:
    IScanTarget(boost::shared_ptr<IFileSystemObject> fileSystemObject, int64_t priority, bool recursive);
    virtual ~IScanTarget()=0;
    bool virtual isReadable() const;
    const std::string getName() const;
protected:
    boost::shared_ptr<IFileSystemObject> mFileSystemObject;
    int64_t mPriority;
    bool mRecursive;
};

#ifdef __GNUC__                                     // make sure were using gcc
#pragma GCC diagnostic pop                          // restore the old diagnostic state
#endif

#endif // ISCANTARGET_H
