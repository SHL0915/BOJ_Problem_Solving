#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct DT {
	long long S, E, S2, E2, idx;
};

long long N, M;
vector <DT> line;
deque <DT> covered;

bool cmpByS(DT A, DT B) {
	if (A.S == B.S) return A.E > B.E;
	return A.S < B.S;
}

bool cmpByI(DT A, DT B) {
	return A.idx < B.idx;
}

bool check(DT A);
void eraseFront();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	line.resize(M);
	for (int i = 0; i < M; i++) {
		long long a, b;
		cin >> a >> b;
		if (a > b) line[i] = line[i] = { a, b + N, a + N, b + 2 * N, i + 1 };
		else line[i] = { a, b, a + N, b + N, i + 1 };
	}
	sort(line.begin(), line.end(), cmpByS);	
	for (int i = 0; i < M; i++) {
		if (covered.size() == 0) covered.push_back(line[i]);
		else if (check(line[i])) covered.push_back(line[i]);
		eraseFront();
	}
	sort(covered.begin(), covered.end(), cmpByI);
	for (int i = 0; i < covered.size(); i++) cout << covered[i].idx << " ";
	return 0;
}

bool check(DT A) {
	if (covered.back().S <= A.S && A.E <= covered.back().E) return false;
	else return true;
}

void eraseFront() {
	while (covered.size() >= 2) {
		if (covered.back().S <= covered.back().S2 && covered.back().E >= covered.front().E2) covered.pop_front();
		else return;
	}
}