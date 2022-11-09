#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100000000;

int N, K, ans = INF, flag;
int population[11];
vector <int> graph[11];
vector <int> A, B;
int mark[11];

void DFS(int vertex);
int absol(int A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> population[i];
	for (int i = 1; i <= N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			int input;
			cin >> input;
			graph[i].push_back(input);
			graph[input].push_back(i);
		}
	}
	for (int i = 0; i < (1 << N); i++) {
		flag = 0;
		A.clear();
		B.clear();		
		for (int j = 1, bit = 1; j <= N; j++, bit <<= 1) {
			if (bit & i) A.push_back(j);
			else B.push_back(j);
		}		
		if (A.size() == 0 || A.size() == N) continue;	
		for (int j = 1; j <= N; j++) mark[j] = 0;
		for (int j = 0; j < A.size(); j++) mark[A[j]] = 1;
		DFS(B[0]);
		for (int j = 1; j <= N; j++) {
			if (mark[j] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		for (int j = 1; j <= N; j++) mark[j] = 0;
		for (int j = 0; j < B.size(); j++) mark[B[j]] = 1;
		DFS(A[0]);
		for (int j = 1; j <= N; j++) {
			if (mark[j] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		int sumA = 0, sumB = 0;
		for (int i = 0; i < A.size(); i++) sumA += population[A[i]];
		for (int i = 0; i < B.size(); i++) sumB += population[B[i]];
		ans = min(ans, absol(sumA - sumB));
	}
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

void DFS(int vertex) {
	if (mark[vertex] != 0) return;
	mark[vertex] = 1;
	for (int i = 0; i < graph[vertex].size(); i++) DFS(graph[vertex][i]);
	return;
}