#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector <pair<int, string>> title;
int power[100000];

void BinarySearch(int left, int right, int data);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int A;
		string B;
		cin >> B >> A;
		title.push_back({ A, B });
	}
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		BinarySearch(0, N - 1, input);
	}
	return 0;
}

void BinarySearch(int left, int right, int data) {
	int mid = (left + right) / 2;
	if (left < right) {
		if (data > title[mid].first) return BinarySearch(mid + 1, right, data);
		else return BinarySearch(left, mid, data);
	}
	else {
		cout << title[mid].second << '\n';
		return;
	}
}