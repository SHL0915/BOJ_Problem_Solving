#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, pair<int, int>> piiii;

int N, ans;
piiii arr[101];
int table[101][2];
vector <int> v;

bool cmp(piiii A, piiii B) {
	return A.first.first > B.first.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].first.first >> arr[i].second.first >> arr[i].first.second;
		arr[i].second.second = i;
	}
	sort(arr + 1, arr + N + 1, cmp);
	for (int i = 1; i <= N; i++) {
		table[i][0] = arr[i].second.first;
		table[i][1] = i;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[i].first.second > arr[j].first.second) continue;
			if (table[i][0] < table[j][0] + arr[i].second.first) {
				table[i][0] = table[j][0] + arr[i].second.first;
				table[i][1] = j;
			}
		}
		ans = max(ans, table[i][0]);
	}
	int pos = 0;
	for (int i = 1; i <= N; i++) if (table[i][0] == ans) pos = i;
	while (1) {
		v.push_back(arr[pos].second.second);
		if (table[pos][1] == pos) break;
		else pos = table[pos][1];
	}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
	return 0;
}