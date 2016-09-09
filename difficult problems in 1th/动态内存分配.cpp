##include<stdio.h>
#include<string.h>
char* join(char* a, int alength, char* b, int blength) {
int*ptr;// 通过ptr指针返回 
ptr= (char *)malloc(( alength+ blength+ 1 )*sizeof(ptr))// 动态申请ptr大小的内存 
strcpy(*ptr, *a) 
strcat(*ptr, *b);
return ptr;
}
 
