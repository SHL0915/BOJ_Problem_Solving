#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A, B, C;
vector <int> possible;
int mark[200][200][200];

void DFS(int arr[3]);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> C;
	int input[3] = { 0,0,C };
	DFS(input);
	sort(possible.begin(), possible.end());
	possible.erase(unique(possible.begin(), possible.end()), possible.end());
	for (int i = 0; i < possible.size(); i++) cout << possible[i] << ' ';
	return 0;
}

void DFS(int arr[3]) {
	if (mark[arr[0]][arr[1]][arr[2]] != 0) return;
	mark[arr[0]][arr[1]][arr[2]] = 1;
	if (arr[0] == 0) possible.push_back(arr[2]);
	int temp[3];
	if (arr[0] + arr[1] <= B) {
		temp[0] = 0;
		temp[1] = arr[0] + arr[1];
	}
	else {
		temp[0] = (arr[0] + arr[1]) - B;
		temp[1] = B;
	}
	temp[2] = arr[2];
	DFS(temp);
	if (arr[0] + arr[2] <= C) {
		temp[0] = 0;
		temp[2] = arr[0] + arr[2];
	}
	else {
		temp[0] = (arr[0] + arr[2]) - C;
		temp[2] = C;
	}
	temp[1] = arr[1];
	DFS(temp);
	if (arr[0] + arr[1] <= A) {
		temp[1] = 0;
		temp[0] = arr[0] + arr[1];
	}
	else {
		temp[1] = (arr[0] + arr[1]) - A;
		temp[0] = A;
	}
	temp[2] = arr[2];
	DFS(temp);
	if (arr[0] + arr[2] <= A) {
		temp[2] = 0;
		temp[0] = arr[0] + arr[2];
	}
	else {
		temp[2] = (arr[0] + arr[2]) - A;
		temp[0] = A;
	}
	temp[1] = arr[1];
	DFS(temp);
	if (arr[1] + arr[2] <= B) {
		temp[2] = 0;
		temp[1] = arr[1] + arr[2];
	}
	else {
		temp[2] = (arr[1] + arr[2]) - B;
		temp[1] = B;
	}
	temp[0] = arr[0];
	DFS(temp);
	if (arr[1] + arr[2] <= C) {
		temp[1] = 0;
		temp[2] = arr[1] + arr[2];
	}
	else {
		temp[1] = (arr[1] + arr[2]) - C;
		temp[2] = C;
	}
	temp[0] = arr[0];
	DFS(temp);
	return;
}