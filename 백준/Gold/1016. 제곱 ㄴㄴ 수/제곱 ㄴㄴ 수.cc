#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long N, M, ans;
int table[2000000];
vector <long long> num;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (long long i = 2; i  * i <= M; i++) {
		if (table[i] == 0) {
			table[i] = 1;
			num.push_back(i * i);
			for (long long j = i * i; j <= (long long)(sqrt(M) + 1); j += i) table[j] = 1;
		}
	}
	for (long long i = 0; i < 2000000; i++) table[i] = 0;
	for (long long i = 0; i < num.size(); i++) {
		long long s = N / num[i];
		if (N % num[i] != 0) s++;
		for (long long j = s; j * num[i] <= M; j++) table[j * num[i] - N] = 1;
	}
	for (long long i = 0; i <= M - N; i++) if (table[i] == 0) ans++;
	cout << ans;
	return 0;
}