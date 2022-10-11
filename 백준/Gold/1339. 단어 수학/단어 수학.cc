#include <iostream>
using namespace std;

int N, num = 9, ans;
string word[10];
int Alphabet[26];
int cnt[26];

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> word[i];
	for (int i = 0; i < 26; i++) Alphabet[i] = -1;
	int temp = 10000000;
	for (int i = 0; i < 8; i++) {		
		for (int j = 0; j < N; j++) {
			if (word[j].length() < 8 - i) continue;	
			cnt[word[j][word[j].length() - (8 - i)] - 'A'] += temp;
		}
		temp /= 10;
	}
	while (1) {
		int index = 0, sum = 0;
		for (int i = 0; i < 26; i++) {			
			if (cnt[index] < cnt[i]) index = i;
			sum += cnt[i];
		}
		if (sum == 0) break;
		Alphabet[index] = num--;
		cnt[index] = 0;
	}
	temp = 10000000;
	for (int i = 0; i < 8; i++) {			
		for (int j = 0; j < N; j++) {
			if (word[j].length() < 8 - i) continue;
			ans += temp * Alphabet[word[j][word[j].length() - (8 - i)] - 'A'];
		}
		temp /= 10;
	}
	cout << ans;
	return 0;
}