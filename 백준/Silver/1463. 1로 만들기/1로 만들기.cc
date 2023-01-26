#include <iostream>
using namespace std;

int N, temp;
int memo[1000001];

int main(void) {
	cin >> N;
	memo[2] = 1;
	memo[3] = 1;
	for (int i = 4; i <= N; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			temp = min(memo[i / 2], memo[i / 3]);
			temp = min(temp, memo[i - 1]);
		}
		else if (i % 3 == 0)
			temp = min(memo[i / 3], memo[i - 1]);
		else if (i % 2 == 0)
			temp = min(memo[i / 2], memo[i - 1]);
		else
			temp = memo[i - 1];
		memo[i] = temp + 1;	
	}
	cout << memo[N];
	return 0;
}