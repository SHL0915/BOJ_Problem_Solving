#include <iostream>
#include <algorithm>
using namespace std;

int triangles[6][3];
int mark[6];
int maxScore;
int hexagon[6][3]; // 0: 왼쪽, 1: 아래, 2: 오른쪽

void createHexagon(int k);

int main(void) {
	while (1) {
		maxScore = -1;		
		for (int i = 0; i < 6; i++) {
			cin >> triangles[i][0] >> triangles[i][1] >> triangles[i][2];
			mark[i] = 0;
		}		
		createHexagon(0);
		string s;
		cin >> s;
		if (maxScore == -1)
			cout << "none\n";
		else
			cout << maxScore << "\n";
		if (s[0] == '$')
			break;
	}
	return 0;
}

void createHexagon(int k) {
	int i, j, sum = 0;
	if (k == 6) {
		for (i = 1; i < 6; i++) {
			if (hexagon[i][0] != hexagon[i - 1][2])
				return;
		}
		if (hexagon[0][0] != hexagon[5][2])
			return;
		for (i = 0; i < 6; i++) {
			sum += hexagon[i][1];
		}
		maxScore = max(maxScore, sum);
		return;
	}
	else {
		for (i = 0; i < 6; i++) {
			if (mark[i] != 0)
				continue;
			mark[i] = 1;
			for (j = 0; j < 3; j++) {
				hexagon[k][0] = triangles[i][j % 3];
				hexagon[k][1] = triangles[i][(j + 1) % 3];
				hexagon[k][2] = triangles[i][(j + 2) % 3];
				createHexagon(k + 1);
			}
			mark[i] = 0;
		}
	}
}