#include <iostream>
#include <vector>
using namespace std;

int N, K, ans = 1000000000;
int arr[1000000];
vector <int> lion;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] == 1) lion.push_back(i);
	}
	if (lion.size() < K) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i <= lion.size() - K; i++) ans = min(ans, lion[i + K - 1] - lion[i] + 1);		
	cout << ans;
	return 0;
}