# [Platinum IV] 그래프의 싱크 - 6543 

[문제 링크](https://www.acmicpc.net/problem/6543) 

### 성능 요약

메모리: 2516 KB, 시간: 12 ms

### 분류

그래프 이론, 강한 연결 요소

### 문제 설명

<p>We will use the following (standard) definitions from graph theory. Let <em>V</em> be a nonempty and finite set, its elements being called vertices (or nodes). Let <em>E</em> be a subset of the Cartesian product <em>V×V</em>, its elements being called edges. Then <em>G=(V,E)</em> is called a directed graph.</p>

<p>Let <em>n</em> be a positive integer, and let <em>p=(e<sub>1</sub>,...,e<sub>n</sub>)</em> be a sequence of length <em>n</em> of edges <em>e<sub>i</sub>∈E</em> such that <em>e<sub>i</sub>=(v<sub>i</sub>,v<sub>i+1</sub>)</em> for a sequence of vertices <em>(v<sub>1</sub>,...,v<sub>n+1</sub>)</em>. Then <em>p</em> is called a path from vertex <em>v<sub>1</sub></em> to vertex <em>v<sub>n+1</sub></em> in <em>G</em> and we say that <em>v<sub>n+1</sub></em> is reachable from <em>v<sub>1</sub></em>, writing <em>(v<sub>1</sub>→v<sub>n+1</sub>)</em>.</p>

<p>Here are some new definitions. A node <em>v</em> in a graph <em>G=(V,E)</em> is called a sink, if for every node <em>w</em> in <em>G</em> that is reachable from <em>v</em>, <em>v</em> is also reachable from <em>w</em>. The bottom of a graph is the subset of all nodes that are sinks, i.e., <em>bottom(G)={v∈V|∀w∈V:(v→w)⇒(w→v)}</em>. You have to calculate the bottom of certain graphs.</p>

### 입력 

 <p>The input contains several test cases, each of which corresponds to a directed graph <em>G</em>. Each test case starts with an integer number <em>v</em>, denoting the number of vertices of <em>G=(V,E)</em>, where the vertices will be identified by the integer numbers in the set <em>V={1,...,v}</em>. You may assume that 1 ≤ <em>v</em> ≤ 5000, 0 ≤ <em>e</em> ≤ 100,000. That is followed by a non-negative integer <em>e</em> and, thereafter, <em>e</em> pairs of vertex identifiers <em>v<sub>1</sub>,w<sub>1</sub>,...,v<sub>e</sub>,w<sub>e</sub></em> with the meaning that <em>(v<sub>i</sub>,w<sub>i</sub>)∈E</em>. There are no edges other than specified by these pairs. The last test case is followed by a zero.</p>

### 출력 

 <p>For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.</p>

