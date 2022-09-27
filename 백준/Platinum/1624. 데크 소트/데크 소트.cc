#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N, dqNum = 0, temp;
int org[1000];
int dq[1000][2];
deque<pair<int, int>> ordered;

bool cmp1(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first)
		return A.second > B.second;
	else
		return A.first < B.first;
}

bool cmp2(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first)
		return A.second < B.second;
	else
		return A.first < B.first;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> org[i];
		ordered.push_back({ org[i],i });
	}
	sort(ordered.begin(), ordered.end(), cmp1);	
	while (ordered.size()) {	
		if (dqNum == 0) {
			dq[dqNum][0] = ordered.front().second;
			dq[dqNum][1] = 0; // 감소
			ordered.pop_front();
			dqNum++;
			continue;
		}
		if (dq[dqNum - 1][1] == 0) { // 감소 상태
			if (ordered.front().second < dq[dqNum - 1][0]) { // front의 인덱스가 데크의 뒤보다 작을 때
				dq[dqNum - 1][0] = ordered.front().second;
				ordered.pop_front();
				continue;
			}
			else { // front의 인덱스가 데크의 뒤보다 클 때
				if (ordered.size() == 1)
					break;
				else if (ordered[0].first == ordered[1].first) {
					dq[dqNum - 1][1] = 1;
					dq[dqNum - 1][0] = ordered[0].second;
					temp = ordered[0].first;
					while (ordered.size()) {
						if (ordered.front().first == temp)
							ordered.pop_front();
						else
							break;
					}
					sort(ordered.begin(), ordered.end(), cmp2);
					continue;
				}
				else {
					dq[dqNum - 1][1] = 1; // 증가로 변경
					sort(ordered.begin(), ordered.end(), cmp2);
					continue;
				}							
			}
		}
		else { // 증가 상태
			if (ordered.front().second > dq[dqNum - 1][0]) {
				dq[dqNum - 1][0] = ordered.front().second;
				ordered.pop_front();
				continue;
			}
			else {
				if (ordered.size() == 1) {
					dqNum++;
					break;
				}
				else if (ordered[0].first == ordered[1].first) {
					dq[dqNum][0] = ordered.front().second;
					dq[dqNum][1] = 0; // 감소
					temp = ordered[0].first;
					while (ordered.size()) {
						if (ordered.front().first == temp)
							ordered.pop_front();
						else
							break;
					}			
					dqNum++;
					sort(ordered.begin(), ordered.end(), cmp1);
					continue;
				}
				else {
					sort(ordered.begin(), ordered.end(), cmp1);
					dq[dqNum][0] = ordered.front().second;
					dq[dqNum][1] = 0; // 감소
					ordered.pop_front();
					dqNum++;
					continue;					
				}
			}
		}
	}
	cout << dqNum;
	return 0;
}