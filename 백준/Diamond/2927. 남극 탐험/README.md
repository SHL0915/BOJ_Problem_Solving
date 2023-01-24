# [Diamond V] 남극 탐험 - 2927 

[문제 링크](https://www.acmicpc.net/problem/2927) 

### 성능 요약

메모리: 12532 KB, 시간: 392 ms

### 분류

자료 구조(data_structures), 분리 집합(disjoint_set), Heavy-light 분할(hld), 오프라인 쿼리(offline_queries), 세그먼트 트리(segtree), 트리(trees)

### 문제 설명

<p>Some time ago Mirko founded a new tourist agency named "Dreams of Ice". The agency purchased N icy islands near the South Pole and now offers excursions. Especially popular are the emperor penguins, which can be found in large numbers on the islands. </p>

<p>Mirko's agency has become a huge hit; so big that it is no longer cost-effective to use boats for the excursions. The agency will build bridges between islands and transport tourists by buses. Mirko wants to introduce a computer program to manage the bridge building process so that fewer mistakes are made. </p>

<p>The islands are numbered 1 through N. No two islands are initially connected by bridges. The initial number of penguins on each island is known. That number may change, but will always be between 0 and 1000 (inclusive). </p>

<p>Your program must handle the following three types of commands: </p>

<ul>
	<li>"bridge A B" – an offer was received to build a bridge between islands A and B (A and B will be different). To limit costs, your program must accept the offer only if there isn't already a way to get from one island to the other using previously built bridges. If the offer is accepted, the program should output "yes", after which the bridge is built. If the offer is rejected, the program should output "no". </li>
	<li>"penguins A X" – the penguins on island A have been recounted and there are now X of them. This is an informative command and your program does not need to respond. </li>
	<li>"excursion A B" – a group of tourists wants an excursion from island A to island B. If the excursion is possible (it is possible to get from island A to B), the program should output the total number of penguins the tourists would see on the excursion (including islands A and B). Otherwise, your program should output "impossible". </li>
</ul>

### 입력 

 <p>The first line contains the integer N (1 ≤ N ≤ 30 000), the number of islands. </p>

<p>The second line contains N integers between 0 and 1000, the initial number of penguins on each of the islands. </p>

<p>The third line contains an integer Q (1 ≤ Q ≤ 300 000), the number of commands. </p>

<p>Q commands follow, each on its own line. As noted above, after receiving a command "bridge" or "excursion", your program will not receive another command until it has responded to the previous one.</p>

### 출력 

 <p>Output the responses to commands "bridge" and "excursion", each on its own line. </p>

