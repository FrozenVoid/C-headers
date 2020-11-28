#pragma once
#include "arguments.h"
#include <stdio.h>
#define filesize(fptr) ({ atype curpos=ftell(fptr);\
fseek(fptr,0,SEEK_END);atype retsize=ftell(fptr);\
fseek(fptr,curpose,SEEK_SET);retsize;})
