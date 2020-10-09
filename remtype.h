#pragma once
/*remtype removbe type info
remtype(int a,int b) ->(a,b)
list of supported types below
*/
#include "argmanip.h"
#define remtype_int
#define remtype_double
#define remtype_float
#define remtype_char
#define remtype_long 
#define remtype_void
#define remtype_signed
#define remtype_unsigned
#define remtype_uint8_t
#define remtype_uint16_t
#define remtype_uint32_t
#define remtype_uint64_t
#define remtype_int8_t
#define remtype_int16_t
#define remtype_int32_t
#define remtype_int64_t
#define remtype1(atom) merge(remtype_,atom)
#define remtype(atoms...) chainapply(remtype1,atoms)
