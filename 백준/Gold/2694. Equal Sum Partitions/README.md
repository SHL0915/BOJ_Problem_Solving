# [Gold III] Equal Sum Partitions - 2694 

[문제 링크](https://www.acmicpc.net/problem/2694) 

### 성능 요약

메모리: 2060 KB, 시간: 132 ms

### 분류

수학, 브루트포스 알고리즘, 정수론, 누적 합

### 문제 설명

<p>An equal sum partition of a sequence of numbers is a grouping of the numbers (in the same order as the original sequence) in such a way that each group has the same sum. For example, the sequence: </p>

<pre>2 5 1 3 3 7 </pre>

<p>may be grouped as: </p>

<pre>(2 5) (1 3 3) (7) </pre>

<p>to yield an equal sum of 7. </p>

<p>Note: The partition that puts all the numbers in a single group is an equal sum partition with the sum equal to the sum of all the numbers in the sequence. </p>

<p>For this problem, you will write a program that takes as input a sequence of positive integers and returns the smallest sum for an equal sum partition of the sequence. </p>

### 입력 

 <p>The first line of input contains a single integer P, (1 ≤ P ≤ 50), which is the number of data sets that follow. The first line of each data set contains a decimal integer M, (1 ≤ M ≤ 10000), giving the total number of integers in the sequence. The remaining line(s) in the dataset consist of the values, 10 per line, separated by a single space. The last line in the dataset may contain less than 10 values. </p>

### 출력 

 <p>For each data set, generate one line of output with the following value: The smallest sum for an equal sum partition of the sequence. </p>

