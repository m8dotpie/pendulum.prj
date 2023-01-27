
#ifndef MY_LCMTYPES_EXPORT_H
#define MY_LCMTYPES_EXPORT_H

#ifdef MY_LCMTYPES_STATIC_DEFINE
#  define MY_LCMTYPES_EXPORT
#  define MY_LCMTYPES_NO_EXPORT
#else
#  ifndef MY_LCMTYPES_EXPORT
#    ifdef my_lcmtypes_EXPORTS
        /* We are building this library */
#      define MY_LCMTYPES_EXPORT 
#    else
        /* We are using this library */
#      define MY_LCMTYPES_EXPORT 
#    endif
#  endif

#  ifndef MY_LCMTYPES_NO_EXPORT
#    define MY_LCMTYPES_NO_EXPORT 
#  endif
#endif

#ifndef MY_LCMTYPES_DEPRECATED
#  define MY_LCMTYPES_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MY_LCMTYPES_DEPRECATED_EXPORT
#  define MY_LCMTYPES_DEPRECATED_EXPORT MY_LCMTYPES_EXPORT MY_LCMTYPES_DEPRECATED
#endif

#ifndef MY_LCMTYPES_DEPRECATED_NO_EXPORT
#  define MY_LCMTYPES_DEPRECATED_NO_EXPORT MY_LCMTYPES_NO_EXPORT MY_LCMTYPES_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MY_LCMTYPES_NO_DEPRECATED
#    define MY_LCMTYPES_NO_DEPRECATED
#  endif
#endif

#endif /* MY_LCMTYPES_EXPORT_H */
