#ifndef _KIWI_RESTRICT

#ifdef _MSC_VER
#define _KIWI_RESTRICT __restrict
#elif defined(__GNUC__) || defined(__clang__)
#define _KIWI_RESTRICT __restrict__
#else
#define _KIWI_RESTRICT
#endif // COMPILER CHOICE

#endif // _KIWI_RESTRICT