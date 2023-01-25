#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M;
string A, B;
int table[1001][1001][2];
pair<pii, int> ans[1001][1001][2];

int DP(int a, int b, int mode);

void solve() {
	cin >> N >> A;
	cin >> M >> B;
	memset(table, INF, sizeof(table));
	cout << DP(0, 0, 0) << '\n';
	int a = 0, b = 0, c = 0;
	string ans_a = "", ans_b = "";
	while (1) {
		pair<pii, int> temp = ans[a][b][c];		
		if (temp.second == 1) {
			if (temp.first.first == a + 1) ans_a += A[a];
			if (temp.first.second == b + 1) ans_b += B[b];
		}		
		a = temp.first.first;
		b = temp.first.second;
		if (c == 1 && temp.second == -1) break;
		c = temp.second;
		if (a >= N || b >= M) break;
	}
	cout << ans_a << '\n' << ans_b;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}

int DP(int a, int b, int mode) {
	if (a >= N || b >= M) return 0;
	int& ret = table[a][b][mode];
	if (ret != INF) return ret;
	ret = 0;
	int sum = 0, flag = 0;
	if (A[a] == B[b]) sum = 3;
	else sum = -2;
	if (sum + DP(a + 1, b + 1, 1) > ret) {
		ret = sum + DP(a + 1, b + 1, 1);
		ans[a][b][mode] = { {a + 1,b + 1},1 };
		flag = 1;
	}
	if (-2 + DP(a + 1, b, 1) > ret) {
		ret = -2 + DP(a + 1, b, 1);
		ans[a][b][mode] = { {a + 1,b},1 };
		flag = 1;
	}
	if (-2 + DP(a, b + 1, 1) > ret) {
		ret = -2 + DP(a, b + 1, 1);
		ans[a][b][mode] = { {a,b + 1},1 };
		flag = 1;
	}
	if (mode == 0) {
		if (DP(a + 1, b, 0) > ret) {
			ret = DP(a + 1, b, 0);
			ans[a][b][mode] = { {a + 1,b},0 };
			flag = 1;
		}
		if (DP(a, b + 1, 0) > ret) {
			ret = DP(a, b + 1, 0);
			ans[a][b][mode] = { {a,b + 1},0 };
			flag = 1;
		}
		if (DP(a + 1, b + 1, 0) > ret) {
			ret = DP(a + 1, b + 1, 0);
			ans[a][b][mode] = { {a + 1,b + 1},0 };
			flag = 1;
		}
	}	
	if (flag == 0) ans[a][b][mode] = { {0,0},-1 };
	return ret;
}