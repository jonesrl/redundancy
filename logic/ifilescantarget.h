#ifndef IFILESCANTARGET_H
#define IFILESCANTARGET_H

#include "iscantarget.h"
#include "ifile.h"
#include <boost/shared_ptr.hpp>

class IFileScanTarget : public IScanTarget
{
public:
    IFileScanTarget(boost::shared_ptr<IFile> file);

};

#endif // IFILESCANTARGET_H
