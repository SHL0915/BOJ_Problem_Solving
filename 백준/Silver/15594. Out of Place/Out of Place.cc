#include<cstdio>
#include<algorithm>
int main(void){int a,b=0,c[100],d[100],i,j;scanf("%d",&a);for(i=0;i<a;i++){scanf("%d",&c[i]);d[i]=c[i];}std::sort(d,d+a);for(i=0;i<a;i++){if(c[i]==d[i])continue;for(j=i+1;j<a;j++){if(c[j]==d[i]&&c[j]!=d[j]){std::swap(c[i],c[j]);b++;}}}printf("%d",b);return 0;}