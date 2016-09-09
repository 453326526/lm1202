#include <stdio.h>
 
int n, v, d, p, vm, fin = 1;
 
int main() {
  scanf("%d%d", &n, &v);
  vm = v;
  while (n--) {
    scanf("%d%d", &d, &p);
    if (d > v) {
      fin = 0;
      break;
    }
    v -= d;
    v = (v+p > vm) ? vm : v+p;
  }
  printf(fin ? "Yes\n" : "No\n");
  return 0;
}///他妈的可以读一次判断一次卧槽
 
