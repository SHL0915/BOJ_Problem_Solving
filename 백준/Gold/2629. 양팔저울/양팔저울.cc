#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int weight[30];
int table[2][20001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> weight[i];
	for (int i = 0; i < N; i++) {
		for (int j = 20000; j >= 0; j--) {
			if (j + weight[i] > 20000) continue;
			if(table[0][j] == 1) table[0][j + weight[i]] = 1;
		}
		table[0][weight[i]] = 1;
	}	
	for (int i = 0; i <= 20000; i++) {
		if (table[0][i] == 1) table[1][i] = 1;
		for (int j = 0; j <= i; j++) {
			if (table[0][i] == 1 && table[0][j] == 1) table[1][i - j] = 1;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int marble;
		cin >> marble;
		if (marble > 20000) cout << "N ";
		else if (table[1][marble] == 1) cout << "Y ";
		else cout << "N ";
	}
	return 0;
}