#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N, M, case_num;
map <string, int> m;
double dist[31][31];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> N;
		if (N == 0) break;
		case_num++;
		double ans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) dist[i][j] = 1;
				else dist[i][j] = 0;
			}
		}
		for (int i = 1; i <= N; i++) {
			string s;
			cin >> s;
			m[s] = i;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			string A,B;
			double r;
			cin >> A >> r >> B;
			dist[m[A]][m[B]] = r;
		}
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
			}
		}
		for (int i = 1; i <= N; i++) ans = max(ans, dist[i][i]);		
		cout << "Case " << case_num << ": ";
		if (ans > 1) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}