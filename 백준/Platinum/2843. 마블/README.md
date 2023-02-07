# [Platinum III] 마블 - 2843 

[문제 링크](https://www.acmicpc.net/problem/2843) 

### 성능 요약

메모리: 46116 KB, 시간: 276 ms

### 분류

자료 구조(data_structures), 분리 집합(disjoint_set), 오프라인 쿼리(offline_queries)

### 문제 설명

<p>Mirko and Slavko love playing with marbles. On an exciting Friday, Mirko has come up with a marble game which he wants to show to Slavko.</p>

<p>In the game, Mirko constructs a directional graph in which all vertices have at most at most one outgoing edge. Then he places a marble on one of the vertices. Whenever a marble is on some vertex X, the marble moves to the adjacent vertex connected by a single edge, if such exists. The movement of the marble continues until a vertex with no outgoing edge is visited, where the marble stops. It is also possible that the marble traverses the graph indefinitely in case no such vertex is ever visited.</p>

<p>To make sure that Slavko understand the rules of the game, Mirko will ask a series of queries. The types of queries are as follows:</p>

<ul>
	<li>1 X – unless the marble stucks in a loop, on which vertex will the marble stop if it is placed on the vertex X?</li>
	<li>2 X – delete the outgoing edge of the vertex X (it is guaranteed that such edge will always exist) </li>
</ul>

<p>Note: queries are executed in order and are cummulative (one affects another).</p>

### 입력 

 <p>The first line contains a postive integer N (1 ≤ N ≤ 300 000), the number of vertices in the graph.</p>

<p>The second line contains exactly N positive integers separated by a single space, where the number at position i denotes the index of the destination of the outgoing edge from vertex with index i. The zero value represent that there is no outgoing edge from the vertex with index i.</p>

<p>The following line contains a single positive integer Q (1 ≤ Q ≤ 300 000), the number of queries.</p>

<p>The remaining Q lines contain queries in the format described above.</p>

### 출력 

 <p>For each query of type 1, output the index of the vertex where the marble stops, one per line, in the order of the execution of queries. If the marble never stops, output CIKLUS instead.</p>

