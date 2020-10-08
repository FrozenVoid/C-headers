#pragma once
#include "dapply.h"
#include "tapply.h"
#include "chainapply.h"
/* argmanip.h
reverse(args) reverse argument order(1,2,3)-> 3,2,1
applyall(func,args) apply func to each argument-> func(arg1),func(arg2),...
mergeall(args) merge all argument tokens
toatom(args...) remove all commas from arglist
opapply(op,args...) -> arg1 op arg2 op arg3 ...
genargs(n,arg) repeat arg N times
tolists(args...) converts arglist to list of tuples (1,2,3)->((1),(2),(3))
appendall(tup,args...) ((a,b,c),1,2,3) ->((a,b,c,1),(a,b,c,2),(a,b,c,3))
prefixall(tup,args...) ((a,b,c),1,2,3) ->((1,a,b,c),(2,a,b,c),(3,a,b,c))
*/
#define reverse(args...) dapply(swapargs,id,args)
#define applyall(func,args...) chainapply(func,args)
#define mergeall(args...) dapply(merge,id,args)
#define toatom(args...) dapply(remcomma,id,args)
#define genargs(n,arg) merge(chainapply,n)(arg id,) 
#define tolists(args...) chainapply(tuple,args)


#define appendall1(tup,arg) mergetuples(tup,(arg))
#define prefixall1(tup,arg) mergetuples((arg),tup)

#define appendall(tup,args...) tapply(tup,appendall1,args)
#define prefixall(tup,args...) tapply(tup,prefixall1,args)



#define opapply(op,arg1,args...) arg1 dapply(remcomma,op id,args)
//examples
#define addall(args...) opapply(+,args)
#define suball(args...) opapply(-,args)
#define multall(args...) opapply(*,args)
#define divall(args...) opapply(/,args)

