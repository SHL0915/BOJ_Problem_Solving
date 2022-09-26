#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int N, K, k;
queue<pair<int, int>> q;
stack<int> s;
int mark[100001] = { 0 };
int path[100001] = { -1 };

void BFS(void);


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	if (N == K) {
		cout << 0 << "\n" << N;
		return 0;
	}
	q.push({N, -1});
	s.push(K);
	k = 0;
	while (q.size())
		BFS();
	return 0;
}

void BFS(void) {
	int vertex = q.front().first;
	int prev = q.front().second;
	q.pop();
	if (mark[vertex] != 0)
		return;
	mark[vertex] = 1;
	path[vertex] = prev;
	if (vertex > 0) {
		if (vertex - 1 == K) {
			path[K] = vertex;
			int i = K;
			while (1) {
				s.push(path[i]);
				k++;
				if (path[i] == N)
					break;
				i = path[i];
			}			
			cout << k << '\n';
			while (s.size()) {
				cout << s.top() << " ";
				s.pop();
			}
			exit(0);
		}
		q.push({ vertex - 1, vertex });
	}
	if (vertex < 100000) {
		if (vertex + 1 == K) {
			path[K] = vertex;
			int i = K;
			while (1) {
				s.push(path[i]);
				k++;
				if (path[i] == N)
					break;
				i = path[i];
			}
			cout << k << '\n';
			while (s.size()) {
				cout << s.top() << " ";
				s.pop();
			}
			exit(0);
		}
		q.push({ vertex + 1, vertex });
	}
	if (vertex <= 50000) {
		if (vertex * 2 == K) {
			path[K] = vertex;
			int i = K;
			while (1) {
				s.push(path[i]);
				k++;
				if (path[i] == N)
					break;
				i = path[i];
			}
			cout << k << '\n';
			while (s.size()) {
				cout << s.top() << " ";
				s.pop();
			}
			exit(0);
		}
		q.push({ vertex * 2, vertex });
	}
}