#include <iostream>
#include <string>
using namespace std;

int N;
string name[100];
int mark[100];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; ; i++) {
		for (int j = 0; j < 100; j++) mark[j] = 0;
		cin >> N;
		if (N == 0) break;
		cin.ignore();
		for (int j = 0; j < N; j++) getline(cin, name[j]);		
		for (int j = 0; j < 2 * N - 1; j++) {
			int input;
			char a;
			cin >> input >> a;
			mark[input - 1] ++;
		}
		cout << i << " ";
		for (int j = 0; j < N; j++) {
			if (mark[j] == 1) {
				cout << name[j] << "\n";
				break;
			}
		}
	}
	return 0;
}