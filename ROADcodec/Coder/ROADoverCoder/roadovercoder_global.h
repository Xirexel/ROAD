#ifndef ROADOVERCODER_GLOBAL_H
#define ROADOVERCODER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ROADOVERCODER_LIBRARY)
#  define ROADOVERCODERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ROADOVERCODERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ROADOVERCODER_GLOBAL_H
