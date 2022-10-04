#include <iostream>
using namespace std;

int N, M;
int Arr[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> Arr[1];
	for (int i = 2; i <= N; i++) {
		cin >> Arr[i];
		Arr[i] += Arr[i - 1];
	}	
	for (int k = 0; k < M; k++) {
		int i, j;
		cin >> i >> j;
		cout << Arr[j] - Arr[i - 1] << "\n";
	}
	return 0;
}