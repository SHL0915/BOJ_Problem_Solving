#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M;
vector <int> graph[501];
set <int> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	for (int i = 0; i < graph[1].size(); i++) {
		s.insert(graph[1][i]);
		for (int j = 0; j < graph[graph[1][i]].size(); j++) s.insert(graph[graph[1][i]][j]);
	}
	s.erase(1);
	cout << s.size();
	return 0;
}