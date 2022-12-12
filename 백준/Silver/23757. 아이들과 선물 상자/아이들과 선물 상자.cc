#include <bits/stdc++.h>
using namespace std;

int N, M, C, W;
priority_queue <int> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {		
		cin >> C;
		pq.push(C);
	}
	for (int i = 0; i < M; i++) {	
		cin >> W;
		if (pq.size() == 0) {
			cout << 0;
			return 0;
		}
		C = pq.top();
		pq.pop();
		if (C < W) {
			cout << 0;
			return 0;
		}
		C -= W;
		if(C > 0) pq.push(C);
	}
	cout << 1;
	return 0;
}