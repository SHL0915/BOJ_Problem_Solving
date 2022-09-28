#include <iostream>
using namespace std;

string first, second, result;
int AlphNum = 0;
int mark[10] = { 0 };
int Alphabet[26] = { 0 };
int AlphIndex[10];

void ChooseNum(int k);
bool Judge();

int main(void) {
	cin >> first >> second >> result;
	for (int i = 0; i < first.size(); i++){
		if (Alphabet[first[i] - 'A'] == 0) {
			AlphIndex[AlphNum++] = first[i] - 'A';
			Alphabet[first[i] - 'A'] = 1;
		}
	}
	for (int i = 0; i < second.size(); i++) {
		if (Alphabet[second[i] - 'A'] == 0) {
			AlphIndex[AlphNum++] = second[i] - 'A';
			Alphabet[second[i] - 'A'] = 1;
		}
	}
	for (int i = 0; i < result.size(); i++) {
		if (Alphabet[result[i] - 'A'] == 0) {
			AlphIndex[AlphNum++] = result[i] - 'A';
			Alphabet[result[i] - 'A'] = 1;
		}
	}
	ChooseNum(0);
	cout << "NO";
	return 0;	
}

void ChooseNum(int k) {
	if (k == AlphNum) {
		if (Judge() == true) {
			cout << "YES";
			exit(0);
		}
		return;
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (mark[i] == 0) {
				mark[i] = 1;
				Alphabet[AlphIndex[k]] = i;
				ChooseNum(k + 1);
				mark[i] = 0;
			}
		}
	}
}

bool Judge() {
	int first_num = 0, second_num = 0, result_num = 0, temp;
	temp = 1;
	for (int i = first.size() - 1; i >= 0; i--) {
		first_num += temp * Alphabet[first[i] - 'A'];
		temp *= 10;
	}
	temp = 1;
	for (int i = second.size() - 1; i >= 0; i--) {
		second_num += temp * Alphabet[second[i] - 'A'];
		temp *= 10;
	}
	temp = 1;
	for (int i = result.size() - 1; i >= 0; i--) {
		result_num += temp * Alphabet[result[i] - 'A'];
		temp *= 10;
	}
	if (first_num + second_num == result_num)
		return true;
	else
		return false;
}