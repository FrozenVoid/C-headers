#pragma once
/*timing.h time in cycles*/
#include <x86intrin.h>
#include <stdint.h>
#include "argmanip.h"
#define timing(args...) ({uint64_t start=__rdtsc();opapply(;,args);__rdtsc()-start;})


