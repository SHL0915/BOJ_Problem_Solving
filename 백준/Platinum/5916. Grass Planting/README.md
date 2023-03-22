# [Platinum I] Grass Planting - 5916 

[문제 링크](https://www.acmicpc.net/problem/5916) 

### 성능 요약

메모리: 24052 KB, 시간: 144 ms

### 분류

자료 구조, 트리, 세그먼트 트리, 느리게 갱신되는 세그먼트 트리, 최소 공통 조상, heavy-light 분할

### 문제 설명

<p>Farmer John has N barren pastures (2 <= N <= 100,000) connected by N-1 bidirectional roads, such that there is exactly one path between any two pastures. Bessie, a cow who loves her grazing time, often complains about how there is no grass on the roads between pastures. Farmer John loves Bessie very much, and today he is finally going to plant grass on the roads. He will do so using a procedure consisting of M steps (1 <= M <= 100,000).</p>

<p>At each step one of two things will happen:</p>

<ul>
	<li>FJ will choose two pastures, and plant a patch of grass along each road in between the two pastures, or,</li>
	<li>Bessie will ask about how many patches of grass on a particular road, and Farmer John must answer her question.</li>
</ul>

<p>Farmer John is a very poor counter -- help him answer Bessie's questions!</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers N and M</li>
	<li>Lines 2..N: Two space-separated integers describing the endpoints of a road.</li>
	<li>Lines N+1..N+M: Line i+1 describes step i. The first character of the line is either P or Q, which describes whether or not FJ is planting grass or simply querying. This is followed by two space-separated integers A_i and B_i (1 <= A_i, B_i <= N) which describe FJ's action or query.</li>
</ul>

### 출력 

 <ul>
	<li>Lines 1..???: Each line has the answer to a query, appearing in the same order as the queries appear in the input.</li>
</ul>

