#include<stdio.h>
void hanuo(int n, char A, char B, char C) {
    if (n == 1) {
        printf("%c%c\n", A, C);
    } else {
        hanuo(n - 1, A, C, B);
        printf("%c%c\n", A, C);
        hanuo(n - 1, B, A, C);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    hanuo(n, '1', '2', '3');
    return 0;
}
