#include<bits/stdc++.h>
using namespace std;
int a,b,c[100000],i;
double d;
int main(void) {ios::sync_with_stdio(false);cin.tie(0);cout<<fixed;cout.precision(7);cin>>a;for(i=0;i<a;i++){cin>>c[i];b+=c[i];}if(a==1){cout<<b;return 0;}sort(c,c+a);d=max((double)b/a,(double)c[a-2]);for(i=0;i<a;i++)d=max(d,min((double)(b-c[i])/(a-1),(double)c[i]));cout<<d;return 0;}