#pragma once /* Coroutines for C*/
/*   
cbegin()  - start coroutine block(assumed to be inside function)
cret([arg]) - return a (optional) value, set to continue after this return
cend([arg])  - end block with final return with optional arg.
creset([arg]) -  reset the switch, returning optional args(as cret),
cbreak() - break out of switch and reset switch value.
cwait(cond,[args]) - return if condition not met,with optional args.(saves location to switch value)
cset(val) - set switch_line to specific value(e.g. cset(0) or cset(__LINE__)

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
#define creset(args...) c_switch_l = 0;return args;
#define cwait(cond,args...) do{\
 c_switch_l = __LINE__;case __LINE__:;if(!(cond)) return args;}\
while(0)
#define cbreak() ;c_switch_l = 0;break;
#define cset(v) ;c_switch_l = v;
#define cend(args...) ;} return args;






