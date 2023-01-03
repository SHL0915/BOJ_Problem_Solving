#include <bits/stdc++.h>
using namespace std;

int N, cnt;
pair<int, pair<string, int>> arr[101];
map <string, int> now;
set <string> milk[1001];
set <string> board;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	now["Bessie"] = 7, now["Elsie"] = 7, now["Mildred"] = 7;
	milk[7].insert("Bessie");
	milk[7].insert("Elsie");
	milk[7].insert("Mildred");
	board = milk[7];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		string name = arr[i].second.first;
		int delt = arr[i].second.second;
		milk[now[name]].erase(name);
		now[name] += delt;
		milk[now[name]].insert(name);
		int M = 0;
		for (auto j = now.begin(); j != now.end(); j++) M = max(M, (*j).second);		
		if (board == milk[M]) continue;
		cnt++;
		board = milk[M];
	}
	cout << cnt;
	return 0;
}