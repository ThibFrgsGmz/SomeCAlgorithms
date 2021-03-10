/*---------------------------------------------------------------------------------------------------------------------*/
/* Exportable header file establishing the
    - System version,
      - compiler/computer system,
      - software common types.
      - macros for Windows/Linux portability
 */
/*---------------------------------------------------------------------------------------------------------------------*/
#ifndef __SOFTWARE_PRELUDE_H_INCLUDED__
#    define __SOFTWARE_PRELUDE_H_INCLUDED__

/***
 *     ____  _  _  ____  ____  ____  _  _    _  _  ____  ____  ____  __  __   __ _
 *    / ___)( \/ )/ ___)(_  _)(  __)( \/ )  / )( \(  __)(  _ \/ ___)(  )/  \ (  ( \
 *    \___ \ )  / \___ \  )(   ) _) / \/ \  \ \/ / ) _)  )   /\___ \ )((  O )/    /
 *    (____/(__/  (____/ (__) (____)\_)(_/   \__/ (____)(__\_)(____/(__)\__/ \_)__)
 */

/*! \brief Version macros for compile-time API version detection */
/*! \def     Major Version of the System.
 *             To be incremented when we make an incompatible API change. */
#    define     SYSTEME_MAJOR_VERSION            0

/*! \def     Minor Version of the System.
 *             To be incremented when we make add a functionality in a backward compatible manner API change.*/
#    define    SYSTEME_MINOR_VERSION            0

/*! \def     Patch Version of the System.
 *             To be incremented when we make a compatible backward bugs fixes */
#    define     SYSTEME_PATCH_VERSION            0


/***
 *      ___  __   _  _  ____  __  __    ____  ____     __     ___  __   _  _  ____  _  _  ____  ____  ____    ____  _  _  ____  ____  ____  _  _
 *     / __)/  \ ( \/ )(  _ \(  )(  )  (  __)(  _ \   /  \   / __)/  \ ( \/ )(  _ \/ )( \(_  _)(  __)(  _ \  / ___)( \/ )/ ___)(_  _)(  __)( \/ )
 *    ( (__(  O )/ \/ \ ) __/ )( / (_/\ ) _)  )   /  (_/ /  ( (__(  O )/ \/ \ ) __/) \/ (  )(   ) _)  )   /  \___ \ )  / \___ \  )(   ) _) / \/ \
 *     \___)\__/ \_)(_/(__)  (__)\____/(____)(__\_)   (__)   \___)\__/ \_)(_/(__)  \____/ (__) (____)(__\_)  (____/(__/  (____/ (__) (____)\_)(_/
 */

/*! \brief Establish the compiler and computer system.
 * Define zero or more of these symbols, for use in any non-portable code
 * (for pre-defined values see e.g. build-system headers as output of GNU C preprocessor)
 *
 * __WINDOWS__            Microsoft C/C++ with Windows calls
 * __UNIX__                System is Unix
 *
 * __IS_32BIT__            OS/compiler is 32 bits
 * __IS_64BIT__            OS/compiler is 64 bits
 *
 * */

#    if (defined (_WIN32) || defined (_WIN64))
#    undef  __WINDOWS__
#    define __WINDOWS__
    /* Stop check warnings about "deprecated" functions like fopen */
#        if _MSC_VER >= 1500
#            undef     _CRT_SECURE_NO_DEPRECATE
#            define     _CRT_SECURE_NO_DEPRECATE
#            pragma warning(disable: 4996)
#        endif
    /* Software is build for 64-bit targets */
#        if (defined (_WIN64) || defined (x64))
#            define __IS_64BIT__
    /* Else assume for 32-bit targets */
#        else
#            define __IS_32BIT__
#        endif
#    endif

#    if __GNUC__
    /* Software is build for 64-bit targets */
#        if (defined __LP64__)
#            define __IS_64BIT__
    /* Else assume for 32-bit targets */
#        else
#            define __IS_32BIT__
#        endif
#    endif

/*! \def Macro to detect if the source code is compiled by GNU GCC. */
/* To use :
 * #if GCC_COMPILER
 *         ...
 * #endif
 * __GNUC__ is defined by all GNU compilers that use the C preprocessor : C/C++/Objective-C/Fortran
 * __GNUG__ is defined by GNU C++ compiler, equivalent to test (__GNUC__ && __cplusplus)
 * __clang__ is defined by clang compiler, an alternative to GCC compilers to C/C++/Objective-C */
