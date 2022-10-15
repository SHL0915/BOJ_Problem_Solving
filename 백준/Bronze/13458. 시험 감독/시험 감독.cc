#include <iostream>
#include <algorithm>
using namespace std;

long long N, B, C, ans;
long long arr[1000000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> B >> C;
	ans = N;
	for (int i = 0; i < N; i++) {
		if (arr[i] <= B) continue;
		else if ((arr[i] - B) % C == 0) ans += (arr[i] - B) / C;
		else ans += ((arr[i] - B) / C + 1);
	}
	cout << ans;
	return 0;
}