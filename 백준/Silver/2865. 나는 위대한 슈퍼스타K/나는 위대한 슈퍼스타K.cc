#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;
vector <double> participant[101];
vector <double> max_ability;
double ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(1);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int idx;
			double input;
			cin >> idx >> input;
			participant[idx - 1].push_back(input);
		}
	}
	for (int i = 0; i < N; i++) {
		sort(participant[i].begin(), participant[i].end());
		max_ability.push_back(participant[i][M - 1]);
	}
	sort(max_ability.begin(), max_ability.end());
	for (int i = N - 1; i >= N - K; i--) ans += max_ability[i];
	cout << ans;
	return 0;
}