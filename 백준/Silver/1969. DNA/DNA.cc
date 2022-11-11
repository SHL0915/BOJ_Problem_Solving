#include <iostream>
using namespace std;

int N, M, max_num;
string arr[1001];
int cnt[50][4];
string ans = "";
int sum;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < M; i++) {
		max_num = 0;
		int idx;
		for (int j = 0; j < N; j++) {
			switch (arr[j][i]) {
			case 'A': cnt[i][0]++; break;
			case 'C': cnt[i][1]++; break;
			case 'G': cnt[i][2]++; break;
			case 'T': cnt[i][3]++; break;
			}
		}
		for (int j = 0; j < 4; j++) {
			if (max_num < cnt[i][j]) {
				max_num = cnt[i][j];
				idx = j;
			}
		}
		sum += (N - max_num);
		switch (idx) {
		case 0: ans += 'A'; break;
		case 1: ans += 'C'; break;
		case 2: ans += 'G'; break;
		case 3: ans += 'T'; break;
		}		
	}
	cout << ans << '\n' << sum;
	return 0;
}