# [Diamond V] 월급 인상 - 3106 

[문제 링크](https://www.acmicpc.net/problem/3106) 

### 성능 요약

메모리: 59740 KB, 시간: 948 ms

### 분류

자료 구조, 오일러 경로 테크닉, 최소 공통 조상, 세그먼트 트리, 트리

### 문제 설명

<p>Mirko is a proud founder of a big software company. Initially he was the only worker in the company, but as the business grew, company hired N additional workers, one by one. We will denote Mirko with integer 0, and each of the remaining worker with integers 1 to N in order they were hired. </p>

<p>On the first day of work every worker was assigned as a subordinate to another worker. Also, every worker was assigned with initial salary. However, if the salary of the new worker was greater than the salary of his boss, then his boss also got a raise to equal their salaries. If the boss of the new worker now has a greater salary than his boss, the procedure is repeated until every worker has a salary that is less than or equal to the salary of his boss. </p>

<p>Write a program that will determine the number of workers that got a raise during the process of hiring each new worker. </p>

### 입력 

 <p>The first line contains one integer N (1 ≤ N ≤ 300000), the number of workers. </p>

<p>The second line contains one integer M, Mirko's initial salary. </p>

<p>The next N lines contain two integers each I and B, initial salary of the new worker and the index of his boss. Workers are given in the order they were hired, i.e. in ascending order of their indices. </p>

<p>All salaries are integers between 1 and 10<sup>9</sup> and boss indices always denote a worker that was already hired at that moment. </p>

### 출력 

 <p>Output N integers, one per line, the total number of workers that got a raise during the process of hiring each new worker in order they were hired. </p>

