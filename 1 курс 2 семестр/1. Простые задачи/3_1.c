#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
    {

        float a,b,c,d,x1,x2;

        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);

        scanf("%f %f %f ",&a,&b,&c);

        d=b*b-4*a*c;

        if(d<0)
            printf("NO");

        if (a==0)
            {
                if(b==0)
                    printf("ERROR");
                else
                    {
                        x1=-c/b;
                        printf("1\n");
                        printf("%.5f",x1);
                    }
            }
        else
        {
            if (d==0)
            {
                x1=-b/(2*a);

                printf("1\n");
                printf("%.5f",x1);
            }


        if (d>0)
            {
                d=sqrt(d);
                x1=(-b+d)/(2*a);
                x2=(-b-d)/(2*a);

                printf("2\n");
                printf("%.5f %.5f",x1,x2);
            }
        }


    }
