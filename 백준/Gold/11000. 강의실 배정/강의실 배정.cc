#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, cnt;
vector <pair <int, int>> classes;

bool cmp(pair <int, int> A, pair <int, int> B) {
	if (A.first == B.first) return A.second < B.second;
	return A.first < B.first;
}

struct lower {
	bool operator() (int A, int B) {
		return A > B;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue <int, vector <int>, lower> pq;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int S, T;
		cin >> S >> T;
		classes.push_back({ S,T });
	}
	sort(classes.begin(), classes.end(), cmp);
	for (int i = 0; i < N; i++) {
		if (pq.size() == 0) pq.push(classes[i].second);
		else {
			if (classes[i].first >= pq.top()) pq.pop();
			pq.push(classes[i].second);
		}
	}
	cout << pq.size();
	return 0;
}