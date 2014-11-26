#ifndef ROADCODER_GLOBAL_H
#define ROADCODER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ROADCODER_LIBRARY)
#  define ROADCODERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ROADCODERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ROADCODER_GLOBAL_H