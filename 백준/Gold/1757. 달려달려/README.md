# [Gold IV] 달려달려 - 1757 

[문제 링크](https://www.acmicpc.net/problem/1757) 

### 성능 요약

메모리: 81044 KB, 시간: 216 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>The cows are trying to become better athletes, so Bessie is running on a track for exactly N (1 ≤ N ≤ 10,000) minutes. During each minute, she can choose to either run or rest for the whole minute.</p>

<p>The ultimate distance Bessie runs, though, depends on her 'exhaustion factor', which starts at 0. When she chooses to run in minute i, she will run exactly a distance of D<sub>i</sub> (1 ≤ D<sub>i</sub> ≤ 1,000) and her exhaustion factor will increase by 1 -- but must never be allowed to exceed M (1 ≤ M ≤ 500).  If she chooses to rest, her exhaustion factor will decrease by 1 for each minute she rests. She cannot commence running again until her exhaustion factor reaches 0. At that point, she can choose to run or rest.</p>

<p>At the end of the N minute workout, Bessie's exaustion factor must be exactly 0, or she will not have enough energy left for the rest of the day.</p>

<p>Find the maximal distance Bessie can run.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and M</li>
	<li>Lines 2..N+1: Line i+1 contains the single integer: D<sub>i</sub></li>
</ul>

### 출력 

 <ul>
	<li>Line 1: A single integer representing the largest distance Bessie can run while satisfying the conditions.</li>
</ul>

