#include <iostream>
#include <algorithm>
using namespace std;

int N, K, ans;
int stuffs[100][2];
int memo[100001];
int mark[100];

int main(void) {
	cin >> N >> K;
	for (int i = 0; i < N; i++) 
		cin >> stuffs[i][0] >> stuffs[i][1];
	for (int i = 0; i < N; i++) {
		for (int j = K; j >= 0; j--) {
			if (stuffs[i][0] > j)
				continue;
			else 
				memo[j] = max(memo[j], stuffs[i][1] + memo[j - stuffs[i][0]]);			
		}
	}
	for (int i = 1; i <= K; i++)
		ans = max(ans, memo[i]);
	cout << ans;
	return 0;
}