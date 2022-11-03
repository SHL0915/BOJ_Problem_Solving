#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long ans;
long long A[4000];
long long B[4000];
long long C[4000];
long long D[4000];
vector <long long> l, r;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			l.push_back(A[i] + B[j]);
			r.push_back(C[i] + D[j]);
		}
	}
	sort(r.begin(), r.end());
	for (int i = 0; i < l.size(); i++) ans += (upper_bound(r.begin(), r.end(), 0 - l[i]) - lower_bound(r.begin(), r.end(), 0 - l[i]));
	cout << ans;
	return 0;
}