#include <iostream>
#include <vector>
using namespace std;

int N;
int matrix[500][2];
int memo[500][500]; // i번째 행렬부터 j번째 행렬까지 곱할 때 필요한 최솟값을 memo[i][j]에 저장

int MatrixMul(pair <int, int> A, pair<int, int> B) {
	return A.first * A.second * B.second;
}

int DP(int start, int end);

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> matrix[i][0] >> matrix[i][1];
	cout << DP(0, N - 1);
	return 0;	
}

int DP(int start, int end) {
	if (start == end) return 0;
	else if (memo[start][end] != 0) return memo[start][end];	
	else {
		int temp = -1;
		for (int i = start; i < end; i++) {
			if (temp == -1) temp = DP(start, i) + DP(i + 1, end) + MatrixMul({ matrix[start][0], matrix[i][1] }, { matrix[i + 1][0], matrix[end][1] });
			else temp = min(temp, DP(start, i) + DP(i + 1, end) + MatrixMul({ matrix[start][0], matrix[i][1] }, { matrix[i + 1][0], matrix[end][1] }));
		}
		memo[start][end] = temp;
		return memo[start][end];
	}
}