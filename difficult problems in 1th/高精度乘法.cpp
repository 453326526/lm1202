#include <stdio.h>
#include <string.h>
#include<memory.h> 
 
#define MAXLENGTH (1000+1)
 
char num1[MAXLENGTH], num2[MAXLENGTH], ans[MAXLENGTH << 1];
unsigned tmp[MAXLENGTH << 1] = { 0 };
 
 
int main() {
int num;
scanf("%d", &num);
while(num-- ) {
	memset(ans, 0, sizeof(ans));
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	memset(tmp, 0, sizeof(tmp));
    scanf("%s%s", num1, num2);
    int l1 = strlen(num1), l2 = strlen(num2);
    int i, j;
    for (i = 0; i < l1; ++i)
        num1[i] -= '0';
    for (j = 0; j < l2; ++j)
        num2[j] -= '0';
 
    for (i = 0; i < l1; ++i)
        for (j = 0; j < l2; ++j)
            tmp[i + j + 1] += num1[i] * num2[j];
    for (i = l1 + l2 - 1; i > 0; --i) {
        ans[i] = '0' + tmp[i] % 10;
        tmp[i-1] += tmp[i] / 10;
    }
    ans[0] = '0' + tmp[0];
 
    for (i = 0; ans[i] == '0'; ++i)
        continue;
    printf("%s\n", ans + i);
}
    return 0;
}
