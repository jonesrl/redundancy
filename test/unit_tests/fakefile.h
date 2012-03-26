#ifndef FAKEFILE_H
#define FAKEFILE_H

#include <string>
#include "ifile.h"

#ifdef __GNUC__                                     // pragma exists for GCC
#pragma GCC diagnostic push                         // save the current diagnostic state
#pragma GCC diagnostic ignored "-Wpadded"           // ignore the Wpadded warning
#endif

class FakeFile : public IFile
{
public:
    FakeFile(const std::string &name);

    bool isReadable() const;
    bool mIsReadable;
};

#ifdef __GNUC__                                     // make sure were using gcc
#pragma GCC diagnostic pop                          // restore the old diagnostic state
#endif

#endif // FAKEFILE_H

