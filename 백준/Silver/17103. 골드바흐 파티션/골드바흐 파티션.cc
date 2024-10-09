#include <iostream>

using namespace std;

int arr[1000001];

void isPrime() {
    for(long long i = 2; i <= 1000000; i++) {
        if(!arr[i]) {
            for(long long j = i * i; j <= 1000000; j += i) arr[j] = 1;
        }
    }
}

void solve() {
   int n, i, ans;
   cin >> n;

   ans = 0;
   for (i = 2; i <= n/2; i++) {
      if ((arr[i] == 0) && (arr[n - i] == 0)) {
         ans++;
      }
   }
   cout << ans << '\n';
   return;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   isPrime();

   int t = 1;
   cin >> t;

   while (t--)
      solve();

   return 0;
}