# [Platinum I] Roads and Planes - 5952 

[문제 링크](https://www.acmicpc.net/problem/5952) 

### 성능 요약

메모리: 5824 KB, 시간: 60 ms

### 분류

데이크스트라, 그래프 이론, 위상 정렬

### 문제 설명

<p>Farmer John is conducting research for a new milk contract in a new territory. He intends to distribute milk to T (1 <= T <= 25,000) towns conveniently numbered 1..T which are connected by up to R (1 <= R <= 50,000) roads conveniently numbered 1..R and/or P (1 <= P <= 50,000) airplane flights conveniently numbered 1..P.</p>

<p>Either road i or plane i connects town A_i (1 <= A_i <= T) to town B_i (1 <= B_i <= T) with traversal cost C_i. For roads, 0 <= C_i <= 10,000; however, due to the strange finances of the airlines, the cost for planes can be quite negative (-10,000 <= C_i <= 10,000).</p>

<p>Roads are bidirectional and can be traversed from A_i to B_i or B_i to A_i for the same cost; the cost of a road must be non-negative.</p>

<p>Planes, however, can only be used in the direction from A_i to B_i specified in the input. In fact, if there is a plane from A_i to B_i it is guaranteed that there is no way to return from B_i to A_i with any sequence of roads and planes due to recent antiterror<br>
regulation.</p>

<p>Farmer John is known around the world as the source of the world's finest dairy cows. He has in fact received orders for his cows from every single town. He therefore wants to find the cheapest price for delivery to each town from his distribution center in town S (1 <= S <= T) or to know that it is not possible if this is the case.</p>

### 입력 

 <ul>
	<li>Line 1: Four space separated integers: T, R, P, and S</li>
	<li>Lines 2..R+1: Three space separated integers describing a road: A_i, B_i and C_i</li>
	<li>Lines R+2..R+P+1: Three space separated integers describing a plane: A_i, B_i and C_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Lines 1..T: The minimum cost to get from town S to town i, or 'NO PATH' if this is not possible</li>
</ul>

<p> </p>