#    define GCC_COMPILER (((defined (__GNUC__)) || defined (__GNUG__)) && !defined(__clang__))

/*! \def Macro to use pragma inside macros. */
#    define PRAGMA(X)    _Pragma(#X)

#    ifdef GCC_COMPILER
#        define PRAGMA_GCC_PUSH_IGNORE_W(warning)        PRAGMA(GCC diagnostic push) \
                                                        PRAGMA(GCC diagnostic ignored warning)
#        define PRAGMA_GCC_POP_IGNORE_W()                PRAGMA( GCC diagnostic pop)
#       define ATTRIBUTE_NO_RETURN                      /*__attribute__ ((__noreturn__))*/ /* We could use _Noreturn but the error parser does not know this symbol */
#    else
#        define PRAGMA_GCC_PUSH_IGNORE_W(warning)
#        define PRAGMA_GCC_POP_IGNORE_W(warning)
#       define ATTRIBUTE_NO_RETURN                      _Noreturn /* C11 compliant */
#    endif

#    ifndef SODERN_REDEFINITION_TYPES
#        define SODERN_REDEFINITION_TYPES


/***
 *     ____   __  ____  ____  _  _   __   ____  ____     ___  __   _  _  _  _   __   __ _    ____  _  _  ____  ____  ____
 *    / ___) /  \(  __)(_  _)/ )( \ / _\ (  _ \(  __)   / __)/  \ ( \/ )( \/ ) /  \ (  ( \  (_  _)( \/ )(  _ \(  __)/ ___)
 *    \___ \(  O )) _)   )(  \ /\ //    \ )   / ) _)   ( (__(  O )/ \/ \/ \/ \(  O )/    /    )(   )  /  ) __/ ) _) \___ \
 *    (____/ \__/(__)   (__) (_/\_)\_/\_/(__\_)(____)   \___)\__/ \_)(_/\_)(_/ \__/ \_)__)   (__) (__/  (__)  (____)(____/
 */

/*
 * In order to develop software that is as maintainable and portable as possible over the years,
 * we will decide to use the variable types defined in the "stdint.h" file.
 * This file is part of the GNU C library and has been introduced in the standard ISO C99.
 * It allows programmers to write more portable code by providing a set of “typedef” that specify
 * exact width integer types, as well as the minimum and maximum allowed values defined for each type, using macros.
 * This header is particularly useful for embedded programming which often involves considerable
 * manipulation of hardware specific I/O registers, requiring integer data of fixed widths, specific locations and exact alignments.
 *
 * In order to keep some homogeneity with the redefinition of historical variable types in SODERN
 * (i.e. TypXYZ), we will redefine the types of "stdint.h" in order to get as close as possible to them.
 *
 */
#        include <stdint.h>    /* Standard ISO C99: 7.18 Integer types */

        /* The redefinition of types allows abstraction from material definitions.
         * Only the types defined below should be used.
         */

        /*! \brief Redefinition of the plain char type.
        * According to MISRA C:2004, 6.1, the plain char is used to contain an ASCII character or
        * a pointer to char is used to point to a string.
        * It is preferable to use simple characters for character data to ensure compatibility
        * with standard string management functions, and also to avoid compilation warnings when a cast is required.
        */
        typedef char                PChar_t;

        /*! \brief Redefinition of the signed char type.
        * Some compilers make all char variables unqualified unsigned, while others make them signed.
        * For this reasons, the source code explicitly qualifies each use of char with "signed' or "unsigned".
        * Unless the plain char is used to contain an ASCII character or a pointer to char is used to point to a string.
        * According to MISRA C:2004, 6.2: signed character is used when we need a signed integer of the character size for arithmetic.
        */
        typedef int8_t              SInt08_t;
        typedef unsigned char       Bool_t;       /*! \brief Redefinition of Boolean (TRUE or FALSE).           */
        typedef Bool_t              Flag_t;       /*! \brief Redefinition of Boolean (TRUE or FALSE).           */
        typedef uint8_t             UInt08_t;     /*! \brief Redefinition of the unsigned char type.            */
        typedef int16_t             SInt16_t;     /*! \brief Redefinition of Signed 16 bits integer.            */
        typedef uint16_t            UInt16_t;     /*! \brief Redefinition of Unsigned 16 bits integer.          */
        typedef int32_t             SInt32_t;     /*! \brief Redefinition of Signed 32 bits integer.            */
        typedef uint32_t            UInt32_t;     /*! \brief Redefinition of Unsigned 32 bits integer.          */
        typedef int64_t             SInt64_t;     /*! \brief Redefinition of Signed 64 bits integer.            */
        typedef uint64_t            UInt64_t;     /*! \brief Redefinition of Unsigned 64 bits integer.          */
        typedef float               Real32_t;     /*! \brief Redefinition of Signed 32 bits floating point.     */
        typedef double              Real64_t;     /*! \brief Redefinition of Signed 64 bits floating point.     */
        typedef void                VOID_t;       /*! \brief Redefinition of the Void type.                     */

