#ifndef ISCANTARGET_H
#define ISCANTARGET_H

#include <boost/shared_ptr.hpp>
#include "ifilesystemobject.h"
#include <string>
class IScanTarget
{
public:
    IScanTarget(boost::shared_ptr<IFileSystemObject> fileSystemObject);
    virtual ~IScanTarget()=0;
    bool virtual isReadable() const;
    const std::string& getName() const;
protected:
    boost::shared_ptr<IFileSystemObject> mFileSystemObject;
};

#endif // ISCANTARGET_H
