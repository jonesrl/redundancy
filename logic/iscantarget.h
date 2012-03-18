#ifndef ISCANTARGET_H
#define ISCANTARGET_H

#include <string>
class IScanTarget
{
public:
    IScanTarget(const std::string& targetPathName);
    virtual ~IScanTarget()=0;
    bool virtual exists() const;
protected:
    std::string mTargetPathName;
};

#endif // ISCANTARGET_H
