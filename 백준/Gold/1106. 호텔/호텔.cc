#include <iostream>
#include <vector>
using namespace std;

int C, N;
pair <int, int> city[20];
int table[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> N;
	for (int i = 0; i < N; i++) {
		int cost, num;
		cin >> cost >> num;
		city[i] = { cost, num };
	}
	for (int i = 0; i <= 100000; i++) {
		for (int j = 0; j < N; j++) {
			if (city[j].first > i) continue;
			table[i] = max(table[i], city[j].second + table[i - city[j].first]);
		}
	}
	for (int i = 0; i <= 100000; i++) {
		if (table[i] >= C) {
			cout << i;
			return 0;
		}
	}
	return 0;
}