# [Gold IV] 구조조정 - 3132 

[문제 링크](https://www.acmicpc.net/problem/3132) 

### 성능 요약

메모리: 2184 KB, 시간: 0 ms

### 분류

애드 혹, 그래프 이론, 정렬

### 제출 일자

2024년 10월 24일 21:40:26

### 문제 설명

<p>A software company has N employees. Each employee, with the exception of the head of the company, has a manager. The head of the company is manager to at least one employee. There are no cycles in the management structure (an employee cannot be, directly or indirectly, superior to himself). In other words, there is a tree-like hierarchy in the company. </p>

<p>A workgroup consists of an employee E and all employees he manages. We say that E is the manager of that workgroup. </p>

<p>Each employee's intelligence quotient (IQ) is represented by an integer. </p>

<p>The company’s management has decided to reorganize the hierarchy in order to improve efficiency. </p>

<p>The new hierarchy must meet the following requirements: </p>

<ol>
	<li>Each workgroup in the new hierarchy should have no more than 3 members. </li>
	<li>In each workgroup in the new hierarchy, no more than one member may have a higher IQ than the manager of the workgroup. </li>
	<li>Every employee and his (her) new manager must have belonged to the same workgroup in the old hierarchy. </li>
</ol>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/34367a0f-26a2-4f8c-99d5-e7292eb83726/-/preview/" style="width: 480px; height: 150px;"></p>

<p>The initial hierarchy in the company. Each node in the tree shows the index of the employee and his (her) IQ. This hierarchy does not meet the above requirements since there are two workgroups with four members (requirement 1 is not met) and, furthermore, workgroups with managers 1 and 8 do not meet requirement 2. </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ac4e3872-db04-4f0d-9aa6-639b1050f13f/-/preview/" style="width: 480px; height: 297px;"></p>

<p>One possible hierarchy after reorganizing. All three requirements are met. </p>

<p>Write a program that, given the description of the initial hierarchy, reorganizes the company so that the new hierarchy meets all of the above requirements. </p>

<p>The input data will be such that a solution will always exist, although it will not necessarily be unique. </p>

### 입력 

 <p>The first line of input contains an integer N (2 ≤ N ≤ 1 000), the number of employees in the company. </p>

<p>The second line of input contains N integers separated by single spaces. Each number represents the intelligence quotient of one employee. Employees are numbered 1 to N in the order in which their IQs are given. All IQs are between 50 and 200, inclusive. </p>

<p>Each of the following N−1 lines contains two integers M and E (1 ≤ M ≤ N, 1 ≤ E ≤ N), meaning that employee M is the manager of employee E in the initial hierarchy.</p>

### 출력 

 <p>Output should consist of exactly N-1 lines. </p>

<p>Each line of output should contain two integers M and E separated by a space, meaning that the employee M is the manager of employee E in the new hierarchy. The new hierarchy should satisfy all the requirements from the task description. </p>

