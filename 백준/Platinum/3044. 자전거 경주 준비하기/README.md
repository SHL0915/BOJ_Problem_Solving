# [Platinum IV] 자전거 경주 준비하기 - 3044 

[문제 링크](https://www.acmicpc.net/problem/3044) 

### 성능 요약

메모리: 5132 KB, 시간: 28 ms

### 분류

깊이 우선 탐색, 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 위상 정렬

### 문제 설명

<p>A bicycle race is being organized in a land far, far away. There are N town in the land, numbered 1 through N. There are also M one-way roads between the towns. The race will start in town 1 and end in town 2. </p>

<p>How many different ways can the route be set? Two routes are considered different if they do not use the exact same roads. </p>

### 입력 

 <p>The first line of input contains two integers N and M (1 ≤ N ≤ 10 000, 1 ≤ M ≤ 100 000), the number of towns and roads. </p>

<p>Each of the next M lines contains two different integers A and B, representing a road between towns A and B. </p>

<p>Towns may be connected by more than one road. </p>

### 출력 

 <p>Output the number of distinct routes that can be set on a single line. If that number has more than nine digits, output only the last nine digits of the number. If there are infinitely many routes, output "inf". </p>

