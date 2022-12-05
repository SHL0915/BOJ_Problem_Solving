#include <bits/stdc++.h>
using namespace std;

int N;
set <long long> cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= N; j++){
      for(int k = 0; k <= N; k++){
        for(int l = 0; l <= N; l++){
          if(i+j+k+l != N) continue;
          cnt.insert(i + j * 5 + k * 10 + l * 50);
        }
      }
    }
  }
  cout << cnt.size();
  return 0;
}