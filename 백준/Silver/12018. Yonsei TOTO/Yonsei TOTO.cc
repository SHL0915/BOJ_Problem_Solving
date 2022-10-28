#include <iostream>
#include <algorithm>
using namespace std;

int N, M, P, L, ans;
int classes[100];
int need[100];

bool cmp(int A, int B) {
	return A > B;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		for (int j = 0; j < P; j++) cin >> classes[j];
		sort(classes, classes + P, cmp);
		if (P < L) need[i] = 1;
		else need[i] = classes[L - 1];
	}
	sort(need, need + N);
	for (int i = 0; i < N; i++) {
		if (M >= need[i]) {
			ans++;
			M -= need[i];
		}
		else break;
	}
	cout << ans;
	return 0;
}