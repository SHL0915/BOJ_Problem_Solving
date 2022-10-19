#include <iostream>
#include <string>
using namespace std;

int N;
string options[30];
string str[30];
int shortcut[30];
int Alph[26];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	string temp;
	getline(cin, temp);
	for (int i = 0; i < 30; i++) shortcut[i] = -1;
	for (int i = 0; i < N; i++) {
		int flag = 0;
		getline(cin, options[i]);
		str[i] = options[i];
		for (int j = 0; j < str[i].size(); j++) {
			if (str[i][j] == ' ') continue;
			else if (str[i][j] >= 'A' && str[i][j] <= 'Z') str[i][j] = 'a' + str[i][j] - 'A';
		}
		for (int j = 0; j < str[i].size(); j++) {
			if (j == 0) {
				if (Alph[str[i][j] - 'a'] == 0) {
					Alph[str[i][j] - 'a'] = 1;
					shortcut[i] = j;
					flag = 1;
					break;
				}
			}
			else if (str[i][j - 1] == ' ') {
				if (Alph[str[i][j] - 'a'] == 0) {
					Alph[str[i][j] - 'a'] = 1;
					shortcut[i] = j;
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) {
			for (int j = 0; j < str[i].size(); j++) {
				if (str[i][j] != ' ') {
					if (Alph[str[i][j] - 'a'] == 0) {
						Alph[str[i][j] - 'a'] = 1;
						shortcut[i] = j;					
						break;
					}
				}
			}
		}
		for (int j = 0; j < options[i].size(); j++) {
			if (j == shortcut[i]) cout << '[' << options[i][j] << ']';
			else cout << options[i][j];			
		}
		cout << '\n';
	}
	return 0;
}