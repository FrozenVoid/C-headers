#pragma once
#include "dapply.h"
#include "tapply.h"
#include "chainapply.h"
/* argmanip.h
reverse(args) reverse argument order(1,2,3)-> 3,2,1
applyall(func,args) apply func to each argument-> func(arg1),func(arg2),...
mergeall(args) merge all argument tokens
toatom(args...) remove all commas from arglist
last(args...) return last argument
opapply(op,args...) -> arg1 op arg2 op arg3 ...
genargs(n,arg) repeat arg N times
tolists(args...) converts arglist to list of tuples (1,2,3)->((1),(2),(3))
fromlist(args...) convert tuple list to arglist ((1,2),(3,4))->(1,2,3,4)
with(args...) apply args in local scope:
with(int a=1,func(a)) -> {int a=1; func(a);}
appendall(tup,args...) ((a,b,c),1,2,3) ->((a,b,c,1),(a,b,c,2),(a,b,c,3))
prefixall(tup,args...) ((a,b,c),1,2,3) ->((1,a,b,c),(2,a,b,c),(3,a,b,c))
rec2apply(func,args...) rec2apply(func,1,2,3,4)> func(1,func(2,func(3,4)));
rect2apply(func,tuples...) rect2apply(func,(1),(2),(3),(4))> func(1,func(2,func(3,4)));
rect2apply(function,(1,2),(2,3),(3,4),(4,5))  - > function(1,2,function(2,3,function(3,4,4,5)));
rec2applyt(func,(a,b,c),1,2,3,4,5)- > func (a,b,c)(1,func (a,b,c)(2,func (a,b,c)(3,func (a,b,c)(4,5))));
dupapply(func,times,(1,2,3)) apply func N times -> func((1,2,3)),...
set(name,val) sets variable to val;
dtset((name,val)) same as above with tuple format
setall((name,val),(name2,val2),...) set tuple vars to values.
*/
#define reverse(args...) dapply(swapargs,id,args)
#define applyall(func,args...) chainapply(func,args)
#define mergeall(args...) dapply(merge,id,args)
#define toatom(args...) dapply(remcomma,id,args)
#define rec2apply(func,args...) dapply(func,id,args)
#define rect2apply(func,tuples...) dapply(func,detuple,tuples)
#define rec2applyt(func,tup,args...) dapply(func tup,id,args)


#define firstarg(args...) first(args) //forwarding
#define last(args...) firstarg(reverse(args))
#define set(name,val) typeof(val) name = val
#define dtset(tup) typeof(second tup) first tup = second tup;
#define setall(tup_args...) toatom(applyall(dtset,tup_args))
#define genargs(n,arg) merge(chainapply,n)(arg id,) 

#define dupapply(func,n,args_tup) chainapply(func,genargs(n,args_tup))
#define tolists(args...) chainapply(tuple,args)
#define fromlists(args...) chainapply(detuple,args)
#define with(args...) {opapply(;,args);}


#define appendall1(tup,arg) mergetuples(tup,(arg))
#define prefixall1(tup,arg) mergetuples((arg),tup)

#define appendall(tup,args...) tapply(tup,appendall1,args)
#define prefixall(tup,args...) tapply(tup,prefixall1,args)



#define opapply(op,arg1,args...) arg1 dapply(remcomma,op id,args)
//examples
#define addall(args...) ({opapply(+,args);})
#define suball(args...) ({opapply(-,args);})
#define multall(args...) ({opapply(*,args);})
#define divall(args...) ({opapply(/,args);})


