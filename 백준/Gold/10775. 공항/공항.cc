#include <bits/stdc++.h>
using namespace std;

int G, P;
int arr[100000];
int parent[100001];

int Find(int node);
void Union(int A, int B);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> G >> P;
	for (int i = 0; i <= G; i++) parent[i] = i;
	for (int i = 0; i < P; i++) {
		int A;
		cin >> A;
		int capacity = Find(A);
		if (capacity == 0) {
			cout << i;
			return 0;
		}
		Union(capacity, capacity - 1);
	}
	cout << P;
	return 0;
}

int Find(int node) {
	if (parent[node] == node) return parent[node];
	else return parent[node] = Find(parent[node]);
}

void Union(int A, int B) {
	A = Find(A);
	B = Find(B);
	if (A == B) return;
	if (A > B) parent[A] = B;
	else parent[B] = A;
	return;
}