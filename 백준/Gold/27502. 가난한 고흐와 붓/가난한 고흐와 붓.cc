#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, t, ans;
int mark[2001];
int box[2001];
int parent[2001];

int Find(int a) {
   if (a == parent[a]) return parent[a];
   else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
   a = Find(a);
   b = Find(b);
   if (a == b) return;
   if (a > b) parent[a] = b;   
   else parent[b] = a;   
   return;
}

void solve() {
   cin >> N >> t;
   for (int i = 1; i <= N; i++) parent[i] = i;   
   if (t) {
      ans = N / 2 + 1;
      cout << "! " << ans << endl;
      for (int i = 1; i <= N / 2; i++) {
         int put, bb;
         for (int j = 1; j <= N; j++) {
            if (mark[j] == 0) {
               put = j;
               break;
            }
         }
         for (int j = 1; j <= N; j++) {
            if (box[j] == 0 && Find(j) == Find(put)) {
               bb = j;
               break;
            }
         }
         cout << put << " " << bb << endl;
         mark[put] = 1;
         box[bb] = 1;
         int a, b;
         cin >> a >> b;
         mark[a] = 1;
         box[b] = 1;
         Union(a, b);
      }
   }
   else {
      ans = N / 2;
      cout << "! " << ans << endl;
      for (int i = 1; i <= N / 2; i++) {
         int a, b;
         cin >> a >> b;
         mark[a] = 1;
         box[b] = 1;
         Union(a, b);
         int put, bb;
         for (int j = 1; j <= N; j++) {
            if (mark[j] == 0) {
               put = j;
               break;
            }
         }
         for (int j = 1; j <= N; j++) {
            if (box[j] == 0 && Find(j) == Find(put)) {
               bb = j;
               break;
            }
         }
         cout << put << " " << bb << endl;
         mark[put] = 1;
         box[bb] = 1;
      }
   }
}

int main(void) {
#ifndef ONLINE_JUDGE
   //freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(false);
   cin.tie(0);
   int t = 1;
   //cin >> t;
   while (t--) solve();
   return 0;
}