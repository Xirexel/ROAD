#ifndef ENCODINGOPTIONS_GLOBAL_H
#define ENCODINGOPTIONS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ENCODINGOPTIONS_LIBRARY)
#  define ENCODINGOPTIONSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ENCODINGOPTIONSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ENCODINGOPTIONS_GLOBAL_H
