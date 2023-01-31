#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector <int> cpos;
set <int> tpos;

struct Trie {
	bool end;
	map <char, Trie*> ch;

	Trie() {
		end = false;
	}
	~Trie() {
		for (auto i = ch.begin(); i != ch.end(); i++) if ((*i).second) delete (*i).second;
	}

	void insert(const char* s) {
		if (!*s) end = true;
		else {
			char now = *s;
			if (ch.count(now) == 0) ch[now] = new Trie;
			ch[now]->insert(s + 1);
		}
	}
	void rev_insert(const char* s) {
		if (!*s) end = true;
		else {
			char now = *s;
			if (ch.count(now) == 0) ch[now] = new Trie;
			ch[now]->rev_insert(s - 1);
		}
	}
	void color(const char* s, int idx) {
		if (end == true) cpos.push_back(idx);
		if (!*s) return;
		else {
			char now = *s;
			if (ch.count(now) == 0) return;
			ch[now]->color(s + 1, idx + 1);
		}
	}
	void team(const char* s, int idx) {
		if (end == true) tpos.insert(idx);
		if (!*s) return;
		else {
			char now = *s;
			if (ch.count(now) == 0) return;
			ch[now]->team(s - 1, idx - 1);
		}
	}
};

int C, N, Q;

void solve() {
	cin >> C >> N;
	Trie* cRoot = new Trie;
	Trie* tRoot = new Trie;
	for (int i = 0; i < C; i++) {
		string s;
		cin >> s;
		cRoot->insert(s.c_str());
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		tRoot->rev_insert(s.c_str() + s.length() - 1);
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cpos.clear();
		tpos.clear();
		string s;
		cin >> s;
		cRoot->color(s.c_str(), 0);
		tRoot->team(s.c_str() + s.length() - 1, s.length());
		int ans = 0;		
		for (int j = 0; j < cpos.size(); j++) {
			if (ans) break;
			ans |= tpos.count(cpos[j]);
		}
		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
	delete cRoot;
	delete tRoot;
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