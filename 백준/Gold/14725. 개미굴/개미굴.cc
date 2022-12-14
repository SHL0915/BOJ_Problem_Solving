#include <bits/stdc++.h>
using namespace std;

struct Trie {
	string name;
	bool end;
	int floor;
	map <string, Trie*> ch;

	Trie(int k, string s) {
		name = s;
		end = false;
		floor = k;
	}

	~Trie() {
		for (auto i = ch.begin(); i != ch.end(); i++) delete (*i).second;
	}

	void insert(const string* s) {
		if (*s == "") end = true;
		else {
			string now = *s;
			if (!ch[now]) ch[now] = new Trie(floor + 1, now);
			ch[now]->insert(s + 1);
		}
		return;
	}

	void print() {
		for (int i = 1; i < floor; i++) cout << "--";
		cout << name;
		if (floor != 0) cout << '\n';
		for (auto i = ch.begin(); i != ch.end(); i++) (*i).second->print();
		return;
	}
};

int N, K;
string arr[16];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Trie* root = new Trie(0, "");
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) cin >> arr[j];
		arr[K] = "";
		root->insert(arr);
	}
	root->print();
	return 0;
}