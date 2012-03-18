#ifndef FILESCANTARGET_H
#define FILESCANTARGET_H
#include "ifilescantarget.h"
#include <string>

class FileScanTarget : public IFileScanTarget
{
public:
    FileScanTarget(const std::string& targetName);
    ~FileScanTarget(){}
    std::string getName() const;
private:
    //std::string mTargetName;
};

#endif // FILESCANTARGET_H
