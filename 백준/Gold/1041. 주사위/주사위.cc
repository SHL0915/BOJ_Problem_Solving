#include <iostream>
using namespace std;

long long N, oneMin, twoMin, threeMin;
long long ans;
long long dice[6];

long long one();
long long two();
long long three();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < 6; i++) cin >> dice[i];
	oneMin = one();
	twoMin = two();
	threeMin = three();
	if (N == 1) {
		long long temp = oneMin;
		for (int i = 0; i < 6; i++) {
			ans += dice[i];
			temp = max(temp, dice[i]);
		}
		cout << ans - temp;
		return 0;
	}
	else if (N == 2) {
		ans += 4 * (threeMin + twoMin);
		cout << ans;
		return 0;
	}
	else {
		ans += (N - 2) * (N - 2) * oneMin;
		ans += 4 * threeMin;
		ans += 4 * (N - 2) * twoMin;
		ans += 4 * ((N - 1) * twoMin + (N - 2) * (N - 1) * oneMin);
		cout << ans;
		return 0;
	}
	return 0;
}

long long one() {
	long long result = 50;
	for (int i = 0; i < 6; i++) result = min(result, dice[i]);
	return result;
}

long long two() {
	long long result = 100;
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (i == 0 && j == 5 || i == 1 && j == 4 || i == 2 && j == 3) continue;
			result = min(result, dice[i] + dice[j]);
		}
	}
	return result;
}

long long three() {
	long long result = 150;
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			for (int k = j + 1; k < 6; k++) {
				if (i == 0 && j == 5 || i == 0 && k == 5 || j == 0 && k == 5) continue;
				if (i == 1 && j == 4 || i == 1 && k == 4 || j == 1 && k == 4) continue;
				if (i == 2 && j == 3 || i == 2 && k == 3 || j == 2 && k == 3) continue;
				result = min(result, dice[i] + dice[j] + dice[k]);
			}
		}
	}
	return result;
}