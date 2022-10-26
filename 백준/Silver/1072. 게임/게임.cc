#include <iostream>
using namespace std;

long long X, Y, num;

long long Search(long long left, long long right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> X >> Y;
	for (int i = 0; i <= 101; i++) {
		if (i * X > Y * 100) {
			num = i;
			break;
		}
	}
	if (num >= 100) cout << -1;
	else cout << Search(1, 1000000001);
	return 0;
}

long long Search(long long left, long long right) {
	long long mid = (left + right) / 2;
	if (left < right) {
		if (num * (X + mid) > (Y + mid) * 100) return Search(mid + 1, right);
		else return Search(left, mid);			
	}
	else return mid;
}