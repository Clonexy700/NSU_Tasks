#include <stdio.h>

int main() {
  int N, M, P, K, L;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &N);
  scanf("%d %d %d %d", &M, &P, &K, &L);
  int number_of_apartments_on_floor = M/(L*(P-1)+(K-1));
  int entrance_number = (N-1)/number_of_apartments_on_floor/L+1;
  int apartment_floor_number = 1 + (N-1)/number_of_apartments_on_floor - L*(((N-1)/number_of_apartments_on_floor)/L);
  printf("%d %d", entrance_number, apartment_floor_number);
  return 0;
}
