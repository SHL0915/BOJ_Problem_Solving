#include <iostream>
using namespace std;

int j_money, s_money;
int j_stock, s_stock;
int d_num, i_num;
int val[14];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> j_money;
	s_money = j_money;
	for (int i = 0; i < 14; i++) {
		cin >> val[i];
		j_stock += j_money / val[i];
		j_money = j_money % val[i];
		if (i > 0) {
			if (val[i] > val[i - 1]) {
				i_num++;
				d_num = 0;
			}
			else if (val[i] < val[i - 1]) {
				d_num++;
				i_num = 0;
			}
			else {
				i_num = 0;
				d_num = 0;
			}
			if (i_num >= 3) {
				s_money += (s_stock * val[i]);
				s_stock = 0;
			}
			else if (d_num >= 3) {
				s_stock += (s_money / val[i]);
				s_money %= val[i];
			}
		}
	}
	j_money += (j_stock * val[13]);
	s_money += (s_stock * val[13]);
	if (j_money > s_money) cout << "BNP";
	else if (s_money > j_money) cout << "TIMING";
	else cout << "SAMESAME";
	return 0;
}