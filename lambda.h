#pragma once
/* lambda.h 
lambda(return_type,(arguments),funcbody...) create a function
 to be return as executable.

vlam((arguments),funcbody...) same as lambda returning void.
examples:
int res=lambda(int,(int a,int b),int c=b+a,return c*b*a)(2,3);
print("result:",res,"\n");
float res2=lambda(float,(float a,float b,float d),float c=b+a*d,return c*b*a)(4.0,3.5,4.401);
print("result:",res2,"\n");
----
evtokens(args...) convert tokens to executable statements(last expr is returned)

reduce(func,arr) apply func to each element of array,return result
int arr[]={1,2,3,4,5,6,7,8,9};
int res=reduce(lambda(int,(int acc,int b),return acc+b),arr);
print("\nResult:",res,"\n");// 45
-----
formap(func,arr) set each array element to func(arr[i])
foreach(func,arr) execute func(arr[i]) for each element.
int arr[]={1,2,3,4,5,6,7,8,9};
int* res=formap(lambda(int,(int a),return a*a),arr);
print("\nResult:");foreach(print,arr);print("\n");
//Result: 1 4 9 16 25 36 49 64 81 
-----partial application
partial(return_type,func,part_arg_tuple,final_tuple)
-> create function_lambda(var_args)-> return function_name(fixed_args,var_args)
js: function partial(f, x) {
    return function(y) { return f(x, y);}}
note that #define already easily proxies any partial functions
  as #define proxytox(args...) xfunc(1,2,3,args) 
example:
int f1(int a,int b,int c,int d){return a*b*c*d;};
int res=partial(int,f1,(int d,int c),(2,3,c,d))(6,7);
print("\nResult:",res);//252
------compose
compose(return_type,f1,f2,arg_formats,arg_names_tuple) creates function(arg_format) that executes
 f1(f2(arg_formats var_names))  
example:

int f2(int c){return c*10;}
int f1(int a,int b,int c,int d){return a*b*c*d;};
int res=compose(int,f2,f1,(int a,int b,int c,int d),(a,b,c,d))(6,7,1,2);
print("\nResult:",res);//840

*/
#include <stdint.h>
#include "arguments.h"
#include "argmanip.h"
#define lambda(return_type,argument_tuple,body...) ({return_type lambda_func argument_tuple {opapply(;,body);}; lambda_func;})

#define vlam(argument_tuple,body...) ({void lambda_func argument_tuple {opapply(;,body);}; lambda_func;})

#define lamptr(name,return_type,argument_tuple,body...) typeof(lambda(return_type,argument_tuple,body))name=lambda(return_type,argument_tuple,body)

#define evtokens(args...) ({opapply(;,args);})

#define reduce(func,arr) ({ typeof(arr[0]) accum=arr[0];\
for(size_t i=1;i<(sizeof(arr)/sizeof(accum));i++)accum=func(accum,arr[i]); accum;})

#define formap(func,arr) ({for(size_t i=0;i<(sizeof(arr)/sizeof(arr[0]));\
i++){arr[i]=func(arr[i]);};arr;})
#define foreach(func,arr) ({for(size_t i=0;i<(sizeof(arr)/sizeof(arr[0]));\
i++){func(arr[i]);};arr;})


#define partial(return_type,func,part_arg_tuple,final_tuple) ({ return_type partial_func part_arg_tuple {return func final_tuple;};partial_func;})

#define compose(return_type,func1,func2,arg_formats,arg_names_tuple) ({return_type composed_func arg_formats {\
return func1(func2 arg_names_tuple);};composed_func;})


