#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct mon {
	int R, C;
	string S;
	int W, A, H, E;
};

struct item {
	int R, C;
	string T;
	string S;
	int n;
};

struct player {
	int LV, HP, ATT, DEF, EXP;
	int hp, att, def;
	int HR, RE, CO, EX, DX, HU, CU;
	int cnt;

	player() {
		LV = 1;
		HP = 20;
		ATT = 2;
		DEF = 2;
		EXP = 0;
		hp = 20;
		att = 2;
		def = 2;
		HR = 0;
		RE = 0;
		CO = 0;
		EX = 0;
		DX = 0;
		HU = 0;
		CU = 0;
		cnt = 0;
	}
};

int N, M, K, L, ans;
string arr[105];
string S, die;
vector <mon> m;
int mid[105][105];
vector <item> I;
int iid[105][105];
player p;


void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '&' || arr[i][j] == 'M') K++;
			if (arr[i][j] == 'B') L++;
		}
	}
	cin >> S;
	
	ans = -1;
	
	m.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> m[i].R >> m[i].C >> m[i].S >> m[i].W >> m[i].A >> m[i].H >> m[i].E;
		m[i].R--;
		m[i].C--;
		mid[m[i].R][m[i].C] = i;
	}
	I.resize(L);
	for (int i = 0; i < L; i++) {
		cin >> I[i].R >> I[i].C >> I[i].T;
		if (I[i].T == "W" || I[i].T == "A") cin >> I[i].n;
		else cin >> I[i].S;
		I[i].R--;
		I[i].C--;
		iid[I[i].R][I[i].C] = i;
	}

	pii now, org;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '@') {
				now = { i,j };
				arr[i][j] = '.';
			}
		}
	}

	org = now;

	int T = 0;
	
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'U') {
			now.first--;
			if (now.first < 0 || arr[now.first][now.second] == '#') now.first++;
		}
		else if (S[i] == 'D') {
			now.first++;
			if (now.first >= N || arr[now.first][now.second] == '#') now.first--;
		}
		else if (S[i] == 'L') {
			now.second--;
			if (now.second < 0 || arr[now.first][now.second] == '#') now.second++;
		}
		else if (S[i] == 'R') {
			now.second++;
			if (now.second >= M || arr[now.first][now.second] == '#') now.second--;
		}
		

		if (arr[now.first][now.second] == '.') {
			T++;
			continue;
		}
		else if (arr[now.first][now.second] == 'B') {
			int id = iid[now.first][now.second];

			item temp = I[id];			
			if (temp.T == "W") {
				p.ATT = p.att + temp.n;
			}
			else if (temp.T == "A") p.DEF = p.def + temp.n;
			else {
				if (p.cnt == 4);
				else {
					if (temp.S == "HR") {
						if (p.HR == 1);
						else {
							p.HR = 1;
							p.cnt++;
						}
					}
					else if (temp.S == "RE") {
						if (p.RE == 1);
						else {
							p.RE = 1;
							p.cnt++;
						}
					}
					else if (temp.S == "CO") {
						if (p.CO == 1);
						else {
							p.CO = 1;
							p.cnt++;
						}
					}
					else if (temp.S == "EX") {
						if (p.EX == 1);
						else {
							p.EX = 1;
							p.cnt++;
						}
					}
					else if (temp.S == "DX") {
						if (p.DX == 1);
						else {
							p.DX = 1;
							p.cnt++;
						}
					}
					else if (temp.S == "HU") {
						if (p.HU == 1);
						else {
							p.HU = 1;
							p.cnt++;
						}
					}
					else if (temp.S == "CU") {
						if (p.CU == 1);
						else {
							p.CU = 1;
							p.cnt++;
						}
					}
				}
			}
			arr[now.first][now.second] = '.';
			T++;
		}
		else if (arr[now.first][now.second] == '^') {
			if (p.DX == 1) p.HP -= 1;
			else p.HP -= 5;

			p.HP = max(p.HP, 0);

			if (p.HP == 0) {
				if (p.RE == 1) {
					now = org;
					p.RE = 0;
					p.cnt--;
					p.HP = p.hp;
				}
				else {
					ans = 0;
					die = "SPIKE TRAP";
					break;
				}
			}

			T++;
		}
		else if (arr[now.first][now.second] == '&') {
			int id = mid[now.first][now.second];

			int hp = p.HP, mhp = m[id].H;
						
			if (p.CO == 1) {
				if (p.DX == 1) mhp -= max(1, p.ATT * 3 - m[id].A);
				else mhp -= max(1, p.ATT * 2 - m[id].A);
				if (mhp <= 0) {
					if (p.HR == 1) p.HP = min(p.hp, 3 + p.HP);
					if (p.EX == 1) p.EXP += (int)(m[id].E * 1.2);				
					else p.EXP += m[id].E;

					if (p.EXP >= 5 * p.LV) {
						p.LV += 1;
						p.hp += 5;
						p.HP = p.hp;
						p.att += 2;
						p.ATT += 2;
						p.def += 2;
						p.DEF += 2;
						p.EXP = 0;
					}

					arr[now.first][now.second] = '.';
					T++;
					continue;
				}
			}
			else {
				mhp -= max(1, p.ATT - m[id].A);
				if (mhp <= 0) {
					if (p.HR == 1) p.HP = min(p.hp, 3 + p.HP);
					if (p.EX == 1) p.EXP += (int)(m[id].E * 1.2);
					else p.EXP += m[id].E;

					if (p.EXP >= 5 * p.LV) {
						p.LV += 1;
						p.hp += 5;
						p.HP = p.hp;
						p.att += 2;
						p.ATT += 2;
						p.def += 2;
						p.DEF += 2;
						p.EXP = 0;
					}

					arr[now.first][now.second] = '.';
					T++;
					continue;
				}
			}

			
			while (1) {
				
				hp -= max(1, m[id].W - p.DEF);
				if (hp <= 0) {
					if (p.RE == 1) {
						now = org;
						p.RE = 0;
						p.cnt--;
						p.HP = p.hp;
						T++;
						break;
					}
					else {
						ans = 0;
						p.HP = 0;
						die = m[id].S;
						break;
					}
				}
				
				mhp -= max(1, p.ATT - m[id].A);
				if (mhp <= 0) {
					p.HP = hp;

					if (p.HR == 1) p.HP = min(p.hp, 3 + p.HP);
					if (p.EX == 1) p.EXP += (int)(m[id].E * 1.2);
					else p.EXP += m[id].E;

					if (p.EXP >= 5 * p.LV) {
						p.LV += 1;
						p.hp += 5;
						p.HP = p.hp;
						p.att += 2;
						p.ATT += 2;
						p.def += 2;
						p.DEF += 2;
						p.EXP = 0;
					}

					arr[now.first][now.second] = '.';
					T++;
					break;
				}
				
			}

			if (ans == 0) break;
		}
		else {
			//
			int id = mid[now.first][now.second];

			int hp = p.HP, mhp = m[id].H;
			
			if (p.HU == 1) hp = p.hp;

			if (p.CO == 1) {
				if (p.DX == 1) mhp -= max(1, p.ATT * 3 - m[id].A);
				else mhp -= max(1, p.ATT * 2 - m[id].A);
				if (mhp <= 0) {
					if (p.HR == 1) p.HP = min(p.hp, 3 + p.HP);
					if (p.EX == 1) p.EXP += (int)(m[id].E * 1.2);
					else p.EXP += m[id].E;

					if (p.EXP >= 5 * p.LV) {
						p.LV += 1;
						p.hp += 5;
						p.HP = p.hp;
						p.att += 2;
						p.ATT += 2;
						p.def += 2;
						p.DEF += 2;
						p.EXP = 0;
					}

					arr[now.first][now.second] = '.';
					T++;
					ans = 1;
					break;
				}
			}
			else {
				mhp -= max(1, p.ATT - m[id].A);
				if (mhp <= 0) {
					if (p.HR == 1) p.HP = min(p.hp, 3 + p.HP);
					if (p.EX == 1) p.EXP += (int)(m[id].E * 1.2);
					else p.EXP += m[id].E;

					if (p.EXP >= 5 * p.LV) {
						p.LV += 1;
						p.hp += 5;
						p.HP = p.hp;
						p.att += 2;
						p.ATT += 2;
						p.def += 2;
						p.DEF += 2;
						p.EXP = 0;
					}

					arr[now.first][now.second] = '.';
					T++;
					ans = 1;
					break;
				}
			}
			
			int flag = 0, aa = 0;

			while (1) {

				if (p.HU == 1 && flag == 0) flag++;
				else {
					hp -= max(1, m[id].W - p.DEF);
					if (hp <= 0) {
						if (p.RE == 1) {
							now = org;
							p.RE = 0;
							p.cnt--;
							p.HP = p.hp;
							T++;
							aa = 1;
							break;
						}
						else {
							ans = 0;
							p.HP = 0;
							die = m[id].S;
							break;
						}
					}
				}				

				mhp -= max(1, p.ATT - m[id].A);
				if (mhp <= 0) {
					p.HP = hp;

					if (p.HR == 1) p.HP = min(p.hp, 3 + p.HP);
					if (p.EX == 1) p.EXP += (int)(m[id].E * 1.2);
					else p.EXP += m[id].E;

					if (p.EXP >= 5 * p.LV) {
						p.LV += 1;
						p.hp += 5;
						p.HP = p.hp;
						p.att += 2;
						p.ATT += 2;
						p.def += 2;
						p.DEF += 2;
						p.EXP = 0;
					}

					arr[now.first][now.second] = '.';
					T++;
					ans = 1;
					break;
				}
			}
			
			if (aa == 1) continue;
			else break;
		}
	}
		
	if (ans == 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) cout << arr[i][j];
			cout << '\n';
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (now.first == i && now.second == j) cout << "@";
				else cout << arr[i][j];
			}
			cout << '\n';
		}
	}

	if (ans == 0) T++;
	cout << "Passed Turns : " << T << '\n';
	cout << "LV : " << p.LV << '\n';
	cout << "HP : " << p.HP << "/" << p.hp << '\n';
	cout << "ATT : " << p.att << "+" << p.ATT - p.att << '\n';
	cout << "DEF : " << p.def << "+" << p.DEF - p.def << '\n';
	cout << "EXP : " << p.EXP << "/" << p.LV * 5 << '\n';

	if (ans == 0) cout << "YOU HAVE BEEN KILLED BY " << die << "..";
	else if (ans == 1) cout << "YOU WIN!";
	else cout << "Press any key to continue.";

	return;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}