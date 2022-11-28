#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, cnt;
ll arr[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	int lptr = 0, rptr = N-1;
	while (lptr < rptr) {
		if (arr[lptr] + arr[rptr] < M) lptr++;
		else {
			cnt++;
			lptr++;
			rptr--;
		}
	}
	cout << cnt;
	return 0;
}