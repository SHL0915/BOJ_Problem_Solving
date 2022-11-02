#include <iostream>
#include <algorithm>
using namespace std;

long long N, ans;
long long num[200000];

long long DnC(long long left, long long right);
long long GCD(long long left, long long right);
long long Euclid(long long A, long long B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];	
	ans = DnC(0, N - 1);
	cout << ans;
	return 0;
}

long long DnC(long long left, long long right) {
	if (left == right) return num[left];
	long long lower_mid = (right - left + 1) / 2;
	long long upper_mid = (right - left + 1) - (right - left + 1) / 2;
	long long result1 = GCD(left, left + lower_mid - 1) + DnC(left + lower_mid, right);
	long long result2 = GCD(right - upper_mid + 1, right) + DnC(left, right - upper_mid);
	return max(result1, result2);	
}

long long GCD(long long left, long long right) {
	long long result = num[left];
	for (int i = left + 1; i <= right; i++) result = Euclid(result, num[i]);
	return result;
}

long long Euclid(long long A, long long B) {
	if (A == 0 || B == 0) return 0;
	else if (A == 1 || B == 1) return 1;
	else if (A == B) return A;
	else if (A > B) {
		if (A % B == 0) return B;
		else return Euclid(A % B, B);
	}
	else {
		if (B % A == 0) return A;
		else return Euclid(A, B % A);
	}
}