# [Platinum II] Critical 3-Path - 8890 

[문제 링크](https://www.acmicpc.net/problem/8890) 

### 성능 요약

메모리: 11204 KB, 시간: 360 ms

### 분류

다이나믹 프로그래밍, 그래프 이론

### 제출 일자

2024년 5월 2일 10:27:44

### 문제 설명

<p>The PERT (Project Evaluation and Review Technique) chart, a graphical tool used in the field of project management, is designed to analyze and represent the set of tasks involved in completing a given project. Edges in PERT chart represent tasks to be performed, and edge weights represent the length of time required to perform the task. For vertices u, v, w of a PERT chart, if edge (u,v) enters vertex v and edge (v,w) leaves v, then task (u,v) must be performed prior to task (v,w). A path through a PERT chart represents a sequence of tasks that must be performed in a particular order. Note that there is no cycle in the PERT chart. A critical path is a longest path in PERT chart, corresponding to the longest time to perform an ordered sequence of tasks. The weight of a critical path is a lower bound on the total time to perform all the tasks in a project. </p>

<p>A 3-path of six distinct vertices s<sub>1</sub>, s<sub>2</sub>, s<sub>3</sub>, t<sub>1</sub>, t<sub>2</sub>, t<sub>3</sub> in a PERT chart is defined as follows: </p>

<ol>
	<li>A 3-path consists of three paths P<sub>i</sub> from vertex s<sub>i</sub> to vertex t<sub>i</sub> for i =1, 2, 3.</li>
	<li>The paths P<sub>1</sub>, P<sub>2</sub>, P<sub>3</sub> are vertex-disjoint, i.e., no two of the paths have vertices in common.</li>
</ol>

<p>The length of a 3-path is the sum of the length of the 3 paths P<sub>1</sub>, P<sub>2</sub>, P<sub>3</sub>. A critical 3-path of six distinct vertices in a PERT chart is a 3-path of maximum length over all 3-paths.</p>

<p>For example, a critical 3-path {P<sub>1</sub>, P<sub>2</sub>, P<sub>3</sub>} of a graph in Figure 1, where P<sub>1</sub> is a path from vertex 3 to vertex 15, P<sub>2</sub> is a path from vertex 4 to vertex 16, and P<sub>3</sub> is path from vertex 5 to vertex 17, is as follows:</p>

<ul>
	<li>P<sub>1</sub> : 3 → 6 → 11 → 15</li>
	<li>P<sub>2</sub> : 4 → 7 → 9 → 12 → 16</li>
	<li>P<sub>3</sub> : 5 → 8 → 13 → 17 </li>
</ul>

<p>The length of the critical 3-path is 128.</p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images2/3path.png" style="height:268px; width:564px"></p>

<p style="text-align:center">Figure 1. A sample PERT chart</p>

<p>Given a graph corresponding to a PERT chart and six distinct vertices, write a program to find the length of critical 3-path of the graph corresponding to the six vertices. </p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing two integers, n and m (6 ≤ n ≤ 100, n-1 ≤ m ≤ n(n-1)/2), where n is the number of vertices and m is the number of edges. Every input node is numbered from 1 to n. Next line contains six integers s<sub>1</sub>, s<sub>2</sub>, s<sub>3</sub>, t<sub>1</sub>, t<sub>2</sub>, t<sub>3</sub>, where all six integers are distinct. In the following m lines, the weight of the directed edges are given; each line contains three integers, u, v, and W (1 ≤ W ≤ 100,000), where W is the weight of an edge from vertex u to v. You may assume that u < v.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain the length of critical 3-path {P<sub>1</sub>, P<sub>2</sub>, P<sub>3</sub>}, where P<sub>i</sub> is a path from s<sub>i</sub> to t<sub>i</sub> (1 ≤ i ≤ 3). If there does not exist a critical 3-path, print 0.</p>

