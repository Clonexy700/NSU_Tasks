#include <stdio.h>

int main ()
{
  int days_in_months_1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int days_in_months_2[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day_1, month_1, year_1, day_2, month_2, year_2;
  scanf("%d %d %d\n", &day_1, &month_1, &year_1);
  scanf("%d %d %d\n", &day_2, &month_2, &year_2);
  int flag_1 = 0, flag_2 = 0;
  if (year_1%4||(year_1%100==0&&year_1%400)) {
    flag_1 = 1;
  }
  if (year_2%4||(year_2%100==0&&year_2%400)) {
    flag_2 = 1;
  }
  if (flag_1 == 1) {
    days_in_months_1[1] = 29;
  }
  if (flag_2 == 1) {
    days_in_months_2[1] = 29;
  }
  if (day_1 > days_in_months_1[month_1-1]) {
    printf("ERROR");
    return 0;
  }
  if (day_2 > days_in_months_2[month_2-1]) {
    printf("ERROR");
    return 0;
  }
  printf("1");
  return 0;
}
