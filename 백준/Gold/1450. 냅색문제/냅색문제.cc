#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C;
long long stuff[31];
vector <long long> l, r;
long long ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> C;	
	for (int i = 0; i < N; i++) cin >> stuff[i];
	for (long long i = 0; i < (long long)1 << (N / 2); i++) {
		long long sum = 0;
		long long bit = 1;
		for (int j = 0; j <= 15; j++) {
			if (bit & i) sum += stuff[j];
			bit <<= 1;
		}
		l.push_back(sum);		
	}
	for (long long i = 0; i < (long long)1 << (N - (N / 2)); i++) {
		long long sum = 0;
		long long bit = 1;
		for (int j = 0; j <= 15; j++) {
			if (bit & i) sum += stuff[j + N / 2];
			bit <<= 1;
		}
		r.push_back(sum);
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	for (long long i = 0; i < l.size(); i++) ans += upper_bound(r.begin(), r.end(), C - l[i]) - r.begin();	
	cout << ans;
	return 0;
}