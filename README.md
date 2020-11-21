# C-headers
Various C headers with utility macros/functions

------------
Compiler assumed to be GCC 7 or newer
```
#include "directory_name/void.h" //to include all headers.
argmanip - key functions 
dapply - recursive applicative of two functions (func2(func(argN),func2(...))
tapply - apply to fixed tuple and each argument(func(tup,argN),...)
chainapply - apply func to each argument
print.h - variadic print/scan macros
arguments.h - argcount and other argument macros
random.h -  random number functions
lambda.h - create a temporary function from arguments and return it.
```
