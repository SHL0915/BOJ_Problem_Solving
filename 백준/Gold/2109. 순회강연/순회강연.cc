#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// priority_queue를 사용하지 않은 풀이

int N, ans;
int greedy[10001];
vector <pair <int, int>> lecture;

bool cmp(pair <int, int> A, pair <int, int> B) {
	return A.first < B.first;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int p, d;
		cin >> p >> d;
		lecture.push_back({ p, d });
	}
	sort(lecture.begin(), lecture.end(), cmp);
	while (lecture.size()) {
		for (int i = lecture.back().second; i >= 1; i--) {
			if (greedy[i] != 0) {
				if (i == 1) lecture.pop_back();
				else continue;
			}
			else {
				greedy[i] = lecture.back().first;
				lecture.pop_back();
				break;
			}
		}
	}
	for (int i = 1; i <= 10000; i++) ans += greedy[i];
	cout << ans;
	return 0;
}