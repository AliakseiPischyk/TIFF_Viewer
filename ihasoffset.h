#ifndef IHASOFFSET_H
#define IHASOFFSET_H


class IHasOffset
{
    unsigned int offset;
public:
    IHasOffset(const unsigned int offset):offset(offset){};
    unsigned int getOffset(){return offset;};
};

#endif // IHASOFFSET_H
