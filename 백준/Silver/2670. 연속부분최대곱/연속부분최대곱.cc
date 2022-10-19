#include <iostream>
#include <algorithm>
using namespace std;

int N;
double ans;
double arr[10000];
double table[10000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(3);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	table[0] = arr[0];
	for (int i = 1; i < N; i++) table[i] = max(table[i - 1] * arr[i], arr[i]);
	for (int i = 0; i < N; i++) ans = max(ans, table[i]);
	cout << ans;
	return 0;
}