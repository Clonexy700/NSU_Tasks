#include <stdio.h>
#include <math.h>

int main()
{
    int i,n, best_index;
    double a, best_number = 1, floor_number, ceil_number;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d\n", &n);
    for (i=1; i<=n; i++) {
      scanf("%lf ", &a);
      a = fabs(a);
      floor_number = a-floor(a);
      if (floor_number > 0.5) {
        ceil_number = ceil(a) - a;
        if (ceil_number < best_number) {
          best_number = ceil_number;
          best_index = i;
        }
      } else {
        if (floor_number < best_number) {
          best_number = floor_number;
          best_index = i;
      }
    }
  }
  printf("%d", best_index);
}
