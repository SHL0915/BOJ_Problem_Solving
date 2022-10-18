#include <iostream>
using namespace std;

int N, M;
int app[100][2];
long long table[10001];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> app[i][0];
	for (int i = 0; i < N; i++) cin >> app[i][1];
	for (int i = 0; i < N; i++) {
		for (int j = 10000; j >= 0; j--) {
			if (app[i][1] > j) continue;
			else if (app[i][0] + table[j - app[i][1]] > table[j]) table[j] = app[i][0] + table[j - app[i][1]];
		}
	}
	for (int i = 0; i <= 10000; i++) {
		if (table[i] >= M) {
			cout << i;
			return 0;
		}
	}
	return 0;
}