#include <bits/stdc++.h>
using namespace std;

int N;
int arr[101];
int pre[101];
pair<int, int> now[101];
string name[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		pre[arr[i]] = i;
		now[i] = { i,i };
	}
	for (int i = 1; i <= N; i++) cin >> name[i];
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= N; j++) now[j].first = pre[now[j].first];
	}
	for (int i = 1; i <= N; i++) now[i].second = i;
	sort(now + 1, now + 1 + N);
	for (int i = 1; i <= N; i++) cout << name[now[i].second] << '\n';
	return 0;
}