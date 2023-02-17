# [Platinum IV] 파티 - 2367 

[문제 링크](https://www.acmicpc.net/problem/2367) 

### 성능 요약

메모리: 3024 KB, 시간: 76 ms

### 분류

최대 유량(flow)

### 문제 설명

<p>A group of  N (3 <= N <= 200) cows is having a New Year's party.  Each cow is able to cook several different kinds of food (in units called a "dish"). There are a total of D (5 <= D <= 100) different kinds of food.  Each kind of food is denoted by an integer in the range 1..D.</p>

<p>The cowrdinator wants to maximize the total number of dishes brought to the party, but has specified a limit for the number of dishes of each type. Each cow can bring K (1 <= K <= 5) dishes, but they must be different from each other (she can't bring 3 bovine pies, for example, but she could bring a pie, some bread, and some nice alfalfa in orange sauce).  What is the maximum amount of food that can be brought?</p>

### 입력 

 <ul>
	<li>Line 1: Three integers: N, K, and D</li>
	<li>Line 2: D non-negative integers: the limit on total number of each of the various dishes that can be brought to the party</li>
	<li>Lines 3..N+2: Each line contains an initial integer Z (1 <= Z <= D) denoting the number of different dishes a cow can prepare; the rest of the line contains Z integers that are the food identifiers, food type 1 first, food type 2 second, etc..</li>
</ul>

### 출력 

 <p>A single line with a single integer that is the maximum number of dishes that can be brought to the party.</p>

