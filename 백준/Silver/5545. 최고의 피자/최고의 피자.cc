#include <iostream>
#include <algorithm>
using namespace std;

int N, A, B, C;
int now_cal, now_price;
int arr[10000];

bool check(int n);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> A >> B >> C;
	now_cal = C;
	now_price = A;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = N - 1; i >= 0; i--) {
		if (check(arr[i]) == true) {
			now_cal += arr[i];
			now_price += B;
		}
	}
	cout << now_cal / now_price;
	return 0;
}

bool check(int n) {
	if (now_cal * (now_price + B) < now_price * (now_cal + n)) return true;
	else return false;
}