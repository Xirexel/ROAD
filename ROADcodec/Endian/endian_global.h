#ifndef ENDIAN_GLOBAL_H
#define ENDIAN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ENDIAN_LIBRARY)
#  define ENDIANSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ENDIANSHARED_EXPORT Q_DECL_IMPORT
#endif

#define UNUSED(x) (void)x;

#endif // ENDIAN_GLOBAL_H
