#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1234567890;

long long A, B, min_num = INF;
pair <long long, long long> ans;
vector <long long> primeNum;

long long absol(long long num) {
	if (num >= 0) return num;
	else return -1 * num;
}

long long GCD(long long N, long long K) {
	if (N == 1 || K == 1) return 1;
	else if (N == K) return N;
	else if (N > K) {
		if (N % K == 0) return K;
		else return GCD(N % K, K);
	}
	else {
		if (K % N == 0) return N;
		else return GCD(K % N, N);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B;
	long long temp = B / A;
	for (long long i = 1; i * i <= temp; i++) {
		if (temp % i != 0) continue;
		if (GCD(i, temp / i) != 1) continue;
		ans = { i, temp / i };
	}		
	cout << A * ans.first << " " << A * ans.second;
	return 0;
}