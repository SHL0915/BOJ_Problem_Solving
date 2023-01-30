#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Trie {
	int cnt;
	Trie* ch[2];

	Trie() {
		cnt = 0;
		memset(ch, 0, sizeof(ch));
	}
	~Trie() {
		for (int i = 0; i < 2; i++) if (ch[i]) delete ch[i];
	}

	void insert(const char* s) {
		cnt++;
		if (!*s) return;
		else {
			int now = *s - '0';
			if (!ch[now]) ch[now] = new Trie;
			ch[now]->insert(s + 1);
		}
	}
	void del(const char* s) {
		cnt--;
		if (!*s) return;
		else {
			int now = *s - '0';
			ch[now]->del(s + 1);
		}
	}
	ll query(const char* s, int lv) {
		if (!*s) return 0;
		else {
			int now = *s - '0';
			if (ch[now ^ 1] && ch[now ^ 1]->cnt > 0) return (1LL << lv) + ch[now ^ 1]->query(s + 1, lv - 1);
			if (ch[now] && ch[now]->cnt > 0) return ch[now]->query(s + 1, lv - 1);
			return 0;
		}
	}
};

int M;

string convert(ll a);

void solve() {
	cin >> M;
	Trie* root = new Trie;
	root->insert(convert(0).c_str());
	for (int i = 0; i < M; i++) {
		ll a, b;
		cin >> a >> b;
		if (a == 1) root->insert(convert(b).c_str());
		else if (a == 2) root->del(convert(b).c_str());
		else cout << root->query(convert(b).c_str(), 34) << '\n';
	}
	delete root;
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

string convert(ll a) {
	string ret = "";
	while (a) {
		ret = (char)('0' + a % 2) + ret;
		a /= 2;
	}
	while (ret.length() < 35) ret = '0' + ret;
	return ret;
}