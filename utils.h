#ifndef UTILS_H
#define UTILS_H
#include "definesandenums.h"
#include <QtGlobal>


unsigned int makeUnsignedIntFromBytes(char b1, char b2, char b3, char b4);

unsigned short makeUnsignedShortFromBytes(char b1, char b2);

bool assertAndRet(const bool b);

#define CHECK_PTR(p) do { if (!(p)) Q_ASSERT(false); } while (false)

template <typename T>
T* check_ptr(T *p) { CHECK_PTR(p); return p; }

#endif // UTILS_H
