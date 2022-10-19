#include <iostream>
#include <queue>
using namespace std;

int N, Dasom, people, ans;
priority_queue <int> pq;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Dasom;
	for (int i = 1; i < N; i++) {
		cin >> people;
		pq.push(people);
	}
	if (pq.size() == 0) {
		cout << 0;
		return 0;
	}
	while (Dasom <= pq.top()) {
		int temp = pq.top();
		pq.pop();
		Dasom++;
		pq.push(temp - 1);
		ans++;
	}
	cout << ans;
	return 0;
}
