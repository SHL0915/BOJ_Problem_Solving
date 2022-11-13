#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
string input;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> input;
		vector <int> arr;
		for (int i = 0; i < input.length(); i++) arr.push_back(input[i] - 'A');
		if (next_permutation(arr.begin(), arr.end()) == false) cout << input << '\n';
		else {
			for (int i = 0; i < arr.size(); i++) cout << (char)(arr[i] + 'A');
			cout << '\n';
		}
	}
	return 0;
}