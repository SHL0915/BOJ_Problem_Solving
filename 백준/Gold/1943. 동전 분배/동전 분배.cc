#include <bits/stdc++.h>

using namespace std;


int n;
int x[101];
int c[101];
int dp[101010];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;tc=3;
    while(tc--){
        for (auto &i: dp) i = false;
        cin>>n;
        int s=0;
        for (int i=1;i<=n;i++){
            cin>>x[i]>>c[i];
            s+=x[i]*c[i];
        }
        if (s&1){
            cout<<"0\n";
            continue;
        }
        dp[0] = 0;
        fill(dp+1,dp+100000+1,1000000);
        for (int i=1;i<=n;i++){
            for (int j=0;j<=100000;j++){
                if (dp[j]==1000000) continue;
                if (dp[j] < c[i] && j + x[i] <= 100000 && dp[j + x[i]] == 1000000){
                    dp[j + x[i]] = dp[j] + 1;
                }
                dp[j] = 0;
            }
        }
        cout<<(dp[s>>1]<1000000)<<'\n';
    }

    return 0;
}
