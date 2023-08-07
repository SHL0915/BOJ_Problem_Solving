# [Platinum I] Guessing Camels - 11672 

[문제 링크](https://www.acmicpc.net/problem/11672) 

### 성능 요약

메모리: 6216 KB, 시간: 3244 ms

### 분류

자료 구조, 세그먼트 트리

### 문제 설명

<p>Jaap, Jan, and Thijs are on a trip to the desert after having attended the ACM ICPC World Finals 2015 in Morocco. The trip included a camel ride, and after returning from the ride, their guide invited them to a big camel race in the evening. The camels they rode will also participate and it is customary to bet on the results of the race.</p>

<p>One of the most interesting bets involves guessing the complete order in which the camels will finish the race. This bet offers the biggest return on your money, since it is also the one that is the hardest to get right.</p>

<p>Jaap, Jan, and Thijs have already placed their bets, but the race will not start until an hour from now, so they are getting bored. They started wondering how many pairs of camels they have put in the same order. If camel c is before camel d on Jaap’s, Jan’s and Thijs’ bet, it means that all three of them put c and d in the same order. Can you help them to calculate the number of pairs of camels for which this happened?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with an integer n (2 ≤ n ≤ 200 000), the number of camels;</li>
	<li>one line with n integers a<sub>1</sub>, . . . , a<sub>n</sub> (1 ≤ a<sub>i</sub> ≤ n for all i), Jaap’s bet. Here a<sub>1</sub> is the camel in the first position of Jaap’s bet, a<sub>2</sub> is the camel in the second position, and so on;</li>
	<li>one line with Jan’s bet, in the same format as Jaap’s bet;</li>
	<li>one line with Thijs’ bet, in the same format as Jaap’s bet.</li>
</ul>

<p>The camels are numbered 1, . . . , n. Each camel appears exactly once in each bet.</p>

### 출력 

 <p>Output the number of pairs of camels that appear in the same order in all 3 bets.</p>

