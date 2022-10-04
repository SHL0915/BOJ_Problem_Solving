#include <iostream>
using namespace std;

int N, M, index, ans;
int profit[20][301];
int memo[20][301];
int output[20][301];
int money[20];

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> index;
		for (int i = 0; i < M; i++)
			cin >> profit[i][index];
	}
	int temp = 0;
	for (int i = 0; i <= N; i++) { // 첫 번째 기업에 i만큼의 투자금을 사용
		temp = profit[0][i];
		if (temp > memo[0][i]) {
			memo[0][i] = temp;
			output[0][i] = i;
		}
	}
	for (int i = 1; i < M; i++) {
		for (int j = 0; j <= N; j++) { // i번째 기업까지 총 j만큼의 투자금 사용을 고려했을 때
			temp = 0;
			for (int k = 0; k <= j; k++) { // i번째 기업에 k만큼의 투자금을 사용
				if (profit[i][k] + memo[i - 1][j - k] > temp) {
					temp = profit[i][k] + memo[i - 1][j - k];
					output[i][j] = k;
				}
			}
			memo[i][j] = temp;
		}
	}
	for (int i = 0; i <= N; i++) {
		if (memo[M - 1][i] > ans) {
			ans = memo[M - 1][i];
			index = i;
		}
	}
	cout << ans << '\n';
	for (int i = M - 1; i >= 0; i--) {
		money[i] = output[i][index];
		index -= output[i][index];
	}
	for (int i = 0; i < M; i++)
		cout << money[i] << " ";
	return 0;
}