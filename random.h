#pragma once

#include <stdint.h>
/*


raw numbers::
randuint128() integer from 0 to UINT128_MAX(if available)
randuint64() integer from 0 to UINT64_MAX
randuint32() integer from 0 to UINT32_MAX
randuint16() integer from 0 to UINT16_MAX
randuint8() integer from 0 to UINT8_MAX

randfloat() random float in range 0.0-1.0

range(reccomended)::
varnd(var,start,end) macro sets var to value in range start<>end 
rnd(start,end)  macro expands to one of functions below

frange (start,end) float in specific range,if argument is floating point
rrange(start,end) integer in specific range(use randuint64()&n for powers of 2 which will be faster than modulus due opcode latency)


*/


/*xoroshiro random generator from http://prng.di.unimi.it/xoshiro256starstar.c */

#define rnd(start,end) _Generic((end),double:frange,float:frange,long double:frange,default:rrange)(start,end)
#define varnd(var,start,end) var=rnd(start,end)

uint64_t xrotl(uint64_t x,uint32_t k){//compiles to ROTL
return (x << k) | (x >> (64 - k));}


uint64_t randuint64(void) {
        static uint64_t s[4]={123456789,123456789,123456789,123456789};

	const uint64_t result = xrotl(s[1] * 5, 7) * 9;

	const uint64_t t = s[1] << 17;

	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;

	s[3] = xrotl(s[3], 45);
	return result;
}

typedef union rndintconv64{
uint64_t a64;
uint32_t a32;
uint16_t a16;
uint8_t a8;
} rndintconv64;
#ifdef __SIZEOF_INT128__ 
unsigned __int128 randuint128(void){union {unsigned __int128 a;
uint64_t b[2];} d;
d.b[0]=randuint64();
d.b[1]=randuint64();
;return d.a;} 
#endif 
uint32_t randuint32(void){rndintconv64 a;a.a64=randuint64(); return a.a32;}
uint16_t randuint16(void){rndintconv64 a;a.a64=randuint64(); return a.a16;}
uint8_t randuint8(void) {rndintconv64 a;a.a64=randuint64(); return a.a8;}
uint8_t rndbyte(void){// (rnd()>>((rnd()>>31)&31))&0xff
return (uint8_t)((randuint64()>>((randuint64()>>31)&31))&0xff);}

uint64_t rrange(uint64_t start,uint64_t end){
return (randuint64()%(end-start))+start;}

double uintdouble01(uint64_t x){//range 0.0-1.0
     const union { uint64_t i; double d; } u = { .i = UINT64_C(0x3FF) << 52 | x >> 12 };\
       return u.d - 1.0;}


double randfloat(void){ return uintdouble01(randuint64());}

double frange(double start, double end){
 return (uintdouble01(randuint64())*(end-start))+start; }

