#include<stdio.h>
typedef struct node *link;
typedef struct node {
	int number;
	char ch;
	link next;
}node;
int main() {
	node list[101];
	int i, j, num, n;
	scanf("%d %d", &num, &n);
	for(i= 1; i<= num; i++) {
		scanf("%d%c", &list[i].number, &list[i].ch);
		if(i== 1)
			list[i].next= NULL;
		else
			list[i].next= &list[i- 1];
		}
		list[1].next= &list[num];
	for(i= 1; i<= num; i++) {
		if(list[i].number== n)
			printf("%c\n", list[i].next->ch);
	}
	return 0;
}
