# [Platinum IV] 순열 - 1849 

[문제 링크](https://www.acmicpc.net/problem/1849) 

### 성능 요약

메모리: 3584 KB, 시간: 56 ms

### 분류

이분 탐색, 자료 구조, 세그먼트 트리

### 제출 일자

2024년 10월 30일 15:08:35

### 문제 설명

<p>Professor Permula gave a number of permutations of the n integers 1, 2, ..., n to her students. For each integer i (1 <= i <= n), she asks the students to write down the number of integers greater than i that appears before i in the given permutation. This number is denoted a<sub>i</sub>. For example, if n = 8 and the permutation is 2,7,3,5,4,1,8,6, then a1 = 5 because there are 5 numbers (2, 7, 3, 5, 4) greater than 1 appearing before it. Similarly, a4 = 2 because there are 2 numbers (7, 5) greater than 4 appearing before it.</p>

<p>John, one of the students in the class, is studying for the final exams now. He found out that he has lost the assignment questions. He only has the answers (the a<sub>i</sub>'s) but not the original permutation. Can you help him determine the original permutation, so he can review how to obtain the answers?</p>

### 입력 

 <p>The input consists of a number of test cases. Each test case starts with a line containing the integer n (n <= 500). The next n lines give the values of a<sub>1</sub>, ..., a<sub>n</sub>. The input ends with n = 0.</p>

### 출력 

 <p>For each test case, print a line specifying the original permutation. Adjacent elements of a permutation should be separated by a comma. Note that some cases may require you to print lines containing more than 80 characters.</p>

