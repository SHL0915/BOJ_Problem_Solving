# [Platinum IV] 꼬리달린 박성원숭이 - 2105 

[문제 링크](https://www.acmicpc.net/problem/2105) 

### 성능 요약

메모리: 124624 KB, 시간: 1768 ms

### 분류

자료 구조(data_structures), 분리 집합(disjoint_set), 그래프 이론(graphs), 오프라인 쿼리(offline_queries), 작은 집합에서 큰 집합으로 합치는 테크닉(smaller_to_larger)

### 문제 설명

<p>There are n monkeys on a tree. They are numbered from 1 to n. The monkey number 1 clutches a branch by its tail. Remaining monkeys either are held by other monkeys, hold on to other monkeys or both. Each monkey can use two hands and can hold at most one other monkey in each hand (gripping its tail). Starting from the moment 0, at each second one monkey releases its grip of one hand. This may cause some monkeys fall down onto the ground, where they can continue releasing their grips (the time of falling is negligibly small).</p>

<p>Write a program which:</p>

<ul>
	<li>reads from the standard input the description of how the monkeys hold together and in what order they release their grips,</li>
	<li>for each monkey computes the time it falls down onto the ground,</li>
	<li>writes the result to the standard output.</li>
</ul>

### 입력 

 <p>The first line of the standard input consists of two positive integers n and m, 1 ≤ n ≤ 200 000, 1 ≤ m ≤ 400 000. The number n denotes the number of monkeys, and the number m denotes the time (in seconds) we observe the monkeys. Next n lines contains the description of the initial situation. In the (k+1)-st line (1 ≤ k ≤ n) there are two integers denoting the numbers of monkeys that are hold by the monkey number k. The former is the number of the monkey that is hold by the left hand, and the latter - by the right hand. The number -1 denotes that the monkey's hand is free. The following m lines denote the result of the observation of the monkeys. In the i-th of those lines (1 ≤ i ≤ m) there are two integers. The former is the number of the monkey, and the latter is the number of its hand (1 - left, 2 - right) the monkey releases its grip of, in the moment i-1.</p>

<p> </p>

### 출력 

 <p>Your program should write to the standard output exactly n integers, one per line. The number of the i-th line should denote the moment the i-th monkey fell down onto the ground, or should be equal -1 if the monkey has not fallen down onto the ground during the observation.</p>

<p> </p>

