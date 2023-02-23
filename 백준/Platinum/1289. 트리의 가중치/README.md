# [Platinum III] 트리의 가중치 - 1289 

[문제 링크](https://www.acmicpc.net/problem/1289) 

### 성능 요약

메모리: 10276 KB, 시간: 52 ms

### 분류

다이나믹 프로그래밍(dp), 트리에서의 다이나믹 프로그래밍(dp_tree), 수학(math), 트리(trees)

### 문제 설명

<p>As you are bound to know by now, a tree is a connected graph consisting of N vertices and N−1 edges. Trees also have the property of there being exactly a single unique path between any pair of vertices. </p>

<p>You will be given a tree in which every edge is assigned a weight – a non-negative integer. The weight of a path is the product of the weights of all edges on the path. The weight of the tree is the sum of the weights of all paths in the tree. Paths going in opposite directions (A to B and B to A) are considered the same and, when calculating the weight of a tree, are counted only once. </p>

<p>Write a program that, given a tree, calculates its weight modulo 1 000 000 007. </p>

### 입력 

 <p>The first line contains the integer N (2 ≤ N ≤ 100000), the number of vertices in the tree. The vertices are numbered 1 to N. </p>

<p>Each of the following N−1 contains three integers A, B and W (1 ≤ A, B ≤ N, 0 ≤ W ≤ 1000) describing one edge. The edge connects vertices A and B, and its weight is W. </p>

### 출력 

 <p>Output the weight of the tree, modulo 1 000 000 007. </p>

