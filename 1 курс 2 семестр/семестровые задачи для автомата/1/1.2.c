#include <stdio.h>

int main() {
    int l, matrix[256][256], newmatrix[256][256], A, count = 0, W, H, min,max;
    scanf("%d %d", &W, &H);
    for (int t=0;t<H;t++) {
        for (int k=0;k<W;k++)
            scanf("%i", &matrix[t][k]);
    }
    for (int t=0;t<H;t++) {
        for (int k = 0; k < W; k++)
            newmatrix[t][k] = matrix[t][k];
    }
    return (0);
}
