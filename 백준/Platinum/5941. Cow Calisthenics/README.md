# [Platinum II] Cow Calisthenics - 5941 

[문제 링크](https://www.acmicpc.net/problem/5941) 

### 성능 요약

메모리: 23080 KB, 시간: 224 ms

### 분류

이분 탐색, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그리디 알고리즘, 매개 변수 탐색, 트리

### 문제 설명

<p>Farmer John continues his never-ending quest to keep the cows fit by having them exercise on various cow paths that run through the pastures. These cow paths can be represented as a set of vertices connected with bidirectional edges so that each pair of vertices has exactly one simple path between them. In the abstract, their layout bears a remarkable resemblance to a tree. Surprisingly, each edge (as it winds its way through the pastures) has the same length.</p>

<p>For any given set of cow paths, the canny cows calculate the longest possible distance between any pair of vertices on the set of cowpaths and call it the pathlength. If they think this pathlength is too large, they simply refuse to exercise at all.</p>

<p>Farmer John has mapped the paths and found V (2 <= V <= 100,000) vertices, conveniently numbered from 1..V. In order to make shorter cowpaths, he can block the path between any two vertices, thus creating more sets of cow paths while reducing the pathlength of both cowpath sets.</p>

<p>Starting from a single completely connected set of paths (which have the properties of a tree), FJ can block S (1 <= S <= V-1) paths, creating S+1 sets of paths. Your goal is to compute the best paths he can create so that the largest pathlength of all those sets is minimized.</p>

<p>Farmer John has a list of all V-1 edges in his tree, each described by the two vertices A_i (1 <= A_i <= V) and B_i (1 <= B_i <= V; A_i != B_i) that it connects.</p>

<p>Consider this rather linear cowpath set (a tree with 7 vertices):</p>

<pre>                   1---2---3---4---5---6---7</pre>

<p>If FJ can block two paths, he might choose them to make a map like this:</p>

<pre>           1---2 | 3---4 | 5---6---7</pre>

<p>where the longest pathlength is 2, which would be the answer in this case. He can do no better than this.</p>

### 입력 

 <ul>
	<li>Line 1: Two space separated integers: V and S</li>
	<li>Lines 2..V: Two space separated integers: A_i and B_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the best maximum pathlength FJ can achieve with S blocks</li>
</ul>

<p> </p>

