#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a, int b) {
    return (a/gcd(a,b))*b;
}


int main() {
    int limit;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d\n", &limit);
    for (int i=0;i < limit; i++) {
        int a, b;
        scanf("%d %d\n", &a, &b);
        printf("%d\n", lcm(a,b));
    }
    return 0;
}
