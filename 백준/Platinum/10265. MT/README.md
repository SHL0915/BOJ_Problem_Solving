# [Platinum IV] MT - 10265 

[문제 링크](https://www.acmicpc.net/problem/10265) 

### 성능 요약

메모리: 2252 KB, 시간: 0 ms

### 분류

깊이 우선 탐색, 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 배낭 문제, 강한 연결 요소

### 문제 설명

<p><img alt="" src="https://www.acmicpc.net/upload/images2/outing.png" style="float:right; height:265px; width:251px">Organising a group trip for the elderly can be a daunting task... Not least because of the fussy participants, each of whom will only make the trip on condition that some other participant also comes. After some effort, you have taken from each of your participants a number, indicating that this participant will refuse to join the excursion unless the participant with that number also joins– the less choosy simply give their own number. This would be easy enough to resolve (just send all of them) but the bus you are going to use during the trip has only a fixed number of places.</p>

<p>Given the preferences of all participants, find the maximum number of participants that can join.</p>

### 입력 

 <p>The first line of input contains two integers n and k (1 ≤ k ≤ n ≤ 1 000), where n denotes the total number of participants and k denotes the number of places on the bus.</p>

<p>The second line contains n integers xi for i = 1, 2, ... , n, where 1 ≤ x<sub>i</sub> ≤ n. The meaning of x<sub>i</sub> is that the i-th participant will refuse to join the excursion unless the x<sub>i</sub>-th participant also joins.</p>

### 출력 

 <p>Output one integer: the maximum number of participants that can join the excursion, so that all the participants’ preferences are obeyed and the capacity of the bus is not exceeded.</p>

