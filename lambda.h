#pragma once
/* lambda.h 
lambda(return_type,(arguments),funcbody...) create a function
 to be return as executable.
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
*/
#include <stdint.h>
#include "arguments.h"
#include "argmanip.h"
#define lambda(return_type,argument_tuple,body...) ({return_type lambda_func argument_tuple {opapply(;,body);}; lambda_func;})
#define evtokens(args...) ({opapply(;,args);})

#define reduce(func,arr) ({ typeof(arr[0]) accum=arr[0];\
for(size_t i=1;i<(sizeof(arr)/sizeof(accum));i++)accum=func(accum,arr[i]); accum;})

#define formap(func,arr) ({for(size_t i=0;i<(sizeof(arr)/sizeof(arr[0]));\
i++){arr[i]=func(arr[i]);};arr;})
#define foreach(func,arr) ({for(size_t i=0;i<(sizeof(arr)/sizeof(arr[0]));\
i++){func(arr[i]);};arr;})
