#pragma once

#include <stdint.h>
#include <x86intrin.h>
/*
rndseed(s) use specific seed
rnd() use default seed to generate random number
setrseed(a,b,c,d) set the generator seed vals[4]
raw numbers::


randuint128() integer from 0 to UINT128_MAX(if available)
randuint64() integer from 0 to UINT64_MAX
randuint32() integer from 0 to UINT32_MAX
randuint16() integer from 0 to UINT16_MAX
randuint8() integer from 0 to UINT8_MAX

randfloat() random float in range 0.0-1.0(from generator,
seed is static)
rdouble() random double in range 0.0-1.0 using __rdtsc() as seed.(for unpredictable first number)

range(reccomended)::

frange (start,end) float in specific range,if argument is floating point
rrange(start,end) integer in specific range(use randuint64()&n for powers of 2 which will be faster than modulus due opcode latency)

randomize(y) randomize an integer variable(no-seed func)




*/



//change to your preferred generator:
#define randuint64() randuint(randuint_seed)
#define rnd() randuint(randuint_seed)


#define rndseed(s) randuint(s)
#define ROTL(x,k) ({ typeof(x) res=(x); typeof(k) shift=(k);\
res=(res<<shift)|(res>>((sizeof(res)*8) -shift));res;})


   static uint64_t randuint_seed [4] __attribute__((unused)) ={123456789,123456789,123456789,123456789};

//state-free/constant-free randomization for an integer;
#define randomize(y) ({uint64_t x=(uint64_t)y;\
x+=~x>>11;x-=~x<<9;x+=~x<<7;\
x+=~x>>10;x-=~x<<8;x+=~x<<6;y=(typeof (y))x;})


//slower that xoshiro, but more random
#define randuint(s) ({  ;\
const uint64_t result = ROTL(s[1]+0xff04ff03ff02ff01ULL, 7)^(~s[2]);\
	const uint64_t t = ~(s[1]+0xf1f2f3f4f5f6f7f8ULL) ;\
	s[2] ^= s[0]-t;s[3] ^=~s[1]+s[2];\
	s[1] ^= ~s[2]+s[3];s[0] ^= ~s[3]-s[1];s[2] ^= ~t+s[0];\
s[3] = ROTL(~s[3], 45)+s[2];result;     })



#define setrseed(a,b,c,d) ({randuint_seed[0]=a;randuint_seed[1]=b;randuint_seed[2]=c;\
randuint_seed[3]=d;})




typedef union rndintconv64{
uint64_t a64;
uint32_t a32;
uint16_t a16;
uint8_t a8;
} rndintconv64;
#ifdef __SIZEOF_INT128__
#define randuint128() ({\
union {unsigned __int128 a;uint64_t b[2];} d;\
d.b[0]=randuint64();d.b[1]=randuint64();d.a;})

#endif

#define randuint32() ({rndintconv64 a;a.a64=randuint64();  a.a32;})
#define randuint16()  ({rndintconv64 a;a.a64=randuint64(); a.a16;})
#define randuint8() ({rndintconv64 a;a.a64=randuint64();  a.a8;})
#define rndbyte() ({   (uint8_t)((randuint64()>>((randuint64()>>31)&31))&0xff);  })

#define rrange(start,end) ({typeof(end) start1=start,end1=end;\
 ((randuint64()%(end1-start1))+start1);})

#define uintdouble01(x) ({     const union { uint64_t i; double d; } u = { .i = UINT64_C(0x3FF) << 52 | x >> 12 }; u.d-1.0;  })

#define randfloat() uintdouble01(randuint64())
#define rdouble() ({ uint64_t q1=__rdtsc(); double res=    uintdouble01(randomize(q1));res;})
#define frange(start,end) ({typeof(end) start1=start,end1=end;\
 ((uintdouble01(randuint64())*(end1-start1))+start1);})



