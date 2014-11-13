#ifndef ENDIAN_GLOBAL_H
#define ENDIAN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ENDIAN_LIBRARY)
#  define ENDIANSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ENDIANSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ENDIAN_GLOBAL_H
