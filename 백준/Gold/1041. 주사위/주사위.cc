#include <iostream>
#include <algorithm>
using namespace std;

long long N, ans;
long long dice[6];

long long findMinArea();
long long findMinTwoArea();
long long findMinThreeArea();

int main(void) {
	cin >> N;
	for (int i = 0; i < 6; i++) cin >> dice[i];	
	long long oneArea = findMinArea();
	long long twoArea = findMinTwoArea();
	long long threeArea = findMinThreeArea();
	if (N == 1) {
		long long temp = dice[0];
		for (int i = 0; i < 6; i++) {
			ans += dice[i];
			temp = max(temp, dice[i]);
		}
		ans -= temp;
		cout << ans;
	}	
	else {
		ans += threeArea * 4;
		ans += ((N - 2) * 8 + 4) * twoArea;
		ans += ((N - 2) * ((N - 2) * 5 + 4)) * oneArea;
		cout << ans;
	}
	return 0;
}

long long findMinArea() {
	long long result = dice[0];
	for (int i = 0; i < 6; i++) result = min(result, dice[i]);
	return result;
}

long long findMinTwoArea() {
	long long result = dice[0] + dice[1];
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			if ((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3)) continue;
			result = min(result, dice[i] + dice[j]);
		}
	}
	return result;
}

long long findMinThreeArea() {
	long long result = dice[0] + dice[1] + dice[2];
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			for (int k = j + 1; k < 6; k++) {
				if ((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 3) || (i == 0 && k == 5) || (i == 1 && k == 4) || (i == 2 && k == 3) || (j == 0 && k == 5) || (j == 1 && k == 4) || (j == 2 && k == 3)) continue;
				result = min(result, dice[i] + dice[j] + dice[k]);
			}
		}
	}
	return result;
}