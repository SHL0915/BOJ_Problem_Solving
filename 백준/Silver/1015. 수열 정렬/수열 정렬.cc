#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair <int, int> A[50];

bool cmp(pair<int, int> A, pair<int, int> B) {
	return A.second < B.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		A[i] = { input, i };
	}
	stable_sort(A, A + N);
	for (int i = 0; i < N; i++) A[i] = { A[i].second, i };
	stable_sort(A, A + N);
	for (int i = 0; i < N; i++) cout << A[i].second << " ";
	return 0;
}