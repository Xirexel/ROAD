#ifndef DRIVER_GLOBAL_H
#define DRIVER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DRIVER_LIBRARY)
#  define DRIVERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DRIVERSHARED_EXPORT Q_DECL_IMPORT
#endif

#define UNUSED(x) (void)x;

#endif // DRIVER_GLOBAL_H
