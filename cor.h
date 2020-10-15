#pragma once /* Coroutines for C*/
/*   
cbegin()  - start coroutine block
cret([arg]) - return a (optional) value, set to continue after this return
cend([arg])  - end block with final return with optinal arg.
creset([arg]) -  reset the switch, returning optional args(as cret),
cbreak() - break out of switch and reset switch value.

cbegin {
//this block is within the coroutine switch.
cret([x])

}cend([x])


see https://www.chiark.greenend.org.uk/~sgtatham/coroutines.html
*/
#define cbegin() static typeof(__LINE__) c_switch_l = 0;\
 switch(c_switch_l){  case 0:;

#define cret(args...) do{\
 c_switch_l = __LINE__;return args;case __LINE__:;}\
while(0)
#define creset(args...) do{\
 c_switch_l = 0;return args;}\
while(0)
#define cbreak() ;c_switch_l = 0;break;
#define cend(args...) ;} return args;





