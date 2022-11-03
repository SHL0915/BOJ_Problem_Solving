#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long T, N, M, ans;
long long A[1000];
long long B[1000];
long long sumA[1000];
long long sumB[1000];
vector <long long> subA, subB;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (i == 0) sumA[i] = A[i];
		else sumA[i] = sumA[i - 1] + A[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> B[i];
		if (i == 0) sumB[i] = B[i];
		else sumB[i] = sumB[i - 1] + B[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) subA.push_back(sumA[j] - sumA[i] + A[i]);		
	}
	for (int i = 0; i < M; i++) {
		for (int j = i; j < M; j++) subB.push_back(sumB[j] - sumB[i] + B[i]);
	}
	sort(subB.begin(), subB.end());
	for (int i = 0; i < subA.size(); i++) ans += (upper_bound(subB.begin(), subB.end(), T - subA[i]) - lower_bound(subB.begin(), subB.end(), T - subA[i]));
	cout << ans;
	return 0;
}