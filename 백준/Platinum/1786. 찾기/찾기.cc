#include <bits/stdc++.h>
using namespace std;

string T, P;
int tlen, plen;
int pi[1000000];
vector <int> ans;

void makePi();
void kmp();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  getline(cin,T);
  getline(cin,P);
  tlen = T.length();
  plen = P.length();
  makePi();
  kmp();
  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";  
  return 0;
}

void makePi(){
  int j = 0;
  for(int i = 1; i < plen; i++){
    while(j > 0 && P[i] != P[j]) j = pi[j-1];
    if(P[i] == P[j]) pi[i] = ++j;
  }
}

void kmp(){
  int j = 0;
  for(int i = 0; i < tlen; i++){
    while(j > 0 && T[i] != P[j]) j = pi[j - 1];
    if(T[i] == P[j]){
      if(j == plen - 1){
        ans.push_back(i - plen + 2);
        j = pi[j];
      }
      else j++;
    }
  }
}