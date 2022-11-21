#include <iostream>
#include <vector>
using namespace std;

int M, Q;
int table[200001][20];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M;
	for (int i = 1; i <= M; i++) {
		int A;
		cin >> A;
		table[i][0] = A;
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j <= M; j++) table[j][i] = table[table[j][i - 1]][i - 1];		
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int N, X;
		cin >> N >> X;
		int bit = 1;
		int pos = 0;
		int now = X;
		while (bit <= N) {
			if (N & bit) now = table[now][pos];
			bit <<= 1;
			pos++;
		}
		cout << now << '\n';
	}
	return 0;
}