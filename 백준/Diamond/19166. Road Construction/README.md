# [Diamond V] Road Construction - 19166 

[문제 링크](https://www.acmicpc.net/problem/19166) 

### 성능 요약

메모리: 18840 KB, 시간: 160 ms

### 분류

이분 매칭

### 제출 일자

2023년 11월 22일 21:38:00

### 문제 설명

<p>There are N cities in the country of Numbata, numbered from 1 to N. Currently, there is no road connecting them. Therefore, each of these N cities proposes a road candidate to be constructed.</p>

<p>City i likes to connect with city A<sub>i</sub>, so city i proposes to add a direct bidirectional road connecting city i and city Ai . It is guaranteed that no two cities like to connect with each other. In other words, there is no pair of integers i and j where A<sub>i</sub> = j and A<sub>j</sub> = i. It is also guaranteed that any pair of cities are connected by a sequence of road proposals. In other words, if all proposed roads are constructed, then any pair of cities are connected by a sequence of constructed road.</p>

<p>City i also prefers the road to be constructed using a specific material. Each material can be represented by an integer (for example, 0 for asphalt, 1 for wood, etc.). The material that can be used for the road connecting city i and city A<sub>i</sub> is represented by an array B<sub>i</sub> containing M<sub>i</sub> integers: [(B<sub>i</sub>)<sub>1</sub>,(B<sub>i</sub>)<sub>2</sub>, . . . ,(B<sub>i</sub>)<sub>M<sub>i</sub></sub>]. This means that the road connecting city i and city A<sub>i</sub> can be constructed with either of the material in B<sub>i</sub>.</p>

<p>There are K workers to construct the roads. Each worker is only familiar with one material, thus can only construct a road with a specific material. In particular, the i<sup>th</sup> worker can only construct a road with material C<sub>i</sub>. Each worker can only construct at most one road. You want to assign each worker to construct a road such that any pair of cities are connected by a sequence of constructed road.</p>

### 입력 

 <p>Input begins with a line containing two integers: N K (3 ≤ N ≤ 2000; 1 ≤ K ≤ 2000) representing the number of cities and the number of workers, respectively. The next N lines each contains several integers: A<sub>i</sub> M<sub>i</sub> (B<sub>i</sub>)<sub>1</sub>,(B<sub>i</sub>)<sub>2</sub>, . . . ,(B<sub>i</sub>)<sub>M<sub>i</sub></sub> (1 ≤ A<sub>i</sub> ≤ N; A<sub>i</sub> ≠ i; 1 ≤ M<sub>i</sub> ≤ 10 000; 0 ≤ (B<sub>i</sub>)<sub>1</sub> < (B<sub>i</sub>)<sub>2</sub> < · · · < (B<sub>i</sub>)<sub>M<sub>i</sub></sub> ≤ 10<sup>9</sup>) representing the bidirectional road that city i likes to construct. It is guaranteed that the sum of Mi does not exceed 10 000. It is also guaranteed that no two cities like to connect with each other and any pair of cities are connected by a sequence of road proposals. The next line contains K integers: C<sub>i</sub> (0 ≤ C<sub>i</sub> ≤ 10<sup>9</sup>) representing the material that is familiarized by the workers.</p>

### 출력 

 <p>If it is not possible to assign each worker to construct a road such that any pair of cities are connected by a sequence of constructed road, simply output -1 in a line. Otherwise, for each worker in the same order as input, output in a line two integers (separated by a single space): u and v in any order. This means that the worker constructs a direct bidirectional road connecting city u and v. If the worker does not construct any road, output “0 0” (without quotes) instead. Each pair of cities can only be assigned to at most one worker. You may output any assignment as long as any pair of cities are connected by a sequence of constructed road.</p>

