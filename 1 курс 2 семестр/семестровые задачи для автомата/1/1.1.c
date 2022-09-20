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
    for (int i=0;i<H;i++)
    {
        min=matrix[i][0];
        for (int x=1;x<W;x++)
        {
            if (matrix[i][x] < min )
            {
                min=matrix[i][x];
            }
        }

        for (int j=0;j<W;j++)

        {
            if (matrix[i][j]==min)
            {
                max=matrix[0][j];
                l = 1;
                A = max;
                for (int y=1;y<H;y++)
                {
                    A = A + matrix[y][j];
                    l++;
                    if ( matrix[y][j]>max ) {
                        max = matrix[y][j];
                    }
                }
                if (matrix[i][j]==max)
                {

                    count += 1;
                    newmatrix[i][j] = A / l;
                }
            }

        }
    }
    printf("%d\n", count);
    for (int t=0;t<H;t++) {
        for (int k=0;k<W;k++)
            printf("%d ", newmatrix[t][k]);
    printf("\n");
    }
    return (0);
}
