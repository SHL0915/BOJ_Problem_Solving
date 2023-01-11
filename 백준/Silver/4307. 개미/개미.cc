#include <bits/stdc++.h>
using namespace std;

int T, L, N;
int arr[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> L >> N;
		vector <int> m, M;
		for (int i = 0; i < N; i++) cin >> arr[i];
		sort(arr, arr + N);
		for (int i = 0; i < N; i++) {
			m.push_back(min(arr[i], L - arr[i]));
			M.push_back(max(arr[i], L - arr[i]));
		}
		sort(m.begin(), m.end());
		sort(M.begin(), M.end());
		cout << m.back() << " " << M.back() << '\n';
	}
	return 0;
}