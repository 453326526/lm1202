#include<stdio.h>
int main() {
char ch;
while((ch= getchar())!= '\0') {
if(ch<= 122&&ch>= 97) {
ch= 219- ch;
printf("%c", ch);
}
else if(ch<= 90&&ch>= 65) {
ch= 155- ch;
printf("%c", ch);
}
else
printf("%c", ch);
}
printf("\n");
return 0;
}

