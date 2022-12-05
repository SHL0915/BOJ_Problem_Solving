#include <iostream>
#include <vector>
using namespace std;

int N;
double ans;
pair<long long,long long> arr[10000];

double absol(double A){
  if(A >= 0) return A;
  else return -1 * A;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(1);
  cin >> N;
  for(int i = 0; i < N; i++){
    long long x, y;
    cin >> x >> y;
    arr[i] = {x,y};
  }
  long long temp = 0;
  for(int i = 0; i < N - 1; i++) temp += (arr[i].first * arr[i+1].second);
  temp += (arr[N-1].first * arr[0].second);
  for(int i = 0; i < N - 1; i++) temp -= (arr[i].second * arr[i+1].first);
  temp-= (arr[N-1].second * arr[0].first);
  ans = absol((double)temp / 2);
  cout << ans;  
  return 0;
}