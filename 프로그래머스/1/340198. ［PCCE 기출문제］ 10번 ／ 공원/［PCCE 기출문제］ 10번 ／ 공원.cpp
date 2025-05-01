#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M;

bool check2(int y, int x, int len, vector<vector<string>> & park) {
    if (y + len > N || x + len > M) return false;
    
    int flag = 0;
    for(int i = y; i < y + len; i++) {
        for(int j = x; j < x + len; j++) {
            if(park[i][j] != "-1")
                flag = 1;
        }
    }
    
    if(flag == 0) return true;
    else return false;
}

bool check(int len, vector<vector<string>> & park) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(check2(i, j, len, park) == true)
                return true;
        }
    }
    
    return false;    
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    N = park.size();
    M = park[0].size();
    
    sort(mats.begin(), mats.end());
    
    for(int i = mats.size() - 1; i >= 0; i--) {
        if (check(mats[i], park) == true) {
            answer = mats[i];
            break;
        }
    }
    
    
    return answer;
}