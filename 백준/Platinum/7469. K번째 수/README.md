# [Platinum II] K번째 수 - 7469 

[문제 링크](https://www.acmicpc.net/problem/7469) 

### 성능 요약

메모리: 4972 KB, 시간: 680 ms

### 분류

이분 탐색(binary_search), 자료 구조(data_structures), 머지 소트 트리(merge_sort_tree), 세그먼트 트리(segtree), 정렬(sorting)

### 문제 설명

<p>You are working for Macrohard company in data structures department. After failing your previous task about key insertion you were asked to write a new data structure that would be able to return quickly k-th order statistics in the array segment.</p>

<p>That is, given an array a[1...n] of different integer numbers, your program must answer a series of questions Q(i, j, k) in the form: “What would be the k-th number in a[i...j] segment, if this segment was sorted?”</p>

<p>For example, consider the array a = (1,5,2,6,3,7,4). Let the question be Q(2,5,3). The segment a[2...5] is (5,2,6,3). If we sort this segment, we get (2,3,5,6), the third number is 5, and therefore the answer to the question is 5.</p>

### 입력 

 <p>The ﬁrst line of the input ﬁle contains n — the size of the array, and m — the number of questions to answer (1 ≤ n ≤ 100 000, 1 ≤ m ≤ 5 000).</p>

<p>The second line contains n diﬀerent integer numbers not exceeding 10<sup>9</sup> by their absolute values — the array for which the answers should be given.</p>

<p>The following m lines contain question descriptions, each description consists of three numbers: i, j, and k (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ j −i+ 1) and represents the question Q(i, j, k).</p>

### 출력 

 <p>For each question output the answer to it — the k-th number in sorted a[i...j] segment.</p>

