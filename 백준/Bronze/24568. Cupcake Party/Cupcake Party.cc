#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A, B;
    cin >> A >> B;
    long long tot = A * 8 + B * 3;
    cout << tot - 28;
    return 0;
}