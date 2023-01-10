#include <bits/stdc++.h>
using namespace std;

int N, cnt;
pair<int, int> arr[100001];
vector <int> graph[100001];
int mark[100001];

void DFS(int node);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) graph[i].push_back(arr[i].second);
	for (int i = 0; i < N; i++) {
		if (mark[i] == 0) {
			DFS(i);
			cnt++;
		}
	}
	cout << N - cnt;
	return 0;
}

void DFS(int node) {
	if (mark[node] == 1) return;
	mark[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) DFS(graph[node][i]);
	return;
}