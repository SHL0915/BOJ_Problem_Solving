#include <bits/stdc++.h>
using namespace std;

struct Trie {
	bool end, check;
	Trie* ch[10];
	
	Trie() {
		end = false;
		check = false;
		memset(ch, 0, sizeof(ch));
	}
	~Trie() {
		for (int i = 0; i < 10; i++) if (ch[i]) delete ch[i];
	}

	void insert(const char* s) {
		if (!*s) end = true;
		else {
			int now = *s - '0';
			if (!ch[now]) {
				ch[now] = new Trie;
				check = true;
			}
			ch[now]->insert(s + 1);
		}
	}

	bool find(const char* s) {
		if (!*s) {
			if (check == true || end == false) return false;
			else return true;			
		}
		else {
			if (end) return false;
			int now = *s - '0';
			if (!ch[now]) return false;
			return ch[now]->find(s + 1);
		}
	}
};

int t, n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		Trie* root = new Trie;
		int flag = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (flag == 1) continue;
			root->insert(s.c_str());
			if (root->find(s.c_str()) == false) flag = 1;
		}
		if (flag == 1) cout << "NO\n";
		else cout << "YES\n";
		delete root;
	}
	return 0;
}