#include <bits/stdc++.h>
using namespace std;

string A, B;
int alen, blen, cnt;
int pi[100000];

void makePi();
void kmp();

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B;
  A += A;
  alen = A.length();
  blen = B.length();
  makePi();
  kmp();
  cout << cnt;  
  return 0;
}

void makePi(){
  int j = 0;
  for(int i = 1; i < blen; i++){
    while(j > 0 && B[i] != B[j]) j = pi[j-1];
    if(B[i] == B[j]) pi[i] = ++j;
  }
}

void kmp(){
  int j = 0;
  for(int i = 0; i < alen - 1; i++){
    while(j > 0 && A[i] != B[j]) j = pi[j-1];
    if(A[i] == B[j]){
      if(j == blen-1){
        cnt++;
        j = pi[j];
      }
      else j++;
    }
  }
}