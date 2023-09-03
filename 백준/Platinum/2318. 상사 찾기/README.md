# [Platinum IV] 상사 찾기 - 2318 

[문제 링크](https://www.acmicpc.net/problem/2318) 

### 성능 요약

메모리: 86848 KB, 시간: 160 ms

### 분류

너비 우선 탐색, 이분 탐색, 값 / 좌표 압축, 자료 구조, 깊이 우선 탐색, 그래프 이론, 그래프 탐색, 세그먼트 트리, 정렬, 희소 배열, 트리, 트리를 사용한 집합과 맵

### 문제 설명

<p>Several surveys indicate that the taller you are, the higher you can climb the corporate ladder. At TALL Enterprises Inc. this “de facto standard” has been properly formalized: your boss is always at least as tall as you are. Furthermore, you can safely assume that your boss earns a bit more than you do. In fact, you can be absolutely sure that your immediate boss is the person who earns the least among all the employees that earn more than you and are at least as tall as you are. Furthermore, if you are the immediate boss of someone, that person is your subordinate, and all his subordinates are your subordinates as well. If you are nobody’s boss, then you have no subordinates. As simple as these rules are, many people working for TALL are unsure of to whom they should be turning in their weekly progress report and how many subordinates they have. Write a program that will help in determining for any employee who the immediate boss of that employee is and how many subordinates they have. Quality Assurance at TALL have devised a series of tests to ensure that your program is correct. These test are described below.</p>

### 입력 

 <p>On the first line of the input is a single positive integer n, telling the number of test scenarios to follow. Each scenario begins with a line containing two positive integers m and q, where m (at most 30000) is the number of employees and q (at most 200) is the number of queries. The following m lines each list an employee by three integers on the same line: employee ID number (six decimal digits, the first one of which is not zero), yearly salary in Euros and finally height in µm (1 µm = 10-6 meters – accuracy is important at TALL). The chairperson is the employee that earns more than anyone else and is also the tallest person in the company. Then there are q lines listing queries. Each query is a single legal employee ID.</p>

<p>The salary is a positive integer which is at most 10 000 000. No two employees have the same ID, and no two employees have the same salary. The height of an employee is at least 1 000 000 µm and at most 2 500 000 µm.</p>

### 출력 

 <p>For each employee ID x in a query output a single line with two integers y k, separated by one space character, where y is the ID of x’s boss, and k is the number of subordinates of x. If the query is the ID of the chairperson, then you should output 0 as the ID of his or her boss (since the chairperson has no immediate boss except, possibly, God).</p>

