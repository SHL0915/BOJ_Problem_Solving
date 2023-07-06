# [Platinum II] 단방향 링크 네트워크 - 3295 

[문제 링크](https://www.acmicpc.net/problem/3295) 

### 성능 요약

메모리: 2452 KB, 시간: 40 ms

### 분류

이분 매칭

### 문제 설명

<p>There is a multicomputer system that consists of a number of nodes, each with its own memory. The nodes in the system are interconnected via unidirectional communication links. The interconnection network of the system, representing the way in which the nodes are connected together, is modeled as a directed graph, where vertices and directed edges respectively represent nodes and unidirectional links of the network. Figure 1 shows an example of interconnection networks with fourteen nodes interconnected via nineteen unidirectional links. </p>

<p>Linear arrays and rings are two of the important computational structures in interconnection networks. In a linear array, each node except for the extreme ends has two neighboring nodes, one to its left and one to its right, where the two nodes at the ends are connected to their single neighbor. If the nodes at either end are connected, we refer to it as a ring. More specifically, the nodes of a linear array with k nodes can be numbered from 0 to k-1 so that there exists a unidirectional link from node i to node i+1 for every 0 ≤ i < k-1. The linear array becomes a ring if we add a unidirectional link from the node k-1 to the node 0. </p>

<p>To support parallel applications that require one of the two aforementioned computational structures, we needs to decompose the system into several subsystems each of whose interconnection networks is a ring or a linear array. The subsystems should be pairwise node-disjoint, i.e., no two subsystems share a common node. According to a recent report, a ring composed of k nodes is worth k dollars while a linear array of k nodes is worth k-1 dollars. This motivates the study on how to decompose the system into subsystems in order to maximize profits. You are to write a program for decomposing the interconnection network of our multicomputer system into rings and/or linear arrays whose total value is the maximum possible. Note that a linear array may have only one node and in that case, its value is zero dollar.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/interconn.png" style="height:305px; width:365px"></p>

<p><strong>Figure 1</strong>. An interconnection network and its decomposition into a ring of six nodes (red) and a linear array of eight nodes (green). The total value of this decomposition is thirteen dollars, which is the maximum possible. </p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases, where the positive integer T is given in the first line of the input, followed by the description of each test case. The first line of a test case contains two positive integers n and m, respectively indicating the numbers of nodes and unidirectional links in an interconnection network, in which we assume n ≤ 1,000 and m ≤ 50,000. The nodes are indexed 0 to n-1. In the following m lines, each line contains two integers u and v, which represent a unidirectional link from node u to node v. The two integers given in a single line are always separated by a space. </p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain an integer, representing the maximum total value in dollars that can be achieved by decomposing the interconnection network into rings and/or linear arrays. </p>

