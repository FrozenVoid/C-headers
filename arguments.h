#pragma once
/* arguments.h macros
argcount(...) count arguments min=0 max=1024
isarg(...) quick check if there an argument(first argument exists)
first(...) return first argument
rest(...) return arguments after first argument.(a,args..)--> args
id(...) return argument unmodified
swapargs(a,args...) return args,a(first argument last)
isdefined(a) is the 'a' symbol defined (#if defined)
istype(x,type) is x's type=type(1) or not (0)
stringify(args...) turn arguments into a string(1,2,3)->"1,2,3"
merge(a,b) merges two tokens(a,b)-> ab
tuple(args...) add parens(convert arglist to tuple) 1,2,3 -> (1,2,3)
detuple(args)  remove parens(convert tuple to arglist) (1,2,3)-> 1,2,3
setapply(func,args) -> func(args) 
remcomma(a,b) remove comma (a,b) -> a b
onearg(args...) is there exactly one argument(non-empty)
mergetuples(a,b) ((1,2,3),(4,5,6)) -> (1,2,3,4,5,6)
toexpr(args...) execute arguments as statement expression(GCC extensions)
toarray(name,args...) create array_name={args}
*/

#include "argcount.h"
    #define argcount_q1(_0,_1,_2,N,...) N
    #define argcount_qc(args...) argcount_q1(args) 
    //  args push>>> n. 3,2,1 :: :args:<numbers> 
    #define argcountq(...) argcount_qc(0,##__VA_ARGS__,2,1,0)
#define merge1(a,b) a##b
#define merge(a,b) merge1(a,b)
#define id(args...) args
#define swapargs(a,args...) args,a
#define tuple(args...) (args)
#define detuple(arg) id arg
#define rest(a,args...) args
#define first(a,args...) a
#define second(args...) first(rest(args))
#define isarg1(args...) argcountq(args) 
#define isarg(args...) isarg1(first(args))
#define isdefined(arg) defined(arg) //gcc extension. from #if defined(x)
#define stringify1(args...) #args
#define stringify(args...) stringify1(args) 
#define setapply(func,args...) func(args)
#define remcomma(a,b) a b
#define remcomma2(a,b...) a b
#define onearg00 0
#define onearg10 1 
#define onearg11 0
#define onearg01 0
#define onearg(args...) merge(onearg,merge(isarg(first(args)),isarg(first(rest(args)))))
#define mergetuples(a,b) (detuple(a),detuple(b))
#define toexpr(args...) ({args;})
#define toarray(name,args...) typeof(first(args)) name[]={args}
#define istype(x,type) (_Generic((x),type:1,default:0))
