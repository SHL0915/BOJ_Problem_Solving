#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1234567890;

int N, K, cnt, ans;
vector <int> arr;
deque <int> tool[500001];
int mark[500001];
priority_queue <pair<int, int>> multitap;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	arr.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		tool[arr[i]].push_back(i);
	}
	for (int i = 1; i <= K; i++) tool[i].push_back(INF);
	for (int i = 0; i < K; i++) {
		tool[arr[i]].pop_front();
		if (mark[arr[i]] == 1) {
			multitap.push({ tool[arr[i]].front(), arr[i] });
			continue;
		}
		if (cnt < N) {
			multitap.push({ tool[arr[i]].front(), arr[i] });
			mark[arr[i]] = 1;
			cnt++;
		}
		else {
			mark[multitap.top().second] = 0;
			multitap.pop();
			multitap.push({ tool[arr[i]].front(), arr[i] });
			mark[arr[i]] = 1;
			ans++;
		}
	}
	cout << ans;
	return 0;
}