#include <iostream>
using namespace std;

int T, N;
string publicKey[1000];
int solve[1000];
string crypto[1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) cin >> publicKey[j];
		for (int j = 0; j < N; j++) {
			string temp;
			cin >> temp;
			for (int k = 0; k < N; k++) if (temp == publicKey[k]) solve[j] = k;			
		}
		for (int j = 0; j < N; j++) {
			string word;
			cin >> word;
			crypto[solve[j]] = word;
		}
		for (int j = 0; j < N; j++) cout << crypto[j] << " ";
		cout << "\n";
	}
	return 0;
}