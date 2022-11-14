#include <iostream>
using namespace std;

int N, sum, ans;
int arr[50];
bool table[2501][2501];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	table[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = sum; j >= 0; j--) {
			for (int k = sum; k >= 0; k--) {
				if (j >= arr[i]) table[j][k] |= table[j - arr[i]][k];
				if (k >= arr[i]) table[j][k] |= table[j][k - arr[i]];
			}
		}
	}
	for (int i = 0; i <= sum; i++) {
		for (int j = 0; j <= i; j++) {
			if (table[i][j] == 1) {
				if (sum - i - j <= j) {
					ans = max(ans, sum - i - j);
				}				
			}
		}
	}
	cout << ans;	
	return 0;
}