/*! \brief Redefinition of the boolean constant FALSE. */
#        if (!defined FALSE) || (FALSE != (0))
#            undef     FALSE
#            define     FALSE    (0)
#        endif

/*! \brief Redefinition of the boolean constant TRUE. */
#        if (!defined TRUE) || (TRUE != (1))
#            undef     TRUE
#            define     TRUE    (1)
#        endif

/*! \brief Definition of NULL. */
#        ifndef __cplusplus
#           ifndef NULL
#                define NULL ((VOID_t *)0)
#           endif
#        else   /* C++ */
#           ifndef NULL
#                define NULL 0
#           endif
#        endif  /* __cplusplus */

#    endif /* !SODERN_REDEFINITION_TYPES */

/*! \brief Check compiler data types size */
#   include <limits.h>
#   if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#       error "Cannot compile : must change definition of uchar/char."
#   endif

#   if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#       error "Cannot compile : must change definition of ushort/short."
#   endif

#   if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#       error "Cannot compile : must change definition of uint/int."
#   endif

#if 0
/* TODO / Careful : long and long long are the same on 64 bits architecture */
#   if ( ULONG_MAX != (0xFFFFFFFFFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFFFFFFFFFF) )
#       error "Cannot compile : must change definition of ulong/long."
#   endif
#   if ( ULLONG_MAX != (0xFFFFFFFFFFFFFFFFU) ) || ( LLONG_MAX != (0x7FFFFFFFFFFFFFFF) )
#       error "Cannot compile : must change definition of ullong/llong."
#   endif
#endif
/***
 *     ____   __  ____  ____  __   ____  __  __    __  ____  _  _    _  _   __    ___  ____   __   ____
 *    (  _ \ /  \(  _ \(_  _)/ _\ (  _ \(  )(  )  (  )(_  _)( \/ )  ( \/ ) / _\  / __)(  _ \ /  \ / ___)
 *     ) __/(  O ))   /  )( /    \ ) _ ( )( / (_/\ )(   )(   )  /   / \/ \/    \( (__  )   /(  O )\___ \
 *    (__)   \__/(__\_) (__)\_/\_/(____/(__)\____/(__) (__) (__/    \_)(_/\_/\_/ \___)(__\_) \__/ (____/
 */
#    ifdef __linux__
#       include <stdio.h>                                               /* Needed for snprintf primitive */
#       include <string.h>                                              /* Needed for strncat & strncpy primitive */
#        define SPRINTF    snprintf                                        /*! \def Macro for SPRINTF portability on Linux */
#        define STRCAT(dst,size,src)    (strncat((dst),(src),(size)))        /*! \def Macro for STRCAT portability on Linux */
#        define STRCPY(dst,size,src)    (strncpy((dst),(src),(size)))        /*! \def Macro for STRCPY portability on Linux */
#    else
#        if defined _WIN32 || defined _WIN64
#           include <stdio.h>                                           /* Needed for sprintf_s primitive */
#           include <string.h>                                          /* Needed for strcat_s & strcpy_s primitive */
#            define SPRINTF    sprintf_s                                    /*! \def Macro for SPRINTF portability on Windows */
#            define STRCAT(dst,size,src)    (strcat_s((dst),(size),(src)))    /*! \def Macro for SPRSTRCATINTF portability on Windows */
#            define STRCPY(dst,size,src)    (strcpy_s((dst),(size),(src)))    /*! \def Macro for STRCPY portability on Windows */
#        endif
#    endif

/*! \def Macro to know the number of element in an array */
#   define  NB_ELEMENTS(_x) (sizeof(_x) / sizeof((_x)[0]))

#endif  /* !__SOFTWARE_PRELUDE_H_INCLUDED__ */

/* File trailer
 *
 * [EOF]
 *
 */
