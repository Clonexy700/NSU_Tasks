#include <stdio.h>
#include <stdlib.h>

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int d=1, p=1, k;
  scanf("%d", &k);
  while (k > 9*d*p) {
    k -= 9*d*p;
    d += 1;
    p *= 10;
  }
  int n = p + (k-1)/d;
  int m = d-(k-1) % d - 1;
  while (m--) n/=10;
  printf("%d", n%10);
}
