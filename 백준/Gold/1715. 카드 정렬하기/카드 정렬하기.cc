#include <iostream>
#include <queue>
using namespace std;

int N, ans;

struct lower {
	bool operator() (int A, int B) {
		return A > B;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	priority_queue <int, vector<int>, lower> pq;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		pq.push(input);
	}
	while (pq.size() != 1) {
		int temp = pq.top();
		pq.pop();
		temp += pq.top();
		ans += temp;
		pq.pop();
		pq.push(temp);
	}
	cout << ans;
	return 0;
}