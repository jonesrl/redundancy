#ifndef IFILESCANTARGET_H
#define IFILESCANTARGET_H

#include "iscantarget.h"
#include <string>
class IFileScanTarget : public IScanTarget
{
public:
    IFileScanTarget(const std::string &targetName);

};

#endif // IFILESCANTARGET_H
