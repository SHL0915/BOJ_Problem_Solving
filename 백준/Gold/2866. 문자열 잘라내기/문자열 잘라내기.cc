#include <iostream>
#include <set>

using namespace std;

int main() {
    int R, C, mid;
    bool flag;
    string temp;
    string Table[1001];
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        cin >> Table[i];
    }
    int start = 1, end = R;
    while (start <= end) {
        mid = (start + end) / 2;
        flag = true;
        set<string> s;       
        for (int i = 0; i < C; i++) {
            temp = "";
            for (int j = mid; j <= R; j++) 
                temp += Table[j][i];
            if (s.find(temp) == s.end())
                s.insert(temp);
            else {
                flag = false;
                break;
            }
        }
        if (flag)
            start = mid + 1;        
        else 
            end = mid - 1;        
    }
    cout << start - 2;
}