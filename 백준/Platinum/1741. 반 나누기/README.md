# [Platinum II] 반 나누기 - 1741 

[문제 링크](https://www.acmicpc.net/problem/1741) 

### 성능 요약

메모리: 33348 KB, 시간: 680 ms

### 분류

자료 구조, 분리 집합, 그래프 이론, 그래프 탐색

### 문제 설명

<p>Bytel is a mobile telephony potentate. Each employee has been issued a company phone, the memory of which holds the numbers of some of his co-workers (all of them have his number in their phones as well). Due to dynamic growth of their operations the board of directors intends to move company headquaters to new office buildings. It has been decided - in order to boost work efficiency - that every pair of employees working in different buildings should know (reciprocally) each others phone number i.e. the memory of their company phone ought to hold necessary phone numbers.</p>

<p>Simultaneously, the board have decided to rent as many office buildings as possible to ensure good working conditions. Help the board of Bytel to plan the number of office buildings and their size in accordance with the aforementioned requirements.</p>

<p>Write a programme which:</p>

<ul>
	<li>reads the description of employees' phone number lists from the standard input</li>
	<li>calculates the maximal number of office buildings and their sizes, satisfying board's conditions</li>
	<li>writes the outcome to the standard output.</li>
</ul>

### 입력 

 <p>The first line of the standard input consists of two integers: n and m (2 ≤ n ≤ 100 000, 1 ≤ m ≤ 2 000 000), separated by single spaces, denoting the number of Bytel employees and the number of pairs of employees who have their numbers in company phones, respectively. The employees are numbered from 1 to n.</p>

<p>Each of the following m lines contains a single pair of integers a<sub>i</sub> and b<sub>i</sub> (1 ≤ a<sub>i</sub> < b<sub>i</sub> ≤ n for 1 ≤ i ≤ m), separated by a single space, denoting that employees ai and bi have their numbers (reciprocally) in company phones' memory. Each pair of integers denoting a pair of employees shall occur once at the most in the standard input.</p>

### 출력 

 <p>The first line of the standard output should contain a single integer: the maximal number of office buildings that Bytel should rent. The second should contain a non-decreasing sequence of positive integers, separated by singe spaces, denoting the sizes of the office buildings (i.e. the numbers of employees working there). Should there exist more than one correct answer - write out any one of them.</p>

