#pragma once
/* enumc(name,args...) 
create a strongly typed enum using unions.

*/
#define enumc(name,args...) typedef union name{char v;}name;name args;
#define isenumeq(a,b) ((&a)==(&b))
