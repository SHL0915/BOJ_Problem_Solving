#include <iostream>
#include <queue>
using namespace std;

struct pqdata {
	int val, index;
};
struct cmp {
	bool operator()(pqdata a, pqdata b) {
		return a.val > b.val;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<pqdata, deque<pqdata>, cmp> q;
	int N, L, data;
	cin >> N >> L;		
	for (int i = 0; i < N; i++) {
		cin >> data;
		q.push({ data, i });
		if(i >= L)
			while (q.top().index <= i - L) q.pop();
		cout << q.top().val << " ";
	}
	return 0;
}