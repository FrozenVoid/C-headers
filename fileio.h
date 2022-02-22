#pragma once
#include "arguments.h"
#include <stdio.h>
#define filesize(fptr) ({ atype curpos=ftell(fptr);\
fseek(fptr,0,SEEK_END);atype retsize=ftell(fptr);\
fseek(fptr,curpos,SEEK_SET);retsize;})

#define fextension(filename) ({ char *dot = strrchr(filename, '.');(!dot || dot == filename)?"":dot+1;})

#define nooutbuffer setvbuf(stdout,NULL,_IONBF, 0);



static void* loadfile(char*filename,size_t* retsize){
FILE* in=NULL;u8* res=NULL;size_t size=0,freadres=0;
if(!filename||!retsize){perror("Invalid filename or sizeptr");goto end;}
 in=fopen(filename,"rb");
if(!in){perror(filename);goto end;}
if(fseek(in,0,SEEK_END)){goto fileend;}
 size=ftell(in);
if(!size)goto fileend;//empty file
if(fseek(in,0,SEEK_SET))goto fileend;
 res=malloc(size);
if(!res){perror("");goto fileend;}
 freadres=fread(res,1,size,in);
if(freadres==size)goto fileend;//success
free(res);
fileend:;fclose(in);
end:;*retsize=size;return (void*)res;}

//will create file if none exist
static size_t appendfile(char*filename,u8*data,size_t size){size_t res=0;
FILE*out=fopen(filename,"ab");
if(!out){perror(filename);goto end;}
res=fwrite(data,1,size,out);
fclose(out);
end:;return res;}

static size_t writefile(char*filename,u8*data,size_t size){size_t res=0;
FILE*out=fopen(filename,"wb");
if(!out){perror(filename);goto end;}
res=fwrite(data,1,size,out);
fclose(out);
end:;return res;}
