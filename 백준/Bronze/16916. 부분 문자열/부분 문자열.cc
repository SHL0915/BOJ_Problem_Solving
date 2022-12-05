#include <bits/stdc++.h>
using namespace std;

string S, P;
int slen, plen;
int pi[1000000];
vector <int> ans;

void kmp();
void makePi();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> S >> P;
  slen = S.length();
  plen = P.length();
  makePi();
  kmp();
  if(ans.size() == 0) cout << 0;
  else cout << 1;
  return 0;
}

void kmp(){
  int j = 0;
  for(int i = 0; i < slen; i++){
    while(j > 0 && S[i] != P[j]) {
      j = pi[j - 1];
    }
    if(S[i] == P[j]){
      if(j == plen-1){
        ans.push_back(i - plen + 1);
        j = pi[j];
      }
      else j++;
    }
  }
}

void makePi(){
  int j = 0;
  for(int i = 1; i < plen; i++){
    while(j > 0 && P[i] != P[j]) j = pi[j-1];
    if(P[i] == P[j]) pi[i] = ++j;
  }
}