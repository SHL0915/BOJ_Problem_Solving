# [Gold III] TV 전쟁 - 11108 

[문제 링크](https://www.acmicpc.net/problem/11108) 

### 성능 요약

메모리: 4576 KB, 시간: 120 ms

### 분류

다이나믹 프로그래밍, 정렬

### 제출 일자

2024년 3월 19일 19:31:54

### 문제 설명

<p>To your immense frustration, you only have one television set in your family. Deciding what TV show to watch at any given time is the source of a lot of argument. As an example, your little sister Anne always wants to watch ”Desperate Housewives” while you want to watch ”C.S.I.”. You believe it would be beneficial to use automated tools to settle these arguments.</p>

<p>You therefore decide to construct a system that will decide which show that should be on at any given point in time. During a season each show is typically sent on the exact same time each week. You therefore decide to solve this problem for one week, and let this solution decide for a whole season. Each member of the family is given y points which he/she can distribute among his/her favorite shows. We assume that each show starts at the same time and lasts for d consecutive minutes each week. Each TV show is then assigned the total number of points given to it by all family members in total. You should write a program that maximizes the total number of points of the TV shows shown on your television set.</p>

### 입력 

 <p>The first line of input gives 1 ≤ t ≤ 30, the number of test cases. The first line for each test case gives 1 ≤ n ≤ 100000, the number of TV shows that have gotten any points from your family. Then follow n lines with 3 space separated integers s<sub>i</sub>, d<sub>i</sub> and p<sub>i</sub>, where each line describes one TV show. s<sub>i</sub> describes the minute at which show i starts, and d<sub>i</sub> describes the number of minutes show i lasts (0 ≤ s<sub>i</sub> < s<sub>i</sub> + d<sub>i</sub> ≤ 10080). If s<sub>i</sub> + d<sub>i</sub> = k, it means that you can start watching a new show at time k. p<sub>i</sub> describes the total number of points show i has gotten in your family (1 ≤ p<sub>i</sub> ≤ 2000).</p>

### 출력 

 <p>There should be one line of output for each test case containing the maximum sum of points for the TV shows shown on the television set.</p>

