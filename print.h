#pragma once
#include <stdint.h>
#include <inttypes.h>
#include <float.h>
#include <stdio.h>
#include <string.h>
#include "argmanip.h"
/* print.h print/scan macros
print(args) print all arguments(space separated)
hexprint(args) prints all arguments in hex(except strings)
dbgprint(args) prints all arguments to stderr
dbghexprint(args) prints all arguments to stderr in hex(if possible)

dprint(delim,args) prints all arguments separated by delim string
hexdprint(delim,args) hex prints all arguments separated by delim string

fprint(FILE*,args) write all arguments(space separated) to file
hexfprint(FILE*,args) hex-write all arguments(space separated) to file

fdprint(delim,file,args)  writes all arguments with custom delim
hexfdprint(delim,file,args) writes all arguments in hex(except strings) with custom delim
------
scan(args...) read arguments from standard input
hexscan(args...) read hex arguments from standard input

fscan(FILE*,args...) read arguments from file
hexfscan(FILE*,args...) read hex arguments from file
example:
long double g;
fscan(stdin,g);//&g is automatic
print("\nscanned:",g);
---
support for printing _DecimalN/__floatN formats
 decprf(file,delim,args...) args = _Decimal numbers
 decprd(delim,args...) 
 decpr(args...) 
----
Support for printing larger integer types > uint64_t
arbprf(file,delim,args...) args= integers
 arbprd(delim,args...) 
 arbpr(args...) 

arbsprint(str,arby) print large integer arb to string(str)
*/
#define SPACE_DELIM " "
#define pformat(x) _Generic((x),\
 char:   "%c",\
 char*:  "%s",\
long long unsigned int: "%llu" ,\
long long int: "%lli" ,\
uint64_t: "%" PRIu64,\
 int64_t: "%" PRIi64,\
uint32_t: "%" PRIu32,\
 int32_t: "%" PRIi32,\
uint16_t: "%" PRIu16,\
 int16_t: "%" PRIi16,\
uint8_t:  "%" PRIu8,\
 int8_t:  "%" PRIi8,\
 float:  "%." stringify(FLT_DIG) "G",\
double:  "%." stringify(DBL_DIG) "G",\
 long double: "%." stringify(LDBL_DIG) "LG",\
default:"%p" )

#define hexformat(x) _Generic((x),\
 char:   "%c",\
 char*:  "%s",\
long long unsigned int: "%llx" ,\
long long int: "%llx" ,\
uint64_t: "%" PRIx64,\
 int64_t: "%" PRIx64,\
uint32_t: "%" PRIx32,\
 int32_t: "%" PRIx32,\
uint16_t: "%" PRIx16,\
 int16_t: "%" PRIx16,\
uint8_t:  "%" PRIx8,\
 int8_t:  "%" PRIx8,\
  float:  "%." stringify(FLT_DIG)"A",\
double:  "%." stringify(DBL_DIG) "A",\
 long double: "%." stringify(LDBL_DIG)"LA",\
default:"%p" )

#define scanformat(x) _Generic((x),\
 char:   "%c",\
 char*:  "%s",\
long long unsigned int: "%llu" ,\
long long int: "%lli" ,\
uint64_t: "%" SCNu64,\
 int64_t: "%" SCNi64,\
uint32_t: "%" SCNu32,\
 int32_t: "%" SCNi32,\
uint16_t: "%" SCNu16,\
 int16_t: "%" SCNi16,\
uint8_t:  "%" SCNu8,\
 int8_t:  "%" SCNi8,\
 float:  "%G",\
double:  "%G",\
 long double: "%LG" ,\
default:"%p")

#define hexscanformat(x) _Generic((x),\
 char:   "%c",\
 char*:  "%s",\
long long unsigned int: "%llx" ,\
long long int: "%llx" ,\
uint64_t: "%" SCNx64,\
 int64_t: "%" SCNx64,\
uint32_t: "%" SCNx32,\
 int32_t: "%" SCNx32,\
uint16_t: "%" SCNx16,\
 int16_t: "%" SCNx16,\
uint8_t:  "%" SCNx8,\
 int8_t:  "%" SCNx8,\
 float:  "%A",\
double:  "%A",\
 long double: "%LA" ,\
default: "%p")

//arbsprint print larger integer to string;
#define arbsprint(str,arby)  ({typeof(arby) x=arby,ten=(typeof(arby))10;\
char sign=' ';int index=strlen(str)-1;\
if(x<0){x=-x;sign='-';};\
do{str[index--]=(x % ten) + '0'; x /= ten;}while(x > 0);\
str[index]=sign;\
;})

