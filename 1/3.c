#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
int a, b, c;
float discriminant, x1, x2;

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

scanf("%d %d %d", &a, &b, &c);

a = (double) a;
b = (double) b;
c = (double) c;


discriminant = b*b-4*a*c;

printf("discriminant raven %lf", discriminant);

if (a == 0 && b == 0 & c == 0) {
  printf("MANY");
  return 0;
}

if(discriminant < 0)
    printf("NO");

if (a==0)
    {
        if(b==0)
            printf("ERROR");
        else
            {
                x1=-c/b;
                printf("1\n");
                printf("%.5f", x1);
            }
    }
else
{
    if (discriminant==0)
    {
        x1=-b/(2*a);

        printf("1\n");
        printf("%.5f",x1);
    }


if (discriminant > 0)
    {
        discriminant=sqrt(discriminant);
        x1=(-b+discriminant)/(2*a);
        x2=(-b-discriminant)/(2*a);

        printf("2\n");
        printf("%.5f %.5f",x1,x2);
    }
}

return 0;

}
