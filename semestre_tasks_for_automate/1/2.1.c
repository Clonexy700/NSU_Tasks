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

    int flag_1 = 1;
    for (int i = 1; i < H && (flag_1 == 1); ++i) {
      for (int j = 0; j < i && (flag_1 == 1); ++j) {
        if (matrix[i][j] != 0)
          flag_1 = 0;
      }
    }

    int flag_2 = 1;
    for (int i = 0; i < H && (flag_2 == 1); ++i) {
      for (int j = i+1; j < H && (flag_2 == 1); ++j) {
        if (matrix[i][j] != 0)
          flag_2 = 0;
      }
    }



    printf("%d %d", flag_1, flag_2);

    return (0);
}
