#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
pair<long long, long long> monkey[50];
long long result1[50][50];
long long result2[50][50];
long long ans = 1000000000000000LL, max1, max2;

long long absol(long long A) {
	if (A >= 0) return A;
	else return -1LL * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long x, y;
		cin >> x >> y;
		monkey[i] = { x,y };
	}	
	long long S = -1000000000LL;
	long long E = 1000000000LL;
	for (int i = 0; ; i++) {
		if (absol(S - E) <= 5) break;
		long long point1 = (2 * S + E) / 3;
		long long point2 = (S + 2 * E) / 3;	
		max1 = 0;
		max2 = 0;
		for (int j = 0; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (monkey[j].first == monkey[k].first) {
					result1[j][k] = absol(monkey[j].second - monkey[k].second);
					result2[j][k] = absol(monkey[j].second - monkey[k].second);
				}
				else {
					result1[j][k] = absol(monkey[j].second - point1) + absol(monkey[k].second - point1);
					result2[j][k] = absol(monkey[j].second - point2) + absol(monkey[k].second - point2);
				}
				result1[j][k] += absol(monkey[j].first - monkey[k].first);
				result2[j][k] += absol(monkey[j].first - monkey[k].first);
				max1 = max(max1, result1[j][k]);
				max2 = max(max2, result2[j][k]);
			}
		}
		if (max1 <= max2) E = point2;
		else S = point1;
	}
	for (int i = S; i <= E; i++) {
		max1 = 0;
		for (int j = 0; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (monkey[j].first == monkey[k].first) result1[j][k] = absol(monkey[j].second - monkey[k].second);
				else result1[j][k] = absol(monkey[j].second - i) + absol(monkey[k].second - i);					
				result1[j][k] += absol(monkey[j].first - monkey[k].first);				
				max1 = max(max1, result1[j][k]);
			}
		}
		ans = min(ans, max1);
	}
	cout << ans;
	return 0;
}