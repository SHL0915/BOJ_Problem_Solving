#include <iostream>
#include <string>
using namespace std;

int N;
int cypher[100000];
int cypherCnt[53];
int orgCnt[53];
string org;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cypher[i];
		cypherCnt[cypher[i]]++;
	}
	cin.ignore();
	getline(cin,org);
	for (int i = 0; i < org.size(); i++) {
		if (org[i] == ' ') orgCnt[0]++;
		else if (org[i] >= 'A' && org[i] <= 'Z') orgCnt[org[i] - 'A' + 1] ++;
		else orgCnt[org[i] - 'a' + 27] ++;
	}
	for (int i = 0; i <= 52; i++) {
		if (orgCnt[i] != cypherCnt[i]) {
			cout << "n";
			return 0;
		}
	}
	cout << "y";
	return 0;
}