#include <iostream>
using namespace std;

int switchNum, studentNum;
int Switch[101];
int Student[100][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin >> switchNum;
	for (int i = 1; i <= switchNum; i++) cin >> Switch[i];
	cin >> studentNum;
	for (int i = 0; i < studentNum; i++) cin >> Student[i][0] >> Student[i][1];
	for (int i = 0; i < studentNum; i++) {
		if (Student[i][0] == 1) {
			for (int j = Student[i][1]; j <= switchNum; j += Student[i][1]) {
				Switch[j]++;
				Switch[j] %= 2;
			}
		}
		else {
			Switch[Student[i][1]]++;
			Switch[Student[i][1]] %= 2;
			for (int j = 0; ; j++) {
				if (Student[i][1] - j <= 0 || Student[i][1] + j > switchNum) break;
				if (Switch[Student[i][1] - j] == Switch[Student[i][1] + j]) {
					Switch[Student[i][1] - j]++;
					Switch[Student[i][1] - j] %= 2;
					Switch[Student[i][1] + j]++;
					Switch[Student[i][1] + j] %= 2;
				}
				else break;
			}
		}
	}
	for (int i = 1; i <= switchNum; i++) {
		if (i >= 20 && i % 20 == 0) cout << Switch[i] << "\n";
		else cout << Switch[i] << " ";
	}
	return 0;
}