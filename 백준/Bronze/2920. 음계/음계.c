#include <stdio.h>

int main(void)
{
     int arr[8];
     int i;
     int num=0;
     
     for(i=0;i<8;i++)
     {
         scanf("%d",&arr[i]);
     }
     for (i=0;i<8;i++)
     {
         if (arr[i] == i+1) num +=1 ;
         else if (arr[i]==8-i) num += 2;
     }
     
     if (num == 8) printf("ascending");
     else if (num == 16) printf("descending");
     else printf("mixed");
     
     return 0;
}
