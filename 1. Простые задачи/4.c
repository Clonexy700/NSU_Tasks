#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
    {

        unsigned int k;
        unsigned int d;
        double p;

        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);

        scanf("%d",&k);

        d=1+4*(k-1)*2;
        p=sqrt((double)d);
        if ((p - ((int)p)) == 0)
            printf("1");
        else
            printf("0");

    return 0;
    }
