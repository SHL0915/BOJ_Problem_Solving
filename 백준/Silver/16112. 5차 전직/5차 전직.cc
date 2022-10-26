#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
long long quest[300000];
long long ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> quest[i];
	sort(quest, quest + N);
	for (int i = 1; i < K; i++) ans += quest[i] * i;
	for (int i = K; i < N; i++) ans += quest[i] * K;
	cout << ans;
	return 0;
}