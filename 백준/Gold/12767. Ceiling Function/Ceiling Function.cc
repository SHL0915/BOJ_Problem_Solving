#include <bits/stdc++.h>
using namespace std;

struct Tree {
	int val;
	char data, level;
	Tree* ch[2];

	Tree(int v, char d, char lv) {
		val = v;
		data = d;
		level = lv;
		memset(ch, 0, sizeof(ch));
	}
	~Tree() {
		for (int i = 0; i < 2; i++) if (ch[i]) delete ch[i];
	}

	void insert(int v) {
		if (v > val) {
			if (!ch[1]) ch[1] = new Tree(v, 'r', level + 1);
			else ch[1]->insert(v);
		}
		else {
			if (!ch[0]) ch[0] = new Tree(v, 'l', level + 1);
			else ch[0]->insert(v);
		}
	}

	string traverse() {
		string ret = "";
		if (ch[0]) ret += ch[0]->traverse();
		ret += level;
		ret += data;
		if (ch[1]) ret += ch[1]->traverse();
		return ret;
	}
};

int N, K;
set <string> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	while (N--) {
		int A;
		cin >> A;
		Tree* root = new Tree(A, 'm', 'A');
		for (int i = 1; i < K; i++) {
			cin >> A;
			root->insert(A);
		}
		s.insert(root->traverse());
		delete root;
	}
	cout << s.size();
	return 0;
}