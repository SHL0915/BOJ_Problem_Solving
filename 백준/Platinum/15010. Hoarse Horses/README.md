# [Platinum I] Hoarse Horses - 15010 

[문제 링크](https://www.acmicpc.net/problem/15010) 

### 성능 요약

메모리: 6572 KB, 시간: 32 ms

### 분류

오일러 지표 (χ=V-E+F), 기하학, 그래프 이론, 선분 교차 판정, 평면 그래프

### 문제 설명

<p>Farmer Bob’s horses all are hoarse and may have a cold - even the pony is a little hoarse! Because of that, all the farm animals need to be individually quarantined. To separate the animals, Farmer Bob has a set of n fences that cannot be crossed. Unfortunately, Farmer Alice has taken all of Farmer Bob’s fences and placed them arbitrarily in the plane! Farmer Bob has no time to rearrange these fences - he must leave them as is.</p>

<p>Help Farmer Bob calculate how many of his prized barnyard animals he can quarantine. That is, Farmer Bob wants to place as many animals inside non-empty regions enclosed by the fences, such that no animal can reach another animal, and no animal can escape to infinity.</p>

<p>Each fence is given by a line segment between two points. It is given that no three fences go through the same point. Fences are allowed to cross each other.</p>

### 입력 

 <ul>
	<li>A single integer 1 ≤ n ≤ 1000, the number of fences.</li>
	<li>Then n lines follow, each with four integers −10<sup>9</sup> ≤ x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, y<sub>2</sub> ≤ 10<sup>9</sup>. These are the endpoints of the fences, each fence is given by a straight line segment between two endpoints.</li>
</ul>

### 출력 

 <p>Output a single line containing a single integer c, the maximum number of animals Farmer Bob can quarantine.</p>

