#include <iostream>
#include <algorithm>
using namespace std;

const long long INF = 1000000000000LL;

struct DT{
	long long x, y, type, idx;
};

int N;
DT cow[51];
long long result[51];

bool cmp(DT A, DT B) {
	return A.x > B.x;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		char type;
		int x, y;
		cin >> type >> x >> y;
		if (type == 'E') cow[i] = { x, y, 0, i };
		else cow[i] = { x, y, 1, i };
		result[i] = INF;
	}
	sort(cow, cow + N, cmp);
	for (int i = 0; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (cow[i].type == 0 && cow[j].type == 1) {
				if (cow[j].y > cow[i].y) continue;
				else {
					if (cow[i].y - cow[j].y < cow[j].x - cow[i].x) {
						if (result[cow[j].idx] >= cow[i].y - cow[j].y) {
							result[cow[i].idx] = cow[j].x - cow[i].x;
							break;
						}						
					}
					else if (cow[i].y - cow[j].y == cow[j].x - cow[i].x) continue;
					else result[cow[j].idx] = min(result[cow[j].idx], cow[i].y - cow[j].y);
				}
			}			
		}
	}
	for (int i = 0; i < N; i++) {
		if (result[i] == INF) cout << "Infinity\n";
		else cout << result[i] << '\n';
	}
	return 0;
}