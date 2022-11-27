#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> arr;
int table[1001][16][16];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int A, B;
	while (cin >> A >> B) arr.push_back({ A,B });
	table[0][1][0] = arr[0].first;
	table[0][0][1] = arr[0].second;
	for (int i = 1; i < arr.size(); i++) {
		for (int j = 0; j <= 15; j++) {
			for (int k = 0; k <= 15; k++) {
				int w = 0, b = 0;
				if (j >= 1) w = table[i - 1][j - 1][k] + arr[i].first;
				if (k >= 1) b = table[i - 1][j][k - 1] + arr[i].second;
				table[i][j][k] = max(table[i - 1][j][k], max(w, b));
			}
		}
	}
	cout << table[arr.size() - 1][15][15];
	return 0;
}