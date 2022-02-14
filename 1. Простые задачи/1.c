#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int x_coord_1, y_coord_1, x_coord_2, y_coord_2, x_coord_3, y_coord_3;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &x_coord_1, &y_coord_1);
    scanf("%d %d", &x_coord_2, &y_coord_2);
    scanf("%d %d", &x_coord_3, &y_coord_3);
    double length_1, length_2, length_3;
    length_1 = sqrt((double)(((x_coord_1 - x_coord_2)*(x_coord_1 - x_coord_2)) + ((y_coord_1 - y_coord_2)*(y_coord_1 - y_coord_2))));
    length_2 = sqrt((double)(((x_coord_2 - x_coord_3)*(x_coord_2 - x_coord_3)) + ((y_coord_2 - y_coord_3)*(y_coord_2 - y_coord_3))));
    length_3 = sqrt((double)(((x_coord_1 - x_coord_3)*(x_coord_1 - x_coord_3)) + ((y_coord_1 - y_coord_3)*(y_coord_1 - y_coord_3))));
    double perimeter = length_1 + length_2 + length_3;
    printf("%.3f\n", perimeter);
    perimeter = (perimeter / 2);
    double square = sqrt(perimeter*(perimeter-length_1)*(perimeter-length_2)*(perimeter-length_3));
    printf("%.3f", square);
    return 0;
}
