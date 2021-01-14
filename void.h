#pragma once //void.h include all headers
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>
#include <unistd.h>

#ifdef __SIZEOF_INT128__
typedef  unsigned __int128 uint128_t;
typedef  __int128 int128_t;
typedef  int128_t i128;
typedef  uint128_t u128;
#endif
typedef  uint8_t u8 ;
typedef uint16_t  u16 ;
typedef  uint32_t u32;
typedef  uint64_t u64;
typedef  int8_t i8 ;
typedef int16_t  i16 ;
typedef  int32_t i32;
typedef  int64_t i64;
typedef float f32;
typedef double f64;
typedef long double f80;


#include "array.h"
#include "argcount.h"
#include "argmanip.h"
#include "arguments.h"
#include "blankapply.h"
#include "boolean-tokens.h"
#include "chainapply.h"
#include "cor.h"
#include "dapply.h"
#include "fileio.h"
#include "enumclass.h"
#include "lookup.h"
#include "lambda.h"
#include "mathmacros.h"
#include "print.h"
#include "random.h"
#include "remtype.h"
#include "recapply.h"
#include "size.h"
#include "tapply.h"
#include "timing.h"
