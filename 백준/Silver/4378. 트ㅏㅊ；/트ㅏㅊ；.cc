#include <iostream>
#include <string>
using namespace std;

string input, result;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (getline(cin, input)) {
		result = "";
		for (int i = 0; i < input.size(); i++) {
			switch (input[i]) {
			case 'W': result += 'Q'; break;
			case 'E': result += 'W'; break;
			case 'R': result += 'E'; break;
			case 'T': result += 'R'; break;
			case 'Y': result += 'T'; break;
			case 'U': result += 'Y'; break;
			case 'I': result += 'U'; break;
			case 'O': result += 'I'; break;
			case 'P': result += 'O'; break;
			case '[': result += 'P'; break;
			case ']': result += '['; break;
			case '\\': result += ']'; break;
			case '1': result += '`'; break;
			case '2': result += '1'; break;
			case '3': result += '2'; break;
			case '4': result += '3'; break;
			case '5': result += '4'; break;
			case '6': result += '5'; break;
			case '7': result += '6'; break;
			case '8': result += '7'; break;
			case '9': result += '8'; break;
			case '0': result += '9'; break;
			case '-': result += '0'; break;
			case '=': result += '-'; break;
			case 'S': result += 'A'; break;
			case 'D': result += 'S'; break;
			case 'F': result += 'D'; break;
			case 'G': result += 'F'; break;
			case 'H': result += 'G'; break;
			case 'J': result += 'H'; break;
			case 'K': result += 'J'; break;
			case 'L': result += 'K'; break;
			case ';': result += 'L'; break;
			case '\'': result += ';'; break;
			case 'X': result += 'Z'; break;
			case 'C': result += 'X'; break;
			case 'V': result += 'C'; break;
			case 'B': result += 'V'; break;
			case 'N': result += 'B'; break;
			case 'M': result += 'N'; break;
			case ',': result += 'M'; break;
			case '.': result += ','; break;
			case '/': result += '.'; break;
			default: result += input[i];
			}
		}
		cout << result << '\n';
	}
	return 0;
}