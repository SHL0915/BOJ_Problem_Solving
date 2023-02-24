#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

string s;

void solve() {
   cin >> s;
   for (int i = 1; i < s.length(); i++) {
      if (s[i] == s[i - 1]) {
         cout << "Or not.";
         return;
      }
   }
   cout << "Odd.";
   return;
}

int main(void) {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(false);
   cin.tie(0);
   int t = 1;
   //cin >> t;
   while (t--) solve();
   return 0;
}