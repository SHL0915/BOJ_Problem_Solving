#include <bits/stdc++.h>
using namespace std;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

struct Trie {
	bool end;
	Trie* ch[26];

	Trie() {
		end = false;
		memset(ch, 0, sizeof(ch));
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}

	void insert(const char* s) {
		if (!*s) end = true;
		else {
			int now = *s - 'A';
			if (!ch[now]) ch[now] = new Trie;
			ch[now]->insert(s + 1);
		}
	}

	bool check(const char* s) {
		if (!*s) {
			if (end == true) return true;
			else return false;
		}
		else {
			int now = *s - 'A';
			if (!ch[now]) return false;
			return ch[now]->check(s + 1);
		}
	}
};

int w, b, cnt, ans;
string arr[300000];
char board[4][4];
int mark[4][4];
Trie* root;
vector <string> v;
set <string> ss;

void BackTracking(int x, int y, string bt);
bool cmp(string A, string B) {
	if (A.length() == B.length()) return A < B;
	return A.length() > B.length();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	root = new Trie;
	cin >> w;
	for (int i = 0; i < w; i++) {
		cin >> arr[i];
		root->insert(arr[i].c_str());
	}
	cin >> b;
	while (b--) {
		cnt = 0, ans = 0;
		v.clear();
		ss.clear();
		for (int i = 0; i < 4; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 4; j++) {
				board[i][j] = s[j];
				mark[i][j] = 0;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				mark[i][j] = 1;
				string input = "";
				BackTracking(j, i, input + board[i][j]);
				mark[i][j] = 0;
			}
		}
		for (auto i = ss.begin(); i != ss.end(); i++) {
			cnt++;
			v.push_back(*i);
			if ((*i).length() <= 2) ans += 0;
			else if ((*i).length() <= 4) ans += 1;
			else if ((*i).length() == 5) ans += 2;
			else if ((*i).length() == 6) ans += 3;
			else if ((*i).length() == 7) ans += 5;
			else if ((*i).length() == 8) ans += 11;

		}		
		sort(v.begin(), v.end(), cmp);
		cout << ans << " " << v.front() << " " << cnt << '\n';
	}
	return 0;
}

void BackTracking(int x, int y, string bt) {
	if (bt.length() > 8) return;
	if (root->check(bt.c_str()) == true) ss.insert(bt);
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx > 3 || ny < 0 || ny > 3) continue;
		if (mark[ny][nx] == 1) continue;
		mark[ny][nx] = 1;
		BackTracking(nx, ny, bt + board[ny][nx]);
		mark[ny][nx] = 0;
	}	
}