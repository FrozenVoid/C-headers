#pragma once
/* lambda.h 
lambda(return_type,(arguments),funcbody...) create a function
 to be return as executable.

vlam((arguments),funcbody...) same as lambda returning void.
defun(name,return_type,argument_tuple,body...) create a lambda pointer(function pointer) with specific name to be called later.

examples:


int res=lambda(int,(int a,int b),int c=b+a,return c*b*a)(2,3);
print("result:",res,"\n");
float res2=lambda(float,(float a,float b,float d),float c=b+a*d,return c*b*a)(4.0,3.5,4.401);
print("result:",res2,"\n");
----
evtokens(args...) convert tokens to executable statements(last expr is returned)
callf(func,args...) return statement expression to call function in it.


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

#define defun(name,return_type,argument_tuple,body...) typeof(lambda(return_type,argument_tuple,body))name=lambda(return_type,argument_tuple,body)

#define evtokens(args...) ({opapply(;,args);})
#define callf(func,args...) ({func(args);})




#define partial(return_type,func,part_arg_tuple,final_tuple) ({ return_type partial_func part_arg_tuple {return func final_tuple;};partial_func;})

#define compose(return_type,func1,func2,arg_formats,arg_names_tuple) ({return_type composed_func arg_formats {\
return func1(func2 arg_names_tuple);};composed_func;})



