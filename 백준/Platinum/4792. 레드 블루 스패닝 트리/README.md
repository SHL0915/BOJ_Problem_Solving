# [Platinum III] 레드 블루 스패닝 트리 - 4792 

[문제 링크](https://www.acmicpc.net/problem/4792) 

### 성능 요약

메모리: 8560 KB, 시간: 164 ms

### 분류

자료 구조, 분리 집합, 그래프 이론, 최소 스패닝 트리

### 제출 일자

2024년 2월 22일 14:13:10

### 문제 설명

<p>Given an undirected, unweighted, connected graph, where each edge is colored either blue or red, determine whether a spanning tree with exactly k blue edges exists. </p>

### 입력 

 <p>There will be several test cases in the input. Each test case will begin with a line with three integers: </p>

<pre>n m k</pre>

<p>Where n (2≤n≤1,000) is the number of nodes in the graph, m (limited by the structure of the graph) is the number of edges in the graph, and k (0≤k<n) is the number of blue edges desired in the spanning tree. </p>

<p>Each of the next m lines will contain three elements, describing the edges: </p>

<pre>c f t</pre>

<p>Where c is a character, either capital ‘R’ or capital ‘B’, indicating the color of the edge, and f and t are integers (1≤f,t≤n, t≠f) indicating the nodes that edge goes from and to. The graph is guaranteed to be connected, and there is guaranteed to be at most one edge between any pair of nodes. </p>

<p>The input will end with a line with three 0s. </p>

### 출력 

 <p>For each test case, output single line, containing 1 if it is possible to build a spanning tree with exactly k blue edges, and 0 if it is not possible. Output no extra spaces, and do not separate answers with blank lines. </p>

