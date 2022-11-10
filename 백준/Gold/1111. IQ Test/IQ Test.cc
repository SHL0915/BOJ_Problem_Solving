#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[51];
deque <pair<int, int>> candidate;

int absol(int A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	if (N <= 2) {
		if (N == 2 && arr[0] == arr[1]) cout << arr[0];
		else cout << "A";
		return 0;
	}
	for (int i = 0; i <= 1000000; i++) {
		candidate.push_back({ i, arr[1] - i * arr[0] });
		candidate.push_back({ -1 * i, arr[1] + i * arr[0] });
	}
	for (int i = 2; i < N; i++) {
		while (candidate.size()) {
			if (arr[i - 1] * candidate.front().first + candidate.front().second != arr[i]) candidate.pop_front();
			else break;
		}
	}	
	if (candidate.size() == 0) cout << "B";
	else cout << arr[N - 1] * candidate.front().first + candidate.front().second;
	return 0;
}