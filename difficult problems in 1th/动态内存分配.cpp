##include<stdio.h>
#include<string.h>
char* join(char* a, int alength, char* b, int blength) {
int*ptr;// ͨ��ptrָ�뷵�� 
ptr= (char *)malloc(( alength+ blength+ 1 )*sizeof(ptr))// ��̬����ptr��С���ڴ� 
strcpy(*ptr, *a) 
strcat(*ptr, *b);
return ptr;
}
 
