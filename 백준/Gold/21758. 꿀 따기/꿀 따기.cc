#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int N;
long long ans, anstemp;
int arr[100001];
long long psum[100001];
long long rpsum[100002];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	for (int i = N; i >= 1; i--) rpsum[i] = rpsum[i + 1] + arr[i];
	anstemp = 2 * psum[N] - arr[1];
	long long temp = INF;
	for (int i = 2; i < N; i++) temp = min(temp, psum[i] + arr[i]);
	anstemp -= temp;
	ans = max(ans, anstemp);
	anstemp = 2 * psum[N] - arr[N];
	temp = INF;
	for (int i = N - 1; i > 1; i--) temp = min(temp, rpsum[i] + arr[i]);
	anstemp -= temp;
	ans = max(ans, anstemp);
	anstemp = psum[N];
	anstemp -= (arr[1] + arr[N]);
	temp = 0;
	for (int i = 2; i < N; i++) temp = max(temp, (long long)arr[i]);
	anstemp += temp;
	ans = max(ans, anstemp);
	cout << ans;
	return 0;
}