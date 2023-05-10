#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

struct Trie {
	bool end, check;
	int idx, val, depth;
	Trie* ch[2];

	Trie(int d) {
		end = false;
		check = false;
		idx = -1;
		val = -1;
		depth = d;
		memset(ch, 0, sizeof(ch));
	}
	~Trie() {
		for (int i = 0; i < 2; i++) if (ch[i]) delete ch[i];
	}

	void insert(const char* s, int id, int col) {
		if (!*s) {
			end = true;
			idx = id;
			val = col;
		}
		else {
			check = true;
			int now;
			if (*s == 'L') now = 0;
			else now = 1;
			if (!ch[now]) ch[now] = new Trie(depth + 1);
			ch[now]->insert(s + 1, id, col);
		}
	}
	pair<pii, int> query(const char* s) {
		pair<pii, int> ret = { { idx, val } , depth };
		if (!*s) return ret;
		else {
			int now;
			if (*s == 'L') now = 0;
			else now = 1;
			if (!ch[now]) return ret;
			else return max(ret, ch[now]->query(s + 1));
		}
	}
};

int Q, C;

void solve() {
	cin >> Q >> C;

	Trie* root = new Trie(0);

	for (int i = 0; i < Q; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b; cin >> b;
			string s; cin >> s;
			root->insert(s.c_str(), i, b);
		}
		else {
			string s; cin >> s;
			int color = -1, idx = -1, cnt = 0, ans_cnt = 0;
			pair <pii, int> ans = root->query(s.c_str());
			if (ans.first.first == -1) cout << -1 << '\n';
			else {
				int cnt = 0;
				for (int i = ans.second; i < s.length(); i++) {
					if (s[i] == 'R') cnt--;
					else cnt++;
				}
				int res = ans.first.second + cnt;
				if (res < 0) res += C * ((-res) / C + 1);
				cout << res % C << '\n';
			}
		}
	}
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