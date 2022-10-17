#include <iostream>
#include <deque>
using namespace std;

int alph[26] = { 3,2,1,2,3,3,2,3,3,2,2,1,2,2,1,2,2,2,1,2,1,1,1,2,2,1 };
deque <int> chemistry;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string jongmin, her;
	cin >> jongmin >> her;
	for (int i = 0; i < jongmin.length(); i++) {
		chemistry.push_back(alph[jongmin[i] - 'A']);
		chemistry.push_back(alph[her[i] - 'A']);
	}	
	while (1) {
		if (chemistry.size() == 2) break;
		int temp = chemistry.size();
		for (int i = 0; i < temp - 1; i++) {
			chemistry.push_back((chemistry[0] + chemistry[1]) % 10);
			chemistry.pop_front();
		}
		chemistry.pop_front();		
	}
	for (int i = 0; i < 2; i++)
		cout << chemistry[i];
	return 0;
}