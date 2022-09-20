#include<stdio.h>

int gcd( int a, int b )
{
   while( b^=a^=b^=a%=b );
   return a;
}

int main()
{
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int a, b;
   scanf("%d %d\n", &a, &b);
   printf("%d", gcd(a, b));
}
