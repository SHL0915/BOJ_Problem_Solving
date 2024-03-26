# [Silver V] 카약과 강풍 - 2891 

[문제 링크](https://www.acmicpc.net/problem/2891) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

그리디 알고리즘, 구현

### 제출 일자

2024년 3월 26일 19:07:48

### 문제 설명

<p>As you know, a kayaking competition is going on as we speak. Unfortunately strong winds have damaged a few kayaks, and the race starts in 5 minutes!. Fortunately, some teams have brought reserve kayaks. Since kayaks are bulky and hard to carry, teams are willing to lend kayaks to opposing teams if and only if they are starting immediately next to them. For example, team with the starting number 4 will lend its reserve kayak only to teams 3 and 5. Of course if some team did bring a reserve and its' kayak was damaged, they will use it themselves and not lend it to anyone.</p>

<p>You as the organizer now need to know, what is the minimal number of teams that cannot start the race, not even in borrowed kayaks.</p>

### 입력 

 <p>The first line of input contains three integers N, (2 ≤ N ≤ 10), total number of teams, S, (1 ≤ S ≤ N), number of teams with damaged kayaks and R, (1 ≤ R ≤ N), number fo teams with reserve kayaks.</p>

<p>The second line contains exactly S numbers, the starting numbers of teams with damaged kayaks. The second line will not contain duplicates.</p>

<p>The third line contains exactly R numbers, the starting numbers of teams with reserve kayaks. The third line will not contain duplicates.</p>

### 출력 

 <p>The first and only line of output should contain the smallest number of teams that cannot start the competition.</p>

