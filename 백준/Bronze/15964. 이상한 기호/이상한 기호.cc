#include <bits/stdc++.h>
using namespace std;

long long func(long long A, long long B) {
	return (A + B) * (A - B);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long A, B;
	cin >> A >> B;
	cout << func(A, B);
	return 0;
}