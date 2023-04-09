# [Platinum I] Going Dutch - 15009 

[문제 링크](https://www.acmicpc.net/problem/15009) 

### 성능 요약

메모리: 174052 KB, 시간: 1148 ms

### 분류

다이나믹 프로그래밍, 비트마스킹, 비트필드를 이용한 다이나믹 프로그래밍

### 문제 설명

<p>You and your friends have just returned from a beautiful vacation in the mountains of the Netherlands. When on vacation, it’s annoying to split the bill on every expense every time, so you just kept all the receipts from the vacation, and wrote down who paid how much for who. Now, it is time to settle the bill.</p>

<p>You could each take all the receipts showing that someone paid something for you, and then pay that person back. But then you would need a lot of transactions, and you want to keep up the lazy spirit from your trip. In the end, it does not matter who transfers money to whom; as long as in the end, everyone’s balance is 0.</p>

<p>Can you figure out the least number of transactions needed to settle the score? Assume everyone has enough spare cash to transfer an arbitrary amount of money to another person.</p>

### 입력 

 <p>Input consists of</p>

<ul>
	<li>A line containing two integers M, the number of people in the group, with 1 ≤ M ≤ 20, and N, the number of receipts from the trip, with 0 ≤ N ≤ 1000.</li>
	<li>N lines, each with three integers a, b, p, where 0 ≤ a, b < M, and 1 ≤ p ≤ 1000, signifying a receipt showing that person a paid p euros for person b.</li>
</ul>

### 출력 

 <p>Output a single line containing a single integer, the least number of transactions necessary to settle all bills.</p>

