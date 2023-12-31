# [Platinum I] Freight - 10137 

[문제 링크](https://www.acmicpc.net/problem/10137) 

### 성능 요약

메모리: 26480 KB, 시간: 176 ms

### 분류

자료 구조, 덱, 덱을 이용한 구간 최댓값 트릭, 다이나믹 프로그래밍, 덱을 이용한 다이나믹 프로그래밍

### 제출 일자

2024년 1월 1일 01:20:45

### 문제 설명

<p>The train stations in Upper Bytown and Lower Bytown are connected with a single track rail link. It takes the train s minutes to travel between them in either direction. However, the trains departing a station have to be spaced at least one minute apart. Moreover, at all times, all the trains on the rail link have to go in the same direction.</p>

<p>According to the timetable at our disposal, n cargo trains destined for Lower Bytown are to pass through the Upper Bytown. They are to be loaded with goods in Lower Bytown and then return to Upper Bytown. For simplicity, we assume that loading the goods on the train takes virtually no time.</p>

<p>We are to determine the minimum possible time of the last train returning to Upper Bytown.</p>

### 입력 

 <p>The first line of the standard input contains two integers n, s(1 ≤ n ≤ 1,000,000, 1 ≤ s ≤ 10<sup>9</sup>), separated by a single space, that specify the number of trains and the one-way travel time respectively. The second line contains n integers t<sub>1</sub>,t<sub>2</sub>,…,t<sub>n</sub>(0 ≤ t<sub>1</sub> ≤ t<sub>2</sub> ≤ … ≤ t<sub>n</sub> ≤ 10<sup>9</sup>), separated by a single space, that specify the arrival times of successive trains at the Upper Bytown station.</p>

<p>In test worth 50% of the total score, n ≤ 5000 holds. Moreover, in their subset worth 25% of the total score, n ≤ 400 holds in addition.</p>

### 출력 

 <p>Your program should print out a single line with a single integer to the standard output: the minimum possible time of the last train returning to Upper Bytown.</p>

<p> </p>

