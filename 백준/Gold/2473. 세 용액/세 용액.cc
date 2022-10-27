#include <iostream>
#include <algorithm>
using namespace std;

int N, lptr, rptr;
int ans[3];
long long ans_val;
long long liq[5000];

long long absolute(long long A) {
	if (A >= 0) return A;
	else return A * (long long)-1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> liq[i];
	sort(liq, liq + N);
	rptr = N - 1;
	ans_val = 4000000000;
	for (int i = 0; i < N - 2; i++) {
		lptr = i + 1;
		rptr = N - 1;
		while (lptr < rptr) {
			if (absolute(liq[i] + liq[lptr] + liq[rptr]) < ans_val) {
				ans_val = absolute(liq[i] + liq[lptr] + liq[rptr]);
				ans[0] = i; ans[1] = lptr; ans[2] = rptr;
			}
			if (liq[i] + liq[lptr] + liq[rptr] >= 0) rptr--;
			else lptr++;
		}
	}
	cout << liq[ans[0]] << " " << liq[ans[1]] << " " << liq[ans[2]];
	return 0;
}