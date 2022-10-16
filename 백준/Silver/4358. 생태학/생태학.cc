#include <iostream>
#include <string>
#include <map>
using namespace std;

int num;
string tree;
map <string, int> trees;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed;
	cout.precision(4);
	while (getline(cin,tree)) {
		if (trees.count(tree)) (*trees.find(tree)).second++;
		else trees.insert({ tree, 1 });
		num++;
	}
	for (map <string, int> ::iterator i = trees.begin(); i != trees.end(); i++) {
		cout << (*i).first << " ";
		cout << (*i).second * 100 / (double)num << "\n";
	}
	return 0;
}