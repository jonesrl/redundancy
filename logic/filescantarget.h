#ifndef FILESCANTARGET_H
#define FILESCANTARGET_H
#include "ifilescantarget.h"
#include "ifile.h"
#include <string>
#include <boost/shared_ptr.hpp>

class FileScanTarget : public IFileScanTarget
{
public:
    FileScanTarget(boost::shared_ptr<IFile> file);
    ~FileScanTarget(){}
};

#endif // FILESCANTARGET_H
