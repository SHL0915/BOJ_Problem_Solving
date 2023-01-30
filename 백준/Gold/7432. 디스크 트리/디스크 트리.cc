#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Trie {
	int level;
	bool end;
	map <string, Trie*> ch;

	Trie(int lv) {
		level = lv;
		end = false;
	}
	~Trie() {
		for (auto i = ch.begin(); i != ch.end(); i++) delete (*i).second;
	}

	void insert(vector <string>& v, int idx) {
		if (idx == v.size()) end = true;
		else {
			string now = v[idx];
			if (ch.count(now) == 0) ch[now] = new Trie(level + 1);
			ch[now]->insert(v, idx + 1);
		}
		return;
	}
	void func() {		
		for (auto i = ch.begin(); i != ch.end(); i++) {
			for (int j = 0; j < level; j++) cout << " ";
			cout << (*i).first << '\n';
			(*i).second->func();
		}
		return;
	}
};

int N;

void solve() {
	cin >> N;
	Trie* root = new Trie(0);
	for (int i = 0; i < N; i++) {
		string s, temp = "";
		vector <string> v;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '\\') {
				v.push_back(temp);
				temp = "";
			}
			else temp += s[j];
		}
		v.push_back(temp);
		root->insert(v, 0);
	}
	root->func();
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