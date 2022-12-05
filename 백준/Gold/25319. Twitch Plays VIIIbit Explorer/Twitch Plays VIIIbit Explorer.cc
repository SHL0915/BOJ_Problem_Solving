#include <bits/stdc++.h>
using namespace std;

int N, M, len, cnt = 1234567890;
int x, y;
string name, ans;
char arr[50][50];
vector <pair<int, int>> pos[26];
map <int, int> m;

void collect(int x1, int y1, int x2, int y2);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> len;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s[j];
			pos[s[j] - 'a'].push_back({ j,i });
		}
	}
	cin >> name;
	for (int i = 0; i < name.length(); i++) m[name[i] - 'a'] ++;
	for (auto i = m.begin(); i != m.end(); i++) cnt = min(cnt, (int)pos[(*i).first].size() / (*i).second);
	for (int i = 0; i < cnt; i++) {		
		for (int j = 0; j < len; j++) {			
			collect(x, y, pos[name[j] - 'a'].back().first, pos[name[j] - 'a'].back().second);
			x = pos[name[j] - 'a'].back().first;
			y = pos[name[j] - 'a'].back().second;
			pos[name[j] - 'a'].pop_back();
		}
	}
	collect(x, y, M - 1, N - 1);
	ans.erase(ans.end() - 1);
	cout << cnt << " " << ans.length() << '\n';
	cout << ans;
	return 0;
}

void collect(int x1, int y1, int x2, int y2) { 
	if (x1 > x2) {
		for (int i = 0; i < x1 - x2; i++) ans += 'L';
	}
	else {
		for (int i = 0; i < x2 - x1; i++) ans += 'R';
	}
	if (y1 > y2) {
		for (int i = 0; i < y1 - y2; i++) ans += 'U';
	}
	else {
		for (int i = 0; i < y2 - y1; i++) ans += 'D';
	}
	ans += 'P';
}