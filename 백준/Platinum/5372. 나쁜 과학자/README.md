# [Platinum IV] 나쁜 과학자 - 5372 

[문제 링크](https://www.acmicpc.net/problem/5372) 

### 성능 요약

메모리: 2156 KB, 시간: 92 ms

### 분류

백트래킹, 브루트포스 알고리즘, 깊이 우선 탐색, 그래프 이론, 그래프 탐색

### 문제 설명

<p>You are a rather fraudulent scientist who makes up all his research data. Due to careful planning you got away with this for many years, but recently you became sloppy. In your most recent paper you came up with so many theories that some even contradict each other. You want to throw away as few theories as possible such that no contradicting pair remains.</p>

<p>There is a problem however: your colleagues have seen you doing a lot of research. There is a limit on how many theories you can throw away before they get suspicious.</p>

### 입력 

 <p>On the ﬁrst line one positive number: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with an integer n (1 ≤ n ≤ 50): the number of theories in the paper.</li>
	<li>one line with an integer k (1 ≤ n ≤ 50): the maximum number of theories that can be discarded without arousing suspicion.</li>
	<li>one line with an integer m (0 ≤ m ≤ n×(n-1)/2): the number of theory pairs that contradict each other.</li>
	<li>m distinct lines with two space-separated integers x<sub>i</sub> and y<sub>i</sub> (1 ≤ x<sub>i</sub> < y<sub>i</sub> ≤ n), indicating theory x<sub>i</sub> and theory y<sub>i</sub> are contradictory.</li>
</ul>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with the minimal number of theories that have to be discarded to make a consistent paper or the word “IMPOSSIBLE” if this is impossible without arousing suspicion.</li>
</ul>

