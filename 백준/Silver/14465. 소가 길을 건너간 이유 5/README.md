# [Silver II] 소가 길을 건너간 이유 5 - 14465 

[문제 링크](https://www.acmicpc.net/problem/14465) 

### 성능 요약

메모리: 2412 KB, 시간: 0 ms

### 분류

누적 합, 슬라이딩 윈도우

### 문제 설명

<p>The long road through Farmer John's farm has N crosswalks across it, conveniently numbered 1…N (1 ≤ N ≤ 100,000). To allow cows to cross at these crosswalks, FJ installs electric crossing signals, which light up with a green cow icon when it is ok for the cow to cross, and red otherwise. Unfortunately, a large electrical storm has damaged some of his signals. Given a list of the damaged signals, please compute the minimum number of signals that FJ needs to repair in order for there to exist some contiguous block of at least K working signals.</p>

### 입력 

 <p>The first line of input contains N, K, and B (1 ≤ B,K ≤ N). The next B lines each describe the ID number of a broken signal.</p>

### 출력 

 <p>Please compute the minimum number of signals that need to be repaired in order for there to be a contiguous block of K working signals somewhere along the road.</p>

