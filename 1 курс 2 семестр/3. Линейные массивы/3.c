#include <stdio.h>
#include <stdlib.h>

int CountDate(int d1,int m1, int y1, int d2, int m2,int y2)
{
  int X1, X2;


  m1 = (m1 + 9) % 12;
  y1 = y1 - m1 / 10;
  X1= 365*y1 + y1/4 - y1/100 + y1/400 + (m1*306 + 5)/10 + ( d1 - 1 );

  m2 = (m2 + 9) % 12;
  y2 = y2 - m2 / 10;
  X2= 365*y2 + y2/4 - y2/100 + y2/400 + (m2*306 + 5)/10 + ( d2 - 1 );

  return abs(X2 - X1);
}

int IsDateValidInvalidValidInvalidValidInvalidInvalidValidolaMne(int dd, int mm, int yy)
{
  if(yy>=1 && yy<=9999)
    {
    if(mm>=1 && mm<=12)
    {
        if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
            return(1);
        else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
            return(1);
        else if((dd>=1 && dd<=28) && (mm==2))
            return(1);
        else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
            return(1);
        else
            return(0);
    }
    else
    {
            return(0);
    }
}
else
{
            return(0);
}

return 0;
}

int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int d1, m1, y1, d2, m2, y2;
  scanf("%d %d %d\n", &d1, &m1, &y1);
  scanf("%d %d %d", &d2, &m2, &y2);
  if ((IsDateValidInvalidValidInvalidValidInvalidInvalidValidolaMne(d1, m1, y1) == 1)&&(IsDateValidInvalidValidInvalidValidInvalidInvalidValidolaMne(d2, m2, y2) == 1)) {
        printf("%d", CountDate(d1, m1, y1, d2, m2, y2));
    } else {
    printf("ERROR");
  }
  return 0;
}
