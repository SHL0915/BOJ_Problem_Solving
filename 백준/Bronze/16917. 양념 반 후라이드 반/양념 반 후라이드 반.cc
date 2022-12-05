#include <bits/stdc++.h>
using namespace std;

int A, B, C, X, Y;
long long ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> C >> X >> Y;
  if(A + B >= 2 * C){
    int temp = min(X,Y);
    ans += (2 * C) * temp;
    X-= temp;
    Y -= temp;
  }
  if(X >= 0){
    if(A >= 2 * C) ans+= 2 * C * X;
    else ans += A * X;
  }
  if(Y >= 0){
    if(B >= 2 * C) ans+= 2 * C * Y;
    else ans += B * Y;
  }
  cout << ans;
  return 0;
}