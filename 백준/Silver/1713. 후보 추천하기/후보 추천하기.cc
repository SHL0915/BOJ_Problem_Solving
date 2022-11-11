#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DT {
	int cnt, t, idx;
};

int N, M;
vector <DT> picture;

bool cmp(DT A, DT B) {
	if (A.cnt == B.cnt) return A.t > B.t;
	return A.cnt > B.cnt;
}

bool cmpByI(DT A, DT B) {
	return A.idx < B.idx;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, flag = 0;
		cin >> A;
		for (int i = 0; i < picture.size(); i++) {
			if (picture[i].idx == A) {
				picture[i].cnt++;
				flag = 1;
			}
		}
		sort(picture.begin(), picture.end(), cmp);
		if (flag == 1) continue;
		if (picture.size() < N) picture.push_back({ 0,i,A });
		else {
			picture.pop_back();
			picture.push_back({ 0,i,A });
		}
		sort(picture.begin(), picture.end(), cmp);		
	}
	sort(picture.begin(), picture.end(), cmpByI);
	for (int i = 0; i < picture.size(); i++) cout << picture[i].idx << " ";
	return 0;
}