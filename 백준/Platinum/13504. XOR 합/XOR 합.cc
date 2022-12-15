#include <bits/stdc++.h>
using namespace std;

struct Trie {
	Trie* ch[2];
	Trie() {
		memset(ch, 0, sizeof(ch));
	}
	~Trie() {
		for (int i = 0; i < 2; i++) if (ch[i]) delete ch[i];
	}

	void insert(const char* s) {
		if (*s == 0) return;
		else {
			int now = *s - '0';
			if (ch[now] == 0) ch[now] = new Trie;
			ch[now]->insert(s + 1);
		}
	}

	void query(char* s) {
		if (*s == 0) return;
		else {
			int now = (*s - '0') ^ 1;
			if (ch[now]) {
				*s = '1';
				ch[now]->query(s + 1);
			}
			else {
				*s = '0';
				ch[now ^ 1]->query(s + 1);
			}
		}
	}
};

int T, N;
int arr[100000];
int	XOR[100000];
long long pow_2[32];
Trie* root;

string itostr(int A) {
	string ret = "";
	for (int i = 0; i < 32; i++) {
		if (A >= pow_2[31 - i]) {
			ret += '1';
			A ^= pow_2[31 - i];
		}
		else ret += '0';
	}
	return ret;
}

int strtoi(string s) {
	int ret = 0;
	for (int i = 0; i < 32; i++) {
		if (s[i] == '1') ret += pow_2[31 - i];
	}
	return ret;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	pow_2[0] = 1;
	for (int i = 1; i < 32; i++) pow_2[i] = pow_2[i - 1] * 2;
	cin >> T;
	while (T--) {
		root = new Trie;
		cin >> N;
		int ans = 0;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			if (i == 0) XOR[i] = arr[i];
			else XOR[i] = XOR[i - 1] ^ arr[i];
			string s = itostr(XOR[i]);
			char temp[35];
			for (int i = 0; i < s.length(); i++) temp[i] = s[i];
			temp[s.length()] = 0;
			root->insert(s.c_str());
			root->query(temp);
			for (int i = 0; i < s.length(); i++) s[i] = temp[i];
			ans = max({ ans, XOR[i], strtoi(s) });
		}
		cout << ans << '\n';
		delete root;
	}
	return 0;
}