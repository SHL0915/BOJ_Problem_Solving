#include <bits/stdc++.h>
using namespace std;

struct Trie {
	Trie* ch[26];

	Trie() {
		memset(ch, 0, sizeof(ch));
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}

	void insert(const char* s) {
		if (*s) {
			int now = *s - 'a';
			if (!ch[now]) ch[now] = new Trie;
			ch[now]->insert(s + 1);
		}
	}
	int check(const char* s) {
		if (!*s) return 1;
		else {
			int now = *s - 'a';
			if (!ch[now]) return 0;
			return ch[now]->check(s + 1);
		}
	}
};

int N, M, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Trie* root = new Trie;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		root->insert(s.c_str());
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		ans += root->check(s.c_str());
	}
	cout << ans;
	return 0;
}