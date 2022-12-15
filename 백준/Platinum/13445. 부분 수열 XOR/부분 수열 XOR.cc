#include <bits/stdc++.h>
using namespace std;

struct Trie {
	long long cnt;
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
		if (*s == 0) return;
		else {
			int now = *s - '0';
			if (!ch[now]) ch[now] = new Trie;
			ch[now]->insert(s + 1);
		}
	}

	long long query(const char* s, const char* cmp, bool type) {
		if (type == true) return cnt;
		if (*s == 0) return 0;
		else {
			int now = *s - '0';
			int k = *cmp - '0';
			if (k) {
				int ret = 0;
				if (ch[now]) ret += ch[now]->query(s + 1, cmp + 1, true);
				if (ch[now ^ 1]) ret += ch[now ^ 1]->query(s + 1, cmp + 1, false);
				return ret;
			}
			else {
				if (ch[now]) return ch[now]->query(s + 1, cmp + 1, false);
				else return 0;
			}
		}
	}
};

long long ans;
int N, K;
int arr[100001];
int XOR[100001];
int p[30];

int strtoi(string s) {
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') ret += p[25 - i];
	}
	return ret;
}

string itostr(int k) {
	string ret = "";
	for (int i = 0; i <= 25; i++) {
		if (k >= p[25 - i]) {
			ret += '1';
			k -= p[25 - i];
		}
		else ret += '0';
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Trie* root = new Trie;
	p[0] = 1;
	for (int i = 1; i <= 25; i++) p[i] = p[i - 1] * 2;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		XOR[i] = XOR[i - 1] ^ arr[i];
		if (XOR[i] < K) ans++;
		string s = itostr(XOR[i]);
		string k = itostr(K);
		ans += root->query(s.c_str(), k.c_str(), false);
		root->insert(s.c_str());
	}
	cout << ans;
	return 0;
}