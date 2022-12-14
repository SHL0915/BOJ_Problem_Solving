#include <bits/stdc++.h>
using namespace std;

struct Trie {
	bool end;
	int num;
	Trie* ch[26];

	Trie() {
		end = false;
		num = 0;
		memset(ch, 0, sizeof(ch));
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}

	void insert(const char* s) {
		if (!*s) end = true;		
		else {
			int now = *s - 'a';
			if (!ch[now]) {
				ch[now] = new Trie;
				num++;
			}
			ch[now]->insert(s + 1);
		}
	}

	int find(int depth) {
		int ret = 0;
		if (depth == -1) {
			for (int i = 0; i < 26; i++) if (ch[i]) ret += ch[i]->find(1);
		}
		else {
			if (end == true) ret += depth;
			if (num == 1 && end == false) {
				for (int i = 0; i < 26; i++) if (ch[i]) ret += ch[i]->find(depth);
			}
			else {
				for (int i = 0; i < 26; i++) if (ch[i]) ret += ch[i]->find(depth + 1);
			}
		}
		return ret;
	}
};

int N;
string s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(2);
	while (cin >> N) {
		Trie* root = new Trie;
		for (int i = 0; i < N; i++) {
			cin >> s;
			root->insert(s.c_str());
		}
		cout << (double)root->find(-1) / N << '\n';
		delete root;
	}
	return 0;
}