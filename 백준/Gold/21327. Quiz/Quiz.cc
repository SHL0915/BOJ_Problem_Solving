#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K, B;
vector <int> question[1001];
long long catSum[1001];
long long table[1001][1001];
long long temp[1001][1001];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K >> B;
	for (int i = 0; i < N; i++) {
		int point, cat;
		cin >> point >> cat;
		question[cat].push_back(point);
		catSum[cat] += point;
	}
	for (int i = 1; i <= M; i++) {
		catSum[i] += B;
		for (int j = 0; j <= K; j++) temp[0][j] = table[i - 1][j];
		for (int j = 0; j < question[i].size(); j++) {
			for (int k = 1; k <= K; k++) {				
				temp[j + 1][k] = max(temp[j][k], question[i][j] + temp[j][k - 1]);
			}
		}		
		for (int j = 0; j <= K; j++) {
			if (j < question[i].size()) table[i][j] = table[i - 1][j];
			else table[i][j] = max(table[i - 1][j], catSum[i] + table[i - 1][j - question[i].size()]);
		}
		for (int j = 0; j <= K; j++) table[i][j] = max(table[i][j], temp[question[i].size()][j]);
	}	
	cout << table[M][K];
	return 0;
}