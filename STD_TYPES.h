#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Unsigned Data Types */
typedef unsigned char          u8;
typedef unsigned short int     u16;
typedef unsigned long int      u32;
typedef unsigned long long int u64;

/* Signed Data Types */
typedef signed char            s8;
typedef signed short int       s16;
typedef signed long int        s32;
typedef signed long long int   s64;

/* Floating Point Types */
typedef float                  f32;
typedef double                 f64;

/* Standard Definitions */
#define NULL                   ((void*)0)

#define OK                     0
#define NOK                    1

#define NULL_POINTER           2
#define BUSY_STATE             3
#define TIMEOUT_STATE          4

#endif /* STD_TYPES_H_ */