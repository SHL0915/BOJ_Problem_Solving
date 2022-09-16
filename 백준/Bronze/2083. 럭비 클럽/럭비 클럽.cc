#include <iostream>
using namespace std;

int main(void) {
	char name[11];
	int age, weight;
	while (1) {
		cin >> name >> age >> weight;
		if (name[0] == '#')
			break;
		if (age > 17 || weight >= 80)
			cout << name << " Senior" << endl;
		else
			cout << name << " Junior" << endl;
	}
	return 0;
}
