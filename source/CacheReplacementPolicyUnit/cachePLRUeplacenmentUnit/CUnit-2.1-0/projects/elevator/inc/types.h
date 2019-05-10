/* Primitive data types */
/* TODO: it is worth for THUMB?!? */
#ifndef TYPES_H
#define TYPES_H

typedef char bool;
typedef unsigned char EE_BIT;
typedef unsigned char EE_UINT8;
typedef unsigned int EE_UINT16;
typedef unsigned long EE_UINT32;
typedef signed char EE_INT8;
typedef signed int EE_INT16;
typedef signed long EE_INT32;

typedef EE_UINT16 EE_UREG;
typedef EE_INT16  EE_SREG;
typedef EE_UINT16 EE_FREG;

#endif // TYPES_H
