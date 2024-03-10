#include <bits/stdc++.h>

using namespace std;

int main()
{   
   char arr[5][15] = {0};
   int i, j;

   for (i = 0; i < 5; i++) {
      cin >> arr[i];
   }

   for (i = 0; i < 15; i++) {
      for (j = 0; j < 5; j++) {
         if (arr[j][i] != NULL)
            cout << arr[j][i];
      }
   }

   return 0;
}