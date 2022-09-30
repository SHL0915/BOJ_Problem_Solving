#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans = - 101;
int paper[12][12];
vector <int> row, column;

void BackTracking(int len, vector<int> prev_state, bool dir);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
			ans = max(ans, paper[i][j]);
		}
	}		
	vector <int> org(12); // 가장 초기의 state
	for (int i = 0; i < N; i++) 
		org[i] = (1 << i);
	BackTracking(N, org, true);	
	for (int i = 0; i < M; i++)
		org[i] = (1 << i);
	BackTracking(M, org, false);

	sort(column.begin(), column.end());
	column.erase(unique(column.begin(), column.end()), column.end());
	sort(row.begin(), row.end());
	row.erase(unique(row.begin(), row.end()), row.end());
	
	for (int i = 0; i < column.size(); i++) { // 세로를 먼저 접는다
		vector <int> temp(12); // 각 가로줄에 대한 정보를 저장
		for (int j = 0; j < N; j++) {
			if (column[i] & (1 << j)) { // 접힘의 결과로 두 행이 서로 겹친다면
				for (int k = 0; k < M; k++) { // 모든 가로에 대하여 값을 더해준다
					temp[k] += paper[j][k];
				}
			}				
		}
		for (int j = 0; j < row.size(); j++) { // 접힌 세로에 대해서 가로를 접는다
			int result = 0;
			for (int k = 0; k < M; k++) { // 어떠한 가로열에 대해서,
				if (row[j] & (1 << k)) { // 접힘의 결과로 두 열이 서로 겹친다면
					result += temp[k]; // 최종 접힘의 결과는 그 가로열을 모두 더해준 것이다
				}
			}
			ans = max(ans, result);
		}
	}
	cout << ans;
	return 0;
}

void BackTracking(int len, vector<int> prev_state, bool dir) {
	if (dir == true) {
		for (int i = 0; i < len; i++)
			column.push_back(prev_state[i]); // 겹쳐진 종이의 값만 중요하므로 각 칸의 상태만 전달
	}
	else {
		for (int i = 0; i < len; i++)
			row.push_back(prev_state[i]);
	}	
	for (int i = 1; i < len; i++) { // 접을 위치를 선택, 접지 않는 경우는 이미 고려했으므로 1부터 시작
		int newlen = max(i, len - i); // 접힌 뒤 총 길이
		vector <int> now(newlen); 
		if (newlen > i) {
			for (int j = 0; j < newlen; j++) {
				if(j < i) now[j] = prev_state[i - j - 1] | prev_state[i + j];
				else now[j] = prev_state[i + j];
			}
		}
		else {
			for (int j = 0; j < newlen; j++) {
				if (j < len - i) now[j] = prev_state[newlen - j - 1] | prev_state[newlen + j];
				else now[j] = prev_state[newlen - 1 - j];
			}
		}
		BackTracking(newlen, now, dir);
	}
	return;
}