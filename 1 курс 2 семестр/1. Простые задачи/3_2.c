#include <math.h>
#include <stdio.h>
int main() {
    double a, b, c, discriminant, root1, root2, realPart, imagPart;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a==0 && b==0 && c==0) {
      printf("MANY");
      return 0;
    }

    if (a==0 && b==0) {
      printf("ERROR");
      return 0;
    }

    discriminant = b * b - 4 * a * c;

    if (a==0 && discriminant == 0) {
      root1 = root2 = -c/b;
      printf("1");
      printf("%.5lf", root1);
      return 0;
    }

    if (discriminant < 0) {
        printf("NO");
        return 0;
    }


    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("2");
        printf("%.5lf %.5lf", root2, root1);
    }

    else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
        printf("1");
        printf("%.5lf", root1);
    }

    else {
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("2");
        printf("%.5lf+%.5lfi %.5f-%.5fi", realPart, imagPart, realPart, imagPart);
    }

    return 0;
}
