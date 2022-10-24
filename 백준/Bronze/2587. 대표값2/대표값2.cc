#include <iostream>
#include <algorithm>
using namespace std;

int num[5];
int sum;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
		sum += num[i];
	}
	sort(num, num + 5);
	cout << sum / 5 << '\n' << num[2];
	return 0;
}