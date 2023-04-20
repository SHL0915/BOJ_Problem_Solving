# [Gold II] Carpets - 10852 

[문제 링크](https://www.acmicpc.net/problem/10852) 

### 성능 요약

메모리: 2064 KB, 시간: 460 ms

### 분류

백트래킹

### 문제 설명

<p>The computer science Professor Toving Liles loves the floor tiles in his office so much that he wants to protect them from damage by careless students. Therefore, he would like to buy cheap small rectangular carpets from the supermarket and cover the floor such that:</p>

<ol>
	<li>The entire floor is covered.</li>
	<li>The carpets do not overlap.</li>
	<li>The carpets are rotated arbitrarily.</li>
	<li>No carpet is cut into pieces.</li>
</ol>

<p>But when checking the supermarket’s stock he begins to wonder whether he can accomplish his plan at all. Can you help him?</p>

### 입력 

 <p>The first line contains two integers W and H describing the size of his room (1 ≤ W, H ≤ 100). The second line contains an integer c, denoting the number of different carpet colors the supermarket has in stock (1 ≤ c ≤ 7).</p>

<p>Each of the following c lines consists of three integers a<sub>i</sub>, w<sub>i</sub>, and h<sub>i</sub>, which means: the supermarket’s stock contains ai carpets of size w<sub>i</sub>, hi and color i (1 ≤ a<sub>i</sub> ≤ 7; 1 ≤ w<sub>i</sub> ≤ 100; 1 ≤ h<sub>i</sub> ≤ 100).</p>

<p>The supermarket has at most 7 carpets, i.e. Σ<sub>i</sub>a<sub>i</sub> ≤ 7.</p>

### 출력 

 <p>For the given room dimensions and the supermarket’s stock of carpets, print “yes” if it is possible to cover the room with carpets as specified above and “no” otherwise.</p>

