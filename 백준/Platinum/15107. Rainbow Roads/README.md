# [Platinum II] Rainbow Roads - 15107 

[문제 링크](https://www.acmicpc.net/problem/15107) 

### 성능 요약

메모리: 25776 KB, 시간: 76 ms

### 분류

자료 구조(data_structures), 오일러 경로 테크닉(euler_tour_technique), 그래프 이론(graphs), 그래프 탐색(graph_traversal), 트리(trees)

### 문제 설명

<p>You are given a tree with n nodes (conveniently numbered from 1 to n). Each edge in this tree has one of n colors. A path in this tree is called a rainbow if all adjacent edges in the path have different colors. Also, a node is called good if every simple path with that node as one of its endpoints is a rainbow path.</p>

<p>Find all the good nodes in the given tree.</p>

<p>A simple path is a path that does not repeat any vertex or edge.</p>

### 입력 

 <p>The first line of input contains a single integer n (1 ≤ n ≤ 50,000).</p>

<p>Each of the next n − 1 lines contains three space-separated integers a<sub>i</sub>, b<sub>i</sub>, and c<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub> ≤ n; a<sub>i</sub> ≠ b<sub>i</sub>), describing an edge of color c<sub>i</sub> that connects nodes a<sub>i</sub> and b<sub>i</sub>.</p>

<p>It is guaranteed that the given edges form a tree.</p>

### 출력 

 <p>On the first line of the output, print k, the number of good nodes.</p>

<p>In the next k lines, print the indices of all good nodes in numerical order, one per line.</p>

