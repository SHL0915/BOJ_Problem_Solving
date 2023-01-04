#include <bits/stdc++.h>
using namespace std;
int a,b,c[100],d[100],i,j;
int main(void){scanf("%d",&a);for(i=0;i<a;i++){scanf("%d",&c[i]);d[i]=c[i];}sort(d,d+a);for(i=0;i<a;i++){if(c[i]==d[i])continue;for(j=i+1;j<a;j++){if(c[j]==d[i]&&c[j]!=d[j]){swap(c[i],c[j]);b++;}}}printf("%d",b);return 0;}