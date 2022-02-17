#pragma once
#include <x86intrin.h>//__rdtsc
#include <stdint.h>
#include <time.h> //clock_gettime
#include <stdio.h>
#include "argmanip.h"
/* walltime(args...) - (double precision) seconds of argument execution time
nanoseconds(args...) - uint64_t nanoseconds of argument execution time
microseconds(args...) - uint64_t microseconds of argument execution time
milliseconds(args...) - uint64_t milliseconds of argument execution time

timing(args...)uint64_t CPU clock cycles of argument execution time
 waitinput()  wait until user presses Enter(interactive)
*/

#define walltime(args...) ({ time_t start;time(&start);opapply(;,args);time_t end;time(&end);\
 difftime(end,start);})
#define nanoseconds(args...) ({struct timespec start, end;clock_gettime(CLOCK_MONOTONIC_RAW, &start);\
opapply(;,args);clock_gettime(CLOCK_MONOTONIC_RAW, &end);\
(end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);})

#define microseconds(args...) ({struct timespec start, end;clock_gettime(CLOCK_MONOTONIC_RAW, &start);\
opapply(;,args);clock_gettime(CLOCK_MONOTONIC_RAW, &end);\
(end.tv_sec - start.tv_sec) * 1000000 + ((end.tv_nsec - start.tv_nsec)/1000);})

#define milliseconds(args...) ({struct timespec start, end;clock_gettime(CLOCK_MONOTONIC_RAW, &start);\
opapply(;,args);clock_gettime(CLOCK_MONOTONIC_RAW, &end);\
(end.tv_sec - start.tv_sec) * 1000 + ((end.tv_nsec - start.tv_nsec)/1000000);})


#define seconds(args...) ({struct timespec start, end;clock_gettime(CLOCK_MONOTONIC_RAW, &start);\
opapply(;,args);clock_gettime(CLOCK_MONOTONIC_RAW, &end);\
(end.tv_sec - start.tv_sec) ;})

#define timing(args...) ({uint64_t start=__rdtsc();opapply(;,args);__rdtsc()-start;})
#define waitinput() ({char c;printf("\nPress Enter to continue:");scanf("%c",&c);c;})

//from program start
#define mstime() ((clock())/(CLOCKS_PER_SEC/1000))
