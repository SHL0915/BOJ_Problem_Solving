#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef struct Qdata {
	int first, second, third;
}Qdata;

int A, B, C;
queue <Qdata> q;
int mark[1500][1500];

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> C;
	int arr[3] = { A,B,C };
	sort(arr, arr + 3);
	Qdata data = { A,B,C };
	q.push(data);
	while (q.size()) BFS();
	cout << 0;
	return 0;
}

void BFS() {
	Qdata temp = q.front();
	q.pop();
	if (temp.first * temp.second * temp.third == 0) return;
	if (temp.first == temp.second && temp.second == temp.third) {
		cout << 1;
		exit(0);
	}
	int arr[3] = { temp.first,temp.second,temp.third };
	sort(arr, arr + 3);
	if (mark[arr[0]][arr[2]] != 0) return;
	mark[arr[0]][arr[2]] = 1;
	q.push({ arr[0] + arr[0], arr[1] - arr[0], arr[2] });
	q.push({ arr[0] + arr[0], arr[1], arr[2] - arr[0] });
	q.push({ arr[0], arr[1] + arr[1], arr[2] - arr[1] });
	return;
}