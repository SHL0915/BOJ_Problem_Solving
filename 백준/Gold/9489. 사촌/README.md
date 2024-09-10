# [Gold IV] 사촌 - 9489 

[문제 링크](https://www.acmicpc.net/problem/9489) 

### 성능 요약

메모리: 2344 KB, 시간: 156 ms

### 분류

자료 구조, 트리

### 제출 일자

2024년 9월 10일 13:55:38

### 문제 설명

<p>A tree is formed from a strictly increasing sequence of integers as follows: </p>

<ul>
	<li>The first integer in the sequence is the root of the tree </li>
	<li>The next set of consecutive integers in the sequence describes the children of the root. The first of these will be greater than root+1. </li>
	<li>From there, each set of consecutive integers describes the children of the lowest numbered node which does not yet have children. </li>
	<li>Non-consecutive integers mark a break between one set of children and the next. </li>
</ul>

<p>For example, the sequence: </p>

<p>1 3 4 5 8 9 15 30 31 32 </p>

<p>Would produce the following tree: </p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/cc.png" style="height:245px; width:320px"></p>

<p>Two nodes are considered to be Cousins if they have different parents, but their parents are siblings. Given a tree and a particular node of that tree, count the number of Cousins of the node. </p>

### 입력 

 <p>There will be several test cases in the input. Each test case will begin with a line with two integers, n (1≤n≤1,000) and k (1≤k≤1,000,000), where n is the number of nodes in the tree, and k is the particular node of interest. On the following line will be n integers, all in the range from 1 to 1,000,000, and guaranteed to be strictly increasing. These describe the tree, in the manner described above. The integers will be separated with a single space. There will be no extra spaces. The value k is guaranteed to be one of the integers on the second line. Input will end with a line with two 0s. </p>

### 출력 

 <p>For each test case, output a single integer, indicating the number of cousins of node k. Output no spaces, and do not separate answers with blank lines. </p>

