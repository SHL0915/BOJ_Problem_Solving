# [Platinum III] 자동차 공장 - 2820 

[문제 링크](https://www.acmicpc.net/problem/2820) 

### 성능 요약

메모리: 63636 KB, 시간: 656 ms

### 분류

자료 구조(data_structures), 오일러 경로 테크닉(euler_tour_technique), 느리게 갱신되는 세그먼트 트리(lazyprop), 세그먼트 트리(segtree), 트리(trees)

### 문제 설명

<p>Mirko loves cars and he finally managed to start his own car factory! Factory has N employees, each of them has exactly one superior (except Mirko - he is by default everybody’s superior). Mirko is denoted by number 1, and the rest of the employees with numbers 2 to N. </p>

<p>Every employee can raise or lower the wages of all of his subordinates (both direct subordinates and those lower in the hieararchy tree). Mirko’s role is to prevent abuse of such power, so from time to time he wants to know wage of a particular employee. </p>

<p>He is asking you to write a program which will help him monitor wage changes, given a sequence of commands described in the input section. </p>

<p>Remark: at any time, all of the wages will be positive integers and will fit in standard 32-bit integer type (int in C/C++, longint in Pascal).</p>

### 입력 

 <p>First line of input contains two space-separated positive integers N (1 ≤ N ≤ 500 000), number of employees, and M (1 ≤ M ≤ 500 000), number of wage changes and wage queries. </p>

<p>Next N lines contain the information about employees 1, 2, ..., N (respectively): starting wage and the identifier of his direct supervisor. Remark: Mirko has no supervisor, so his line will contain only his starting wage. </p>

<p>Next M lines contain one of the following: </p>

<p>p A X - employee A increases (or decreases in case of a negative X) wage of all his subordinates by the amount X (-10 000 ≤ X ≤ 10 000); <br>
u A - Mirko wants to know the wage of employee A. </p>

### 출력 

 <p>Output should contain one line for each ‘2’ query in the input - the current wage of the given employee. </p>

<p> </p>

