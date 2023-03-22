# [Platinum IV] Elections - 1226 

[문제 링크](https://www.acmicpc.net/problem/1226) 

### 성능 요약

메모리: 75516 KB, 시간: 272 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘, 정렬, 배낭 문제

### 문제 설명

<p>The citizens of Byteland have recently been voting in the parliamentary elections. Now, when the results have been published, the parties have to decide on a coalition to form the government.</p>

<p>Each party received a certain number of seats in the parliament. The coalition must be a subset of the parties such that together they have strictly more than half of all the seats in the parliament. It is desirable for the coalition to have as many seats as possible, to ensure they can still pass their proposed laws even if a few of their members are absent from a parliament session.</p>

<p>A coalition is called redundant if one of its parties can be removed with the remaining ones still having more than half of the seats in the parliament. Of course, such a removable party would eﬀectively have no power — the other members of the coalition would be able to force the laws regardless of its opinion.</p>

<p>Write a program that:</p>

<ul>
	<li>reads the election results from the standard input,</li>
	<li>ﬁnds a non-redundant coalition that has the maximal possible number of seats in the parliament,</li>
	<li>writes the description of this coalition to the standard output.</li>
</ul>

### 입력 

 <p>The ﬁrst line of the standard input contains one integer n (1 ≤ n ≤ 300) — the number of parties that participated in the elections. The parties are numbered from 1 to n.</p>

<p>The second line contains n nonnegative integers a<sub>1</sub>,..., a<sub>n</sub>, separated by single spaces, where a<sub>i</sub> is the number of seats received by the i-th party. You may assume that the total number of seats in the parliament will be positive and lower or equal to 100 000 .</p>

### 출력 

 <p>The ﬁrst line of the standard output should contain one integer k — the number of parties in a non-redundant coalition which has the maximal number of seats.</p>

<p>The second line should contain k distinct integers separated by single spaces — the numbers of parties that form the coalition.</p>

<p>If there are several non-redundant coalitions with the maximal number of seats, you may output any of them. The member parties can be listed in any order.</p>

