#pragma once
#include "dapply.h"
#include "tapply.h"
#include "chainapply.h"
#include "recapply.h"
#include "blankapply.h"
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
cond((cond1,result),(cond2,result),...) return first tuple with condition evaluation to true or 0 if none match.
condelse(default,(cond1,result),(cond2,result),...) return first tuple with condition evaluation to true or 'default' if none match.
 condif(tuples...) cond with if(){}else if() instead of ternary
 condifelse(default,tuples...)  same as above with
 default condition( else if chaining)
orall(args...) apply short-circuit OR || which returns 1 if any condition is true,0 otherwise
andall(args...) apply short-circuit AND&& which returns 1 if all conditions are true,0 otherwise
andlast(args...) return last argument if all arguments are true, 0 otherwise.
orfirst(args...) return first true argument, 0 if none true.
ntharg(n,args...) return nth argument of arglist
rntharg(n,args...) return nth argument from end of arglist
restslice(n,args...) return arguments after Nth argument(including Nth)
frontslice(n,args...) return first N arguments
listslice(start,length,args...) return slice of arglist from StartNth  with length arguments
rlistslice(end,length,args...) return slice of arglist from Nth to Nth-Length argument from end with Length arguments
remlast(args...) remove last argument from list
removenth(args...) remove Nth argument from list
removernth(args...) remove Nth argument from list's end
 insertnth(n,arg,args...) insert arg at Nth place in arglist
insertrnth(n,arg,args...) nsert arg at Nth place in arglist from end
//evaluate a if a is a tuple, by using first argument as function
//if the a is not a turple the argument is returned as is
evtuplewith(func,a) merge(evtuplewith,istuple(a))(func,a)
//if the argument isn't a tuple(a,b,c...) (2+ arg tuple) the argument is unchanged
 evtuplerec(a) evtuplewith(rec2apply,a) -> rec2apply(a...) or a
 evtupleda(a) evtuplewith(dapply,a)  dapply(a...) or a
 evtupleop(a) evtuplewith(opapply,a)  opapply(a...) or a
evtupleap(a) evtuplewith(applyall,a) applyall(a...) or a
 evtuplef(a) evtuplewith(setapply,a) setapply(a...) or a
*/
#define reverse(args...) dapply(swapargs,id,args)
#define applyall(func,args...) chainapply(func,args)
#define mergeall(args...) dapply(merge,id,args)
#define toatom(args...) dapply(remcomma,id,args)
#define rec2apply(func,args...) dapply(func,id,args)
#define rect2apply(func,tuples...) dapply(func,detuple,tuples)
#define rec2applyt(func,tup,args...) dapply(func tup,id,args)


#define firstarg(args...) first(args) //forwarding
#define last(args...) firstarg(reverse2(args))

#define forwremlast(a) reverse(rest(a))
#define remlast(args...) forwremlast(reverse(args))
#define ntharg(n,arg...)   firstarg(merge(rec2chainapply,n)(rest,0,arg))
#define rntharg(n,arg...) ntharg(n,reverse(arg))
#define restslice(n,arg...) merge(rec2chainapply,n)(rest,0,arg)
#define frontslice(n,arg...) merge(chainapply,n)(id,arg)
#define listslice(start,len,arg...)  frontslice(len,restslice(start,arg))
#define rlistslice(end,len,arg...)  reverse(frontslice(len,restslice(end,reverse(arg))))
#define removenth(n,arg...) remlast(frontslice(n,arg)),restslice(n,rest(arg))
#define removernth(n,arg...)   reverse(removenth(n,reverse(arg)))


#define insertnth(n,arg,args...) skiparg(remlast(frontslice(n,args)),arg,restslice(n,args))
#define insertrnth(n,arg,args...) reverse(insertnth(n,arg,reverse(args)))

#define evtuplewith0(func,a...) a
#define evtuplewithx(func,args...) func(args)
#define evtuplewithx2(func,args...) evtuplewithx(func,remlast(args))
#define evtuplewith1(func,a)  evtuplewithx2(func,detuple(a),0)
#define evtuplewith(func,a) merge(evtuplewith,istuple(a))(func,a)

#define evtuplerec(a) evtuplewith(rec2apply,a)
#define evtupleda(a) evtuplewith(dapply,a)
#define evtupleop(a) evtuplewith(opapply,a)
#define evtupleap(a) evtuplewith(applyall,a)
#define evtuplef(a) evtuplewith(setapply,a)

#define set(name,val) typeof(val) name = val
#define dtset(tup) typeof(second tup) first tup = second tup;
#define setall(tup_args...) toatom(applyall(dtset,tup_args))
#define genargs(n,arg) merge(chainapply,n)(arg id,)



#define dupapply(func,n,args_tup) chainapply(func,genargs(n,args_tup))
#define tolists(args...) chainapply(tuple,args)
#define fromlists(args...) chainapply(detuple,args)
#define with(args...) {opapply(;,args);}
#define cond1(tup,arg) ternary((first tup),second tup,arg)
#define cond(tuples...) ({rec2apply(cond1,tuples,0);})
#define condelse(default,tuples...) ({rec2apply(cond1,tuples,default);})
#define condif1(tup) else if((first(detuple(tup)))){rest  tup;}
#define condif(tuples...)  ({if(0){;} blankapply(condif1,tuples) ;0;})
#define condifelse(default,tuples...)  ({if(0){;} blankapply(condif1,tuples) else {default;};})
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
#define andall(args...) ({opapply(&&,args);})
#define orall(args...) ({opapply(||,args);})
#define orfirst(args...) ({rec2apply(iftrue,args,0);})
#define andlast(args...) ({andall(args)?last(args):0;}) //(1,2,3)->(1)&&(3)

