#include <iostream>
using namespace std;

int N;
int S[100];
int DPTable[2000000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		DPTable[S[i]] = 1;
	}
	for (int i = 0; i <= (S[N - 1] + S[N - 2]); i++) {
		for (int j = 0; j < N; j++) {
			if (S[j] >= i) break;
			else if (DPTable[i] != 0) DPTable[i] = min(DPTable[i], DPTable[i - S[j]] + 1);
			else DPTable[i] = DPTable[i - S[j]] + 1;
		}
	}
	for (int i = 0; i <= S[N - 1] + S[N - 2]; i++) {
		int temp = i;
		int cnt = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (temp < S[j]) continue;
			else {
				cnt += temp / S[j];
				temp %= S[j];
			}
		}
		if (DPTable[i] != cnt) {
			cout << "non-canonical";
			exit(0);
		}
	}	
	cout << "canonical";	
	return 0;
}