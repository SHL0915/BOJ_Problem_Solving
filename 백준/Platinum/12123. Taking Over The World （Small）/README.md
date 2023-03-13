# [Platinum IV] Taking Over The World (Small) - 12123 

[문제 링크](https://www.acmicpc.net/problem/12123) 

### 성능 요약

메모리: 2784 KB, 시간: 4 ms

### 분류

구현, 그래프 이론, 데이크스트라, 최대 유량, 최대 유량 최소 컷 정리

### 문제 설명

<p>You and your friend Pinky have a plan to take over the world. But first you need to disable a certain secret weapon.</p>

<p>It is hidden inside a twisted maze of passages (a graph) with one entrance. Pinky is going to be at the vertex with the secret weapon, disabling it. Meanwhile, a security team at the graph entrance will be alerted, and will run through the graph to try to get to Pinky in time to stop him. You are going to be slowing down the security team to give Pinky as much time as possible. It takes one unit of time to traverse any edge of the graph, but you can additionally "obstruct" up to <strong>K</strong> vertices. It takes one additional unit of time to traverse an obstructed vertex. You will choose to obstruct a set of vertices that slows down the security team by as much as possible.</p>

<p>If the security team will be starting at the graph entrance and is trying to get to the secret weapon vertex, how much time will it take them to get there? Note that you have to commit all your obstructions before the security guards start their journey, and the security guards will know which vertices you have obstructed and will choose an optimal path based on that information.</p>

<p>Obstructing the secret weapon vertex is not useful because that will not delay the guards any further after they have already caught Pinky. Obstructing the entrance, on the other hand, is obviously a good idea.</p>

### 입력 

 <p>The first line of the input gives the number of test cases, <strong>T</strong>.  <strong>T</strong> test cases follow. Each one starts with a line containing <strong>N</strong>, <strong>M</strong>, and <strong>K</strong>. The next <strong>M</strong> lines each contain a pair of vertices connected by an edge. Vertices are numbered from 0 (the entrance) to <strong>N</strong> - 1 (the secret weapon room). The first vertex will always be smaller than the second vertex, and no pair of vertices will appear more than once in the same test case. Edges are bi-directional -- the guards can travel along any edge in either direction.</p>

<h3>Limits</h3>

<ul>
	<li>1 ≤ <strong>T</strong> ≤ 100.</li>
	<li>2 ≤ <strong>N</strong> ≤ 100.</li>
	<li>1 ≤ <strong>M</strong> ≤ <strong>N</strong> * (<strong>N</strong> - 1) / 2.</li>
	<li>1 ≤ <strong>K</strong> ≤ <strong>N</strong>.</li>
	<li>There will always be a path from room 0 to room <strong>N</strong> - 1.</li>
	<li>It will not be possible to delay the guards by more than 2 time units, compared to the shortest unobstructed path length (using the given <strong>K</strong>).</li>
</ul>

### 출력 

 <p>For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the time it will take the security guards to get from the entrance to the secret weapon room.</p>

