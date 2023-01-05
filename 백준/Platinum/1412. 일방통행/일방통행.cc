#include <bits/stdc++.h>
using namespace std;

int N;
int arr[51][51];
int in_degree[51];
vector <int> graph[51];
set <int> s;
queue <int> q;

void Topology();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {	
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'N') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && arr[j][i] == 0) {
				in_degree[j] ++;
				graph[i].push_back(j);
				s.insert(i);
				s.insert(j);
			}
		}
	}
	Topology();
	cout << "YES";
	return 0;
}

void Topology() {
	for (int i = 0; i < N; i++) if (in_degree[i] == 0) q.push(i);
	for (int i = 0; i < s.size(); i++) {
		if (q.size() == 0) {
			cout << "NO";
			exit(0);
		}
		int now = q.front();
		q.pop();
		for (int j = 0; j < graph[now].size(); j++) {
			if (--in_degree[graph[now][j]] == 0) q.push(graph[now][j]);
		}
	}
	return;
}