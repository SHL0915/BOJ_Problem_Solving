#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K, i, j, ans;
int use[100];
deque <int> tools[101];
vector <int> multitap;

bool cmp(int A, int B) {
	if (tools[A].size() == 0) return tools[A].size() != 0;
	else if (tools[B].size() == 0) return tools[B].size() == 0;
	return tools[A].front() < tools[B].front();
}

int main(void) {
	cin >> N >> K;
	for (i = 0; i < K; i++) {
		cin >> use[i];
		tools[use[i]].push_back(i);
	}
	for (i = 0; i < K; i++) {
		if (multitap.size() < N) {		
			for (j = 0; j < multitap.size(); j++) if (multitap[j] == use[i]) break;
			if (j == multitap.size()) multitap.push_back(use[i]);
		}
		else {		
			for (j = 0; j < N; j++) if (multitap[j] == use[i]) break;
			if (j == N) {
				multitap.pop_back();
				multitap.push_back(use[i]);
				ans++;
			}
		}
		tools[use[i]].pop_front();
		sort(multitap.begin(), multitap.end(), cmp);
	}
	cout << ans;
	return 0;
}