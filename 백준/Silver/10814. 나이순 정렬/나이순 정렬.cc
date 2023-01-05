#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> arr[100001];
string name[100001];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
		cin >> name[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) cout << arr[i].first << " " << name[arr[i].second] << '\n';
	return 0;
}