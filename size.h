#include <stdint.h>
 #ifdef WIN32
 #include <malloc.h>
 #define memsize(x) _msize((void*)x)
  #else
  #ifdef __APPLE__
  #include <malloc/malloc.h>
  #define memsize(x) malloc_size((const void*)x)
  #else//assume Linux-compatible
  #include <malloc.h>
  #define memsize(x) malloc_usable_size((void*)x)
  #endif
#endif
//does not work with constant string and many stack objects
// malloc and inline arrays, return number of elements
#define elems(x) ({ size_t s=sizeof(x);\
if(s==sizeof(void*)){s=memsize(x);}s/sizeof(x[0]);}) 
