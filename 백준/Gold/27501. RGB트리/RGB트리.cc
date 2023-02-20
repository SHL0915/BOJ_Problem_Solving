#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
vector <int> graph[500001];
ll arr[500001][3];
ll table[500001][3];
int ans[500001];

ll DP(int node, int par, int color);
void DFS(int node, int par, int color);

void solve() {
   cin >> N;
   for (int i = 0; i < N - 1; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }
   for (int i = 1; i <= N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
   memset(table, -1, sizeof(table));
   ll a = DP(1, -1, 0);
   ll b = DP(1, -1, 1);
   ll c = DP(1, -1, 2);
   vector <pii> v;
   v.push_back({ a,0 });
   v.push_back({ b,1 });
   v.push_back({ c,2 });
   sort(v.begin(), v.end(), greater<>());
   cout << v[0].first << '\n';
   DFS(1, -1, v[0].second);
   for (int i = 1; i <= N; i++) {
      if (ans[i] == 0) cout << "R";
      else if (ans[i] == 1) cout << "G";
      else cout << "B";
   }
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

ll DP(int node, int par, int color) {
   ll& ret = table[node][color];
   if (ret != -1) return ret;
   ret = arr[node][color];
   for (int i = 0; i < graph[node].size(); i++) {
      int next = graph[node][i];
      if (next == par) continue;
      ll val = 0;
      for (int j = 0; j < 3; j++) {
         if (j == color) continue;
         val = max(val, DP(next, node, j));
      }
      ret += val;
   }
   return ret;
}

void DFS(int node, int par, int color) {
   ans[node] = color;
   for (int i = 0; i < graph[node].size(); i++) {
      int next = graph[node][i];
      if (next == par) continue;
      pii val[2];
      int idx = 0;
      for (int j = 0; j < 3; j++) {
         if (j == color) continue;
         val[idx].first = table[next][j];
         val[idx++].second = j;
      }
      if (val[0].first > val[1].first) DFS(next, node, val[0].second);
      else DFS(next, node, val[1].second);
   }
   return;
}