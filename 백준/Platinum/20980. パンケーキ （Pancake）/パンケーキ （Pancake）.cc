#include <iostream>
#include <queue>
using namespace std;

int N, Q;
int mark[5000000];
string input;
queue <pair<int, int>> q;

int StoI(string S);
string ItoS(int n);
void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin >> N >> Q;
	for (int i = 0; i < 5000000; i++) mark[i] = -1;
	for (int i = 0; i <= N; i++) { 
		for (int j = 0; j <= N - i; j++) {
			string temp = "";
			for (int k = 0; k < i; k++) temp += 'A';
			for (int k = 0; k < j; k++) temp += 'B';
			for (int k = 0; k < N - i - j; k++) temp += 'C';
			q.push({ StoI(temp),0 });
			while (q.size()) BFS();
		}
	}
	while (Q--) {
		cin >> input;
		cout << mark[StoI(input)] << '\n';
	}
	return 0;
}

int StoI(string S) {
	int result = 0;
	int A = 0;
	int B = 1;
	int C = 2;
	int degree = 1;
	for (int i = S.length() - 1; i >= 0; i--) {
		if (S[i] == 'A') result += (A * degree);
		else if (S[i] == 'B') result += (B * degree);
		else result += (C * degree);
		degree *= 3;
	}
	return result;
}

string ItoS(int n) {
	string result = "";
	for (int i = 0; i < N; i++) {		
		if ((n % 3) == 0) result = 'A' + result;
		else if ((n % 3) == 1) result = 'B' + result;
		else if ((n % 3) == 2) result = 'C' + result;
		n /= 3;
	}	
	return result;
}

void BFS() {
	pair<int, int> temp = q.front();
	q.pop();
	int now = temp.first;
	int d = temp.second;
	if (mark[now] != -1) return;
	mark[now] = d;	
	string A = ItoS(now);
	for (int i = 1; i < A.length(); i++) {
		string newS = "";
		for (int j = i; j >= 0; j--) newS += A[j];
		for (int j = i + 1; j < A.length(); j++) newS += A[j];
		q.push({ StoI(newS), d + 1 });
	}
	return;
}