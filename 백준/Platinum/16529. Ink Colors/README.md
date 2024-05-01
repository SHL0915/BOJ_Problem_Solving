# [Platinum III] Ink Colors - 16529 

[문제 링크](https://www.acmicpc.net/problem/16529) 

### 성능 요약

메모리: 7260 KB, 시간: 64 ms

### 분류

깊이 우선 탐색, 다이나믹 프로그래밍, 트리에서의 다이나믹 프로그래밍, 그래프 이론, 그래프 탐색, 그리디 알고리즘, 트리

### 제출 일자

2024년 5월 1일 21:55:21

### 문제 설명

<p>Stick Man left the family tree and went out for adventures. On his journey he found a strange tree with the root on the air and branches directed towards the ground. He decided to paint some of the tree branches to remind himself of home. To do so he wants that branches painted with the same color are all connected and form a stick man. A stick man is a group of six branches (p, q) (q, r) (q, s) (q, t) (s, u) and (s, v), as show in figure (a) below. Figure (b) shows a tree with one stick man painted and figure (c) shows the same tree with two stick men painted.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/cb79e059-4d3a-4914-b904-129db66006b1/-/preview/" style="width: 550px; height: 230px;"></p>

<p>Stick Man would like to paint as many stick men on the tree as possible, such that each branch is part of at most a single stick man. Can you help him figure out how many ink colors he needs to buy?</p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 10<sup>5</sup>) indicating the number of nodes in the tree. Nodes are identified by distinct integers from 1 to N, where node 1 is the root of the tree. The second line contains N − 1 integers P<sub>2</sub>, P<sub>3</sub>, . . . , P<sub>N</sub> (1 ≤ P<sub>i</sub> ≤ N for i = 2, 3, . . . , N), where the value P<sub>i</sub> represents that there is a branch (P<sub>i</sub>, i), that is, from node P<sub>i</sub> to node i.</p>

### 출력 

 <p>Output a single line with an integer indicating the maximum number of stick men that might be simultaneously painted on the tree.</p>

