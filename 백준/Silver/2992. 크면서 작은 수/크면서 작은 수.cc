#include <iostream>
#include <vector>
using namespace std;

string X;
vector <int> num;
int iX;
int mark[10];
int arr[10];
int ans = 1000000;

void BackTracking(int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> X;
	int temp = 1;
	for (int i = X.length()-1; i >= 0; i--) {
		num.push_back(X[i] - '0');
		iX += (X[i] - '0') * temp;
		temp *= 10;
	}
	BackTracking(0);
	if (ans == 1000000) cout << 0;
	else cout << ans;
	return 0;
}

void BackTracking(int k) {
	if (k == X.length()) {
		int sum = 0;
		int temp = 1;
		for (int i = X.length() - 1; i >= 0; i--) {
			sum += arr[i] * temp;
			temp *= 10;
		}
		if (sum > iX) ans = min(ans, sum);
	}
	else {
		for (int i = 0; i < X.length(); i++) {
			if (mark[i] == 0) {
				arr[k] = num[i];
				mark[i] = 1;
				BackTracking(k + 1);
				mark[i] = 0;
			}
		}
	}
	return;
}