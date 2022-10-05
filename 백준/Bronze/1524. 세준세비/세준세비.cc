#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M, s_index, b_index;
int S[1000000];
int B[1000000];

int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		for (int j = 0; j < N; j++)
			cin >> S[j];
		for (int j = 0; j < M; j++)
			cin >> B[j];
		sort(S, S + N);
		sort(B, B + M);
		s_index = 0;
		b_index = 0;
		while (1) {
			if (S[s_index] < B[b_index]) s_index++;
			else b_index++;
			if (s_index == N || b_index == M) break;
		}
		if (s_index == N)
			cout << "B\n";
		else
			cout << "S\n";
	}
	return 0;
}