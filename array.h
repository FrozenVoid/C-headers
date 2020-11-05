#pragma once
#include <stdint.h>
#include "random.h"
/*
reduce(func,arr,len)  return accumulated value from func(accum,arr[i])
formap(func,arr,len) set len elements to func(arr[i])
foreach(func,arr,len) execute func(arr[i]) for len elements
dupfilter(arr,len) check if array(or its first len members) has duplicates(1) or not (0)
uniqueset(arr,len,rangemin,rangemax) set len elements of array to unique values  min< arr[x] > min

*/
#define reduce(func,arr,len) ({ typeof(arr[0]) accum=arr[0];\
for(size_t i=1;i<len;i++)accum=func(accum,arr[i]); accum;})
#define formap(func,arr,len) ({for(size_t i=0;i<len;i++){arr[i]=func(arr[i]);};arr;})
#define foreach(func,arr,len) ({for(size_t i=0;i<len;i++){func(arr[i]);};arr;})

#define dupfilter(arr,len) ({size_t location=-1;\
for(size_t i=0;i<len;i++){ typeof(arr[0]) t=arr[i]; for(size_t x=i+1;x<len;x++)if(t==arr[x]){location=x;break;} if(location!=-1)break;    }location;})

#define uniqueset(arr,len,rangemin,rangemax) ({size_t loc=-1; \
for(size_t i=0;i<len;i++){arr[i]=rrange(rangemin,rangemax);};\
for(loc=dupfilter(arr,len);loc!=-1;loc=dupfilter(arr,len)){ arr[loc]=rrange(rangemin,rangemax); };arr; })


