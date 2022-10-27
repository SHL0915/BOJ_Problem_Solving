#include <iostream>
#include <algorithm>
using namespace std;

int N, lptr, rptr;
pair <int, int> ans;
long long liq[100000];

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
	ans = { lptr, rptr };
	while (lptr < rptr) {
		if (absolute(liq[lptr] + liq[rptr]) < absolute(liq[ans.first] + liq[ans.second])) ans = { lptr,rptr };
		if (liq[lptr] + liq[rptr] >= 0) rptr--;
		else lptr++;
	}
	cout << liq[ans.first] << " " << liq[ans.second];
	return 0;
}