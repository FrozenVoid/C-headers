#pragma once
/* lambda.h 
lambda(return_type,(arguments),funcbody...) create a function
 to be return as executable.
examples:
int res=lambda(int,(int a,int b),int c=b+a,return c*b*a)(2,3);
print("result:",res,"\n");
float res2=lambda(float,(float a,float b,float d),float c=b+a*d,return c*b*a)(4.0,3.5,4.401);
print("result:",res2,"\n");
*/
#include "arguments.h"
#include "argmanip.h"
#define lambda(return_type,argument_tuple,body...) ({return_type lambda_func argument_tuple {opapply(;,body);}; lambda_func;})
