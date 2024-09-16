# [Platinum V] 비밀 회선 - 12985 

[문제 링크](https://www.acmicpc.net/problem/12985) 

### 성능 요약

메모리: 4364 KB, 시간: 24 ms

### 분류

자료 구조, 세그먼트 트리, 정렬

### 제출 일자

2024년 9월 17일 00:22:24

### 문제 설명

<p>Every year, Farmer John's N (1 <= N <= 50,000) cows attend "MooFest",a social gathering of cows from around the world. MooFest involves a variety of events including haybale stacking, fence jumping, pin the tail on the farmer, and of course, mooing. When the cows all stand in line for a particular event, they moo so loudly that the roar is practically deafening. After participating in this event year after year, some of the cows have in fact lost a bit of their hearing.</p>

<p>Each cow i has an associated "hearing" threshold v(i) (in the range 1..50,000). If a cow moos to cow i, she must use a volume of at least v(i) times the distance between the two cows in order to be heard by cow i. If two cows i and j wish to converse, they must speak at a volume level equal to the distance between them times max(v(i),v(j)).</p>

<p>Suppose each of the N cows is standing in a straight line (each cow at some unique x coordinate in the range 1..50,000), and every pair of cows is carrying on a conversation using the smallest possible volume.</p>

<p>Compute the sum of all the volumes produced by all N(N-1)/2 pairs of mooing cows.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer, N</li>
	<li>Lines 2..N+1: Two integers: the volume threshold and x coordinate for a cow. Line 2 represents the first cow; line 3 represents the second cow; and so on.</li>
</ul>

### 출력 

 <p>Line 1: A single line with a single integer that is the sum of all the volumes of the conversing cows.</p>

