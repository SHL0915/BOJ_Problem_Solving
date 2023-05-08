# [Platinum III] Promotions - 11677 

[문제 링크](https://www.acmicpc.net/problem/11677) 

### 성능 요약

메모리: 171336 KB, 시간: 1028 ms

### 분류

그래프 이론, 그래프 탐색, 위상 정렬

### 문제 설명

<p>The Fair Inc. administration decided to promote the best employees and limited the number of promotions to a fixed interval [A, B]. The directors compared the employees’ performance and their evaluations resulted in a consistent precedence relation among employees, which has to be respected by promotions. This means that, for every pair of employees x and y, if x outperformed y, then y may be promoted only if x is promoted.</p>

<p>In order to understand whether the data collected so far is enough for ensuring fairness, the executive chairman wants to know:</p>

<ul>
	<li>How many employees will certainly be promoted in the interval endpoints (i.e., if the number of promotions is A and if the number of promotions is B).</li>
	<li>How many employees have no possibility of being promoted (even if the number of promotions is B).</li>
</ul>

<p>Consider the example depicted in the figure. There are seven employees and eight precedence rules. An arrow from an employee x to an employee y means that x outperformed y. The number of promotions is limited to the interval [3, 4]. Therefore:</p>

<ul>
	<li>If there are only three promotions, the promoted employees must be:
	<ul>
		<li>either Anne, Bob and Greg,</li>
		<li>or Anne, Eve and Greg.</li>
	</ul>
	</li>
</ul>

<p>In this case, two employees (Anne and Greg) will certainly be promoted. Notice that, with the current information, Bob and Eve may or may not win a promotion.</p>

<ul>
	<li>If there are four promotions, the promoted employees have to be:
	<ul>
		<li>Anne, Bob, Eve and Greg.</li>
	</ul>
	</li>
</ul>

<p>So, with four promotions, four employees (Anne, Bob, Eve and Greg) will certainly be promoted and three employees (Cora, Dan and Fred) have no possibility of being promoted.</p>

<p>Write a program that, given the interval of the number of promotions, the set of employees and the precedence relation among them, computes, for each of the interval endpoints, the number of employees that will certainly be promoted, and the number of employees that have no possibility of being promoted.</p>

<p>The precedence relation is consistent in the sense that, if an employee x outperformed an employee y, y did not outperform (directly or indirectly) x.</p>

### 입력 

 <p>The first line of the input has four space separated integers: A, B, E, and P. A and B are the interval endpoints, E is the number of employees and P is the number of precedence rules. Employees are identified by integers, ranging from 0 to E − 1. Each of the following P lines contains two distinct space separated integers, x and y, which indicate that employee x outperformed employee y.</p>

<p>Constraints</p>

<ul>
	<li>1 ≤ A < B < E Interval endpoints.</li>
	<li>2 ≤ E ≤ 5 000 Number of employees.</li>
	<li>1 ≤ P ≤ 20 000 Number of precedence rules.</li>
</ul>

### 출력 

 <p>The output consists of three lines. The first line contains the number of employees that will certainly be promoted if there are A promotions. The second line contains the number of employees that will certainly be promoted if there are B promotions. The third line contains the number of employees that have no possibility of being promoted (even if there are B promotions).</p>

