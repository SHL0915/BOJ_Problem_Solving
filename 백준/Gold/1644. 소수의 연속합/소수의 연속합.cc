#include <iostream>
#include <vector>
using namespace std;

int N, lptr, rptr, ans;
int table[4000001];
vector <int> primeNum;
int psum[300000];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (long long i = 2; i <= N; i++) {
		if (table[i] == 0) {
			table[i] = 1;
			primeNum.push_back(i);
			for (long long j = i * i; j <= N; j += i) table[j] = 1;
		}
	}
	if (N == 1) {
		cout << 0;
		return 0;
	}
	psum[0] = primeNum[0];
	for (int i = 1; i < primeNum.size(); i++) psum[i] = psum[i - 1] + primeNum[i];
	for (int lptr = 0; lptr < primeNum.size(); lptr++) {
		if (rptr == primeNum.size() - 1 && psum[rptr] - psum[lptr] + primeNum[lptr] < N) break;
		while (rptr < primeNum.size()) {
			if (psum[rptr] - psum[lptr] + primeNum[lptr] == N) {
				ans++;
				break;
			}
			else if (psum[rptr] - psum[lptr] + primeNum[lptr] > N) break;
			else if (rptr == primeNum.size() - 1) break;
			else rptr++;
		}
	}
	cout << ans;
	return 0;
}