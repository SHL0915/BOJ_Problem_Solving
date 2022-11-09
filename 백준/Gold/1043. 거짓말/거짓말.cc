#include <iostream>
#include <vector>
using namespace std;

int N, M, K, flag, cnt;
vector <int> graph[51];
vector <int> truth;
int party[50][50];
int mark[51];

void DFS1(int vertex);
void DFS2(int vertex);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int input;
		cin >> input;
		truth.push_back(input);
	}
	for (int i = 0; i < M; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> party[i][j];
			if (j == 0) continue;
			else {
				graph[party[i][j - 1]].push_back(party[i][j]);
				graph[party[i][j]].push_back(party[i][j - 1]);
			}
		}		
	}
	for (int i = 0; i < truth.size(); i++) DFS1(truth[i]);
	for (int i = 0; i < M; i++) {
		flag = 0;
		cnt++;
		DFS2(party[i][0]);
	}
	cout << cnt;
	return 0;
}

void DFS1(int vertex) {
	if (mark[vertex] != 0) return;
	mark[vertex] = 2;
	for (int i = 0; i < graph[vertex].size(); i++) DFS1(graph[vertex][i]);
	return;
}

void DFS2(int vertex) {
	if (mark[vertex] == 2 && flag == 0) {
		cnt--;
		flag = 1;
	}
	if (mark[vertex] != 0) return;
	mark[vertex] = 1;
	for (int i = 0; i < graph[vertex].size(); i++) DFS2(graph[vertex][i]);
	return;
}