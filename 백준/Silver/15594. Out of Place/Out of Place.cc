#include<cstdio>
#include<algorithm>
int a,b[100],c[100],d,i;
int main(){scanf("%d",&d);for(i=0;i<d;i++){scanf("%d",&b[i]);c[i]=b[i];}std::sort(b,b+d);for(i=0;i<d;i++)a+=(b[i]!=c[i]);printf("%d",std::max(a-1,0));}