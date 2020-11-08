#pragma once
/* arguments.h macros
argcount(...) count arguments min=0 max=1024
isarg(...) quick check if there an argument(first argument exists)
first(...) return first argument
rest(...) return arguments after first argument.(a,args..)--> args
id(...) return arguments unmodified
rem(...) remove arguments(replace with blank)
swapargs(a,args...) return args,a(first argument last)
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
atype __auto_type (GCC extension)
ret alias to return
optnext(a,b...) if optnext(a)->a optnext(a,b)->b : return second argument if it exists,first if not
ternary(cond,a,b) return a if cond==true, b if not.
iftrue(x,y) return x if X is true,Y otherwise.
negate(args...) negate last expression (!x), (func(),2,3)=>(!3)
skiparg(x,args...) skip first argument if it doesn't exist(empty argument)
skipf(func,args...) apply func(args) if args exist
 insertbefore(arg,args...)  ->arg,args...
insertafter(arg,args...) ->args...,arg
istuple(a)   1 if argument is tuple(x,y,...) or 0 if not,(1)/((b)) 1-arg tuples treated as arguments.
argeval(tuplefunc,atomfunc,a)  if a is a tuple tuplefunc(detuple a) else atomfunc(a),if a isn't argument return nothing
evrec(args) evaluate deferred recursive functions(up to 10k iterations)
defereval(func_id)  allow this function to run recursively
example:
#define rapply_id() rapply_impl
#define rapply_impl00(func,a,args...)
#define rapply_impl10(func,a,args...) func(a)
#define rapply_impl01(func,a,args...) defereval(rapply_id)(func,args)
#define rapply_impl11(func,a,args...) func(a),defereval(rapply_id)(func,args)
#define rapply_impl(func,args...) merge(merge(rapply_impl,isarg(args)),isarg(second(args)))(func,args)
#define rapply(func,args...) evrec(rapply_impl(func,args))
rapply(func,1,2,3)-> func(1),func(2),func(3),..(max 10k args)


*/

#include "argcount.h"
    #define argcount_q1(_0,_1,_2,N,...) N
    #define argcount_qc(args...) argcount_q1(args) 
    //  args push>>> n. 3,2,1 :: :args:<numbers> 
    #define argcountq(...) argcount_qc(0,##__VA_ARGS__,2,1,0)
    #define atype __auto_type
    #define ret return
//deferred eval for recursive functions(note;this is impossible to debug)
#define ev00(args...) args
#define ev10(args...) ev00(ev00(ev00(ev00(ev00(ev00(ev00(ev00(ev00(ev00(args))))))))))
#define ev20(args...) ev10(ev10(ev10(ev10(ev10(ev10(ev10(ev10(ev10(ev10(args))))))))))
#define ev30(args...) ev20(ev20(ev20(ev20(ev20(ev20(ev20(ev20(ev20(ev20(args))))))))))
#define evrec(args...) ev30(ev30(ev30(ev30(ev30(ev30(ev30(ev30(ev30(ev30(args))))))))))
#define defereval(func_id) func_id rem()()

#define rapply_id() rapply_impl
#define rapply_impl00(func,a,args...)
#define rapply_impl10(func,a,args...) func(a)
#define rapply_impl01(func,a,args...) defereval(rapply_id)(func,args)
#define rapply_impl11(func,a,args...) func(a),defereval(rapply_id)(func,args)
#define rapply_impl(func,args...) merge(merge(rapply_impl,isarg(args)),isarg(second(args)))(func,args)
#define rapply(func,args...) evrec(rapply_impl(func,args))



#define insertbefore(arg,args...) arg,args
#define insertafter(arg,args...) args,arg

#define merge1(a,b) a##b
#define merge(a,b) merge1(a,b)
#define id(args...) args
#define negate(args...) (!(args))
#define rem(args...) 
#define swapargs(a,args...) args,a
#define tuple(args...) (args)
#define detuple(arg) id arg
#define rest(a,args...) args
#define first(a,args...) a
#define second(args...) first(rest(args))
#define isarg1(args...) argcountq(args) 
#define isarg(args...) isarg1(first(args))
#define istuple(a) isarg(second(id a))
#define skiparg0(x,args...) args
#define skiparg1(x,args...) x,args
#define skiparg(x,args...) merge(skiparg,isarg(x))(x,args)
#define skipf0(func,args...) 
#define skipf1(func,args...) func(args)
#define skipf(func,args...) merge(skipf,isarg(args))(func,args)


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
#define ternary(condition,trueexpr,falseexpr) ({(condition)?toexpr(trueexpr):toexpr(falseexpr);})
#define iftrue(x,y) ternary(x,x,y)
#define toarray(name,args...) typeof(first(args)) name[]={args}
#define istype(x,type) (_Generic((x),type:1,default:0))
#define optnext0(default,args...) default
#define optnext1(default,args...) args
#define optnext(default,optional...) merge(optnext,isarg(optional))(default,optional)


#define argeval0(tuplefunc,atomfunc,arg) skipf(atomfunc,arg)
#define argevalx(func,args...) func(args)
#define argevalx2(func,args...) argevalx(func,args)
#define argeval1(tuplefunc,atomfunc,arg)  argevalx2(tuplefunc,detuple(arg)) 
#define argeval(tuplefunc,atomfunc,arg) merge(argeval,istuple(arg))(tuplefunc,atomfunc,arg)



