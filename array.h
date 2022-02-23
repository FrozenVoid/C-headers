#pragma once
#include <stdint.h>
#include "random.h"
/*
combsort(A,length) sort array with combsort
reduce(func,arr,len)  return accumulated value from func(accum,arr[i])
formap(func,arr,len) set len elements to func(arr[i])
foreach(func,arr,len) execute func(arr[i]) for len elements
dupfilter(arr,len) check if array(or its first len members) has duplicates(1) or not (0)
uniqueset(arr,len,rangestart) set len elements of array to rangestart+i
uniquesetrand(arr,len,rangemin,rangemax) set array elements to unique values in range

*/
    #define combsort(A,lenx) ({size_t i,j, gap=lenx,len=gap;;;\
    do{gap = gap<10 ? gap-1 : (gap*7)/9+1;\
    for (i=0,j=gap; j<len; i++,j++){\
    const typeof(A[0]) tmp=A[i];\
    const int cnd=tmp>A[j];\
    A[i]=cnd?A[j]:tmp;A[j]=cnd?tmp:A[j];};}while (gap);})

#define reduce(func,arr,len) ({ typeof(arr[0]) accum=arr[0];\
for(size_t i=1;i<len;i++)accum=func(accum,arr[i]); accum;})
#define formap(func,arr,len) ({for(size_t i=0;i<len;i++){arr[i]=func(arr[i]);};arr;})
#define foreach(func,arr,len) ({for(size_t i=0;i<len;i++){func(arr[i]);};arr;})

#define dupfilter(arr,len) ({size_t location=-1;\
for(size_t i=0;i<len;i++){ typeof(arr[0]) t=arr[i]; for(size_t x=i+1;x<len;x++)if(t==arr[x]){location=x;break;} if(location!=-1)break;    }location;})

#define uniqueset(arr,len,rangestart) ({typeof(rangemax) cur=rangestart;\
for(size_t i=0;i<len;i++){arr[i]=cur++;};arr; })

#define uniquesetrand(arr,len,rangemin,rangemax) ({size_t loc=-1; \
for(size_t i=0;i<len;i++){arr[i]=rrange(rangemin,rangemax);};\
for(loc=dupfilter(arr,len);loc!=-1;loc=dupfilter(arr,len)){ arr[loc]=rrange(rangemin,rangemax); };arr; })

#define arrcopy(dest,src,len) ({for(size_t i=0;i<len;i++)dest[i]=src[i];dest;})
#define arr2copy(dest,locs,src,len) ({for(size_t i=0;i<len;i++)dest[locs[i]]=src[i];dest;})
#define arrcopy2(dest,src,locs,len) ({for(size_t i=0;i<len;i++)dest[i]=src[locs[i]];dest;})


