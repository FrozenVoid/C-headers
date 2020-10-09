#pragma once
#include <stdint.h>
#include <inttypes.h>
#include <float.h>
#include <stdio.h>
#include "argmanip.h"
/* print.h print/scan macros
print(args) print all arguments(space separated)
hexprint(args) prints all arguments in hex(except strings)

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
*/
#define SPACE_DELIM " "
#define pformat(x) _Generic((x),\
uint64_t: "%" PRIu64,\
 int64_t: "%" PRIi64,\
uint32_t: "%" PRIu32,\
 int32_t: "%" PRIi32,\
uint16_t: "%" PRIu16,\
 int16_t: "%" PRIi16,\
uint8_t:  "%" PRIu8,\
 int8_t:  "%" PRIi8,\
 char:   "%c",\
 char*:  "%s",\
 void*: "%p",\
 float:  "%." stringify(FLT_DIG) "G",\
double:  "%." stringify(DBL_DIG) "G",\
 long double: "%." stringify(LDBL_DIG) "LG" )

#define hexformat(x) _Generic((x),\
uint64_t: "%" PRIx64,\
 int64_t: "%" PRIx64,\
uint32_t: "%" PRIx32,\
 int32_t: "%" PRIx32,\
uint16_t: "%" PRIx16,\
 int16_t: "%" PRIx16,\
uint8_t:  "%" PRIx8,\
 int8_t:  "%" PRIx8,\
 char:   "%c",\
 char*:  "%s",\
 void*: "%p",\
 float:  "%." stringify(FLT_DIG)"A",\
double:  "%." stringify(DBL_DIG) "A",\
 long double: "%." stringify(LDBL_DIG)"LA" )

#define scanformat(x) _Generic((x),\
uint64_t: "%" PRIu64,\
 int64_t: "%" PRIi64,\
uint32_t: "%" PRIu32,\
 int32_t: "%" PRIi32,\
uint16_t: "%" PRIu16,\
 int16_t: "%" PRIi16,\
uint8_t:  "%" PRIu8,\
 int8_t:  "%" PRIi8,\
 char:   "%c",\
 char*:  "%s",\
 void*: "%p",\
 float:  "%G",\
double:  "%G",\
 long double: "%LG" )

#define hexscanformat(x) _Generic((x),\
uint64_t: "%" PRIx64,\
 int64_t: "%" PRIx64,\
uint32_t: "%" PRIx32,\
 int32_t: "%" PRIx32,\
uint16_t: "%" PRIx16,\
 int16_t: "%" PRIx16,\
uint8_t:  "%" PRIx8,\
 int8_t:  "%" PRIx8,\
 char:   "%c",\
 char*:  "%s",\
 void*: "%p",\
 float:  "%A",\
double:  "%A",\
 long double: "%LA" )


#define core_print1(delim,file,format_type,arg) \
fprintf(file,delim),fprintf(file,format_type(arg),arg)
#define print1(arg) core_print1(SPACE_DELIM,stdout,pformat,arg)
#define hexprint1(arg) core_print1(SPACE_DELIM,stdout,hexformat,arg)

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

#define dprint2(delim,arg) core_print1(delim,stdout,hexformat,arg)
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
