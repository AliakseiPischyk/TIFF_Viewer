#ifndef IFD_H
#define IFD_H

#include "ihasoffset.h"
//image file directory
class IFD:public IHasOffset
{
public:
    IFD(const unsigned int IFDOffset):IHasOffset(IFDOffset){};
};

#endif // IFD_H
