#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K;
ll ans;
ll arr[200001];
ll psum[200001];
map <ll, int> m;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	for (int i = 1; i <= N; i++) {
		if (psum[i] == K) ans++;
		ans += m[psum[i] - K];
		m[psum[i]]++;
	}
	cout << ans;
	return 0;
}