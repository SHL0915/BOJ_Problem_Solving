# [Gold III] 최대 거리 - 2381 

[문제 링크](https://www.acmicpc.net/problem/2381) 

### 성능 요약

메모리: 2412 KB, 시간: 20 ms

### 분류

애드 혹, 수학, 정렬

### 제출 일자

2024년 6월 22일 13:36:25

### 문제 설명

<p>Farmer John's N (1 <= N <= 50,000) cows are exploring a large room in a cave.  It is dark, and the cows communicate by mooing loudly at each other.  Due to the strange accoustics of the room, the time it takes for a 'moo' from one cow to reach another cow is proportional to the "manhattan" distance between the two cows: that is, if cow A is at location (Xa, Ya) and cow B is at location (Xb, Yb), it takes |Xa-Xb| + |Ya-Yb| units of time for a 'moo' from cow A to reach cow B. X and Y coordinates are all in the range (-1,000,000 .. 1,000,000).</p>

<p>Given the locations of the N cows, determine the maximum time over all pairs of cows for a 'moo' to propagate.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N+1: Each line contains two space-separated integers, giving the (x,y) coordinates of a cow</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The maximum 'moo' distance among all pairs of cows</li>
</ul>

