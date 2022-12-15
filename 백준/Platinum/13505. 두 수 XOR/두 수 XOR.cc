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

	void insert(const char * s) {
		if (*s == 0) return;
		else {
			int now = *s - '0';
			if (ch[now] == 0) ch[now] = new Trie;
			ch[now]->insert(s + 1);
		}
	}

	void find(char* s) {
		if (*s == 0) return;
		else {
			int now = *s - '0';
			now ^= 1;
			if (ch[now] == 0) {
				*s = '0';
				ch[now ^ 1]->find(s + 1);
			}
			else {
				*s = '1';
				ch[now]->find(s + 1);
			}
		}
	}


};

int N, ans;
int arr[100000];
long long pow_2[32];

string itos(int A) {
	string ret = "";
	for (int i = 31; i >= 0; i--) {
		if (A >= pow_2[i]) {
			ret += '1';
			A -= pow_2[i];
		}
		else ret += '0';
	}
	return ret;
}

int strtoi(string s) {
	int ret = 0;
	for (int i = 31; i >= 0; i--) {
		if (s[i] == '1') ret += pow_2[31 - i];
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Trie* root = new Trie;
	pow_2[0] = 1;
	for (int i = 1; i <= 31; i++) pow_2[i] = pow_2[i - 1] * 2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		root->insert(itos(arr[i]).c_str());
	}
	for (int i = 0; i < N; i++) {
		string s = itos(arr[i]);
		char temp[33];
		for (int i = 0; i < s.size(); i++) temp[i] = s[i];
		temp[s.size()] = '\0';
		root->find(temp);
		for (int i = 0; i < s.size(); i++) s[i] = temp[i];
		ans = max(ans, strtoi(s));
	}
	cout << ans;
	return 0;
}