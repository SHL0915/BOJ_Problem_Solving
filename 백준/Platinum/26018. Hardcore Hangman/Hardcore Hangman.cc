#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int ans[10101];
string qry[7];


int main(void) {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
#endif
    for (int i=1;i<=26;i++){
        for (int j=1;j<=5;j++){
            if (i & (1 << (j - 1))){
                qry[j] += char('a' + i - 1);
            }
        }
    }
    for (int j=1;j<=5;j++){
        cout << "? " << qry[j] << endl;
        int cnt;cin>>cnt;
        while(cnt--){
            int x;cin>>x;
            ans[x] |= (1 << (j - 1));
        }
    }
    int i = 1;
    cout<<"! ";
    while (ans[i]){
        cout << char('a' + ans[i] - 1);
        i++;
    }
    cout<<endl;
    return 0;
}