#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, m, n, ans;
long long A[1000];
long long B[1000];
long long sumA[1000];
long long sumB[1000];
vector <long long> pieceA, pieceB;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> A[i];
		if (i == 0) sumA[i] = A[i];
		else sumA[i] = sumA[i - 1] + A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
		if (i == 0) sumB[i] = B[i];
		else sumB[i] = sumB[i - 1] + B[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			if (i > 0 && j < m - 1) pieceA.push_back(sumA[m - 1] - (sumA[j] - sumA[i] + A[i]));
			pieceA.push_back(sumA[j] - sumA[i] + A[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i > 0 && j < n - 1) pieceB.push_back(sumB[n - 1] - (sumB[j] - sumB[i] + B[i]));
			pieceB.push_back(sumB[j] - sumB[i] + B[i]);
		}
	}
	sort(pieceA.begin(), pieceA.end());
	sort(pieceB.begin(), pieceB.end());
	for (int i = 0; i < pieceA.size(); i++) ans += (upper_bound(pieceB.begin(), pieceB.end(), N - pieceA[i]) - lower_bound(pieceB.begin(), pieceB.end(), N - pieceA[i]));
	ans += (upper_bound(pieceA.begin(), pieceA.end(), N) - lower_bound(pieceA.begin(), pieceA.end(), N));
	ans += (upper_bound(pieceB.begin(), pieceB.end(), N) - lower_bound(pieceB.begin(), pieceB.end(), N));
	cout << ans;
	return 0;
}