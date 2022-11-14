#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int sum;
pair<int,int> arr[10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		sum = 0;
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			arr[i] = { input, i + 1 };
			sum += arr[i].first;
		}
		sort(arr, arr + N);
		if (arr[N - 1].first == arr[N - 2].first) cout << "no winner\n";
		else {
			if (arr[N - 1].first > sum / 2) cout << "majority winner " << arr[N - 1].second << '\n';
			else cout << "minority winner " << arr[N - 1].second << '\n';
		}
	}
	return 0;
}