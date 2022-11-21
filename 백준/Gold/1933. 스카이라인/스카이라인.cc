#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N;
vector <pair<pair<int, int>, int>> building;
vector <int> coor;
priority_queue <pair<int, int>> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int L, H, R;
		cin >> L >> H >> R;
		building.push_back({ {L,R},H });
		coor.push_back(L);
		coor.push_back(R);
	}
	sort(coor.begin(), coor.end());
	coor.erase(unique(coor.begin(), coor.end()), coor.end());
	sort(building.begin(), building.end());
	int pos = 0;
	int h = 0;
	for (int i = 0; i < coor.size(); i++) {
		for (; pos < N; pos++) {
			if (building[pos].first.first <= coor[i]) pq.push({ building[pos].second, building[pos].first.second });
			else break;
		}
		while (pq.size()) {
			if (pq.top().second <= coor[i]) pq.pop();
			else break;
		}
		if (pq.size() == 0) {
			if (h != 0) {
				cout << coor[i] << " " << 0 << " ";
				h = 0;
			}
		}
		else if (pq.top().first != h) {
			cout << coor[i] << " " << pq.top().first << " ";
			h = pq.top().first;
		}	
	}
	return 0;
}