//large integer formats supported by GCC
#define arbprf1(file,delim,arby)  ({typeof(arby) x=arby,ten=(typeof(arby))10;\
char sign=' ';int index=126;\
 char output[128];output[127]=0;\
if(x<0){x=-x;sign='-';};\
do{output[index--]=(x % ten) + '0'; x /= ten;}while(x > 0);\
output[index]=sign;\
fprintf(file,"%s%s",delim,&output[index]);\
;})

#define arbprd1(delim,arby) arbprf1(stdout,delim,arby)
#define arbpr1(arby) arbprf1(stdout,SPACE_DELIM,arby)

#define arbprf(file,delim,args...) chainapply(arbprf1,args)
#define arbprd(delim,args...) chainapply(arbprd1,args)
#define arbpr(args...) chainapply(arbpr1,args)





//print _DecimalN and __floatX format support : decy=number
#define decprf1(file,delim,decy) ({typeof(decy) x=decy; int n=0;\
char sign=' ';\
if(x<0){x=-x;sign='-';}\
while(x>=10){x/=10;n++;};\
while(x<1){x*=10;n--;};\
long double d=(long double)x;\
fprintf(file,"%s%c%."stringify(LDBL_DIG) "LG",delim,sign,d);\
if(n!=0)fprintf(file,"e%d",n);\
;})
#define decprd1(delim,decy) decprf1(stdout,delim,decy)
#define decpr1(decy) decprf1(stdout,SPACE_DELIM,decy)

#define decprf(file,delim,args...) chainapply(decprf1,args)
#define decprd(delim,args...) chainapply(decprd1,args)
#define decpr(args...) chainapply(decpr1,args)


#define core_print1(delim,file,format_type,arg) \
fprintf(file,delim),fprintf(file,format_type(arg),arg)
#define print1(arg) printf(SPACE_DELIM),printf(pformat(arg),arg)
#define hexprint1(arg) printf(SPACE_DELIM),printf(hexformat(arg),arg)

#define scan1(arg) scanf(scanformat(arg),&arg)
#define hexscan1(arg) scanf(hexscanformat(arg),&arg)

#define fscan2(file,arg) fscanf(file,scanformat(arg),&arg)
#define fscan1(tup) fscan2 tup
 
#define hexfscan2(file,arg) fscanf(file,hexscanformat(arg),&arg)
#define hexfscan1(tup) hexfscan2 tup


#define fprint2(file,arg) core_print1(SPACE_DELIM,file,pformat,arg)
#define fprint1(tup) fprint2 tup
 
#define hexfprint2(file,arg) core_print1(SPACE_DELIM,file,hexformat,arg)
#define hexfprint1(tup) hexfprint2 tup

#define dprint2(delim,arg) printf(delim),printf(pformat(arg),arg)
#define dprint1(tup) dprint2 tup

#define hexdprint2(delim,arg) core_print1(delim,stdout,hexformat,arg)
#define hexdprint1(tup) hexdprint2 tup


#define dfprint2(delim,file,arg) core_print1(delim,file,pformat,arg)
#define dfprint1(tup) dfprint2 tup


#define hexfdprint2(delim,file,arg) core_print1(delim,file,hexformat,arg)
#define hexfdprint1(tup) hexfdprint2 tup


//---- applicative 
#define print(args...) chainapply(print1,args)
#define hexprint(args...) chainapply(hexprint1,args)


#define fprint(file,args...) chainapply(fprint1,appendall((file),args))
//#define fprint(file,args...) chainapply(fprint1,appendall((file),args))
#define hexfprint(file,args...) chainapply(hexfprint1,appendall((file),args))

#define dprint(delim,args...) chainapply(dprint1,appendall((delim),args))
#define hexdprint(delim,args...) chainapply(hexdprint1,appendall((delim),args))


#define dfprint(delim,file,args...) chainapply(dfprint1,appendall((delim,file),args))

#define hexfdprint(delim,file,args...) chainapply(hexfdprint1,appendall((delim,file),args))

#define scan(args...) chainapply(scan1,args)
#define hexscan(args...) chainapply(hexscan1,args)

#define fscan(file,args...) chainapply(fscan1,appendall((file),args))
#define hexfscan(file,args...) chainapply(hexfscan1,appendall((file),args))
#define dbgprint(args...) fprint(stderr,args)
#define dbghexprint(args...) hexfprint(stderr,args)


