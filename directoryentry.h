#ifndef DIRECTORYENTRY_H
#define DIRECTORYENTRY_H

#include "ihasoffset.h"

class DirectoryEntry:public IHasOffset
{
public:
    DirectoryEntry(const unsigned int offset):IHasOffset(offset){};
};

#endif // DIRECTORYENTRY_H
