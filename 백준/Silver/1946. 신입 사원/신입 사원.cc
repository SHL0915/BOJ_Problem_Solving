#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, temp;
vector <pair <int, int>> applicant;

bool cmp(pair <int, int > A, pair <int, int> B) {
	return A.first < B.first;
}

int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		int cnt = 0;
		cin >> N;
		applicant.resize(0);
		for (int j = 0; j < N; j++) {
			int paper, interview;
			cin >> paper >> interview;
			applicant.push_back({ paper, interview });
		}
		sort(applicant.begin(), applicant.end(), cmp);
		temp = N;
		for (int j = 0; j < N; j++) {
			if (applicant[j].second > temp) continue;
			else {
				temp = applicant[j].second;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}