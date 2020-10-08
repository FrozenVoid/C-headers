#pragma once
#include "dapply.h"
/* argmanip.h
reverse(args) reverse argument order(1,2,3)-> 3,2,1
applyall(func,args) apply func to each argument-> func(arg1),func(arg2),...
mergeall(args) merge all argument tokens
toatom(args...) remove all commas from arglist
opapply(op,args...) -> arg1 op arg2 op arg3 ...
*/
#define reverse(args...) dapply(swap,id,args)
#define applyall(func,args...) dapply(id,func,args)
#define mergeall(args...) dapply(merge,id,args)
#define toatom(args...) dapply(remcomma,id,args)



#define opapply(op,arg1,args...) arg1 dapply(remcomma,op id,args)
//examples
#define addall(args...) opapply(+,args)
#define suball(args...) opapply(-,args)
#define multall(args...) opapply(*,args)
#define divall(args...) opapply(/,args)

