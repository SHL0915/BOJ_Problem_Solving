# [Platinum V] 공책 구매 - 5375 

[문제 링크](https://www.acmicpc.net/problem/5375) 

### 성능 요약

메모리: 2100 KB, 시간: 36 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘

### 문제 설명

<p>John wants to buy a large number of widgets. He has already compiled a list of shops that sell the widgets he likes.</p>

<p>Each shop may charge a different price per widget. Additionally, each shop only has a limited number of widgets in stock (and John does not want to order out-of-stock items). Finally, each shop may charge a fixed per-order fee, that John must pay once, if he decides to place an order at that shop. Of course, a single order can include any number of widgets (up to the amount in stock).</p>

<p>You will be given the pricing information for all shops. Your task is to determine how much money John has to spend to obtain the desired number of widgets if he spreads his orders optimally across the various shops.</p>

### 입력 

 <p>On the first line one positive number: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with two space-separated integers n (1 ≤ n ≤ 10 000) and m (1 ≤ m ≤ 100): the number of items to buy and the number of shops available.</li>
	<li>m lines with three space-separated integers s<sub>i</sub> (0 ≤ s<sub>i</sub> ≤ 10 000), p<sub>i</sub> (0 ≤ p<sub>i</sub> ≤ 10 000) and o<sub>i</sub> (0 ≤ o<sub>i</sub> ≤ 1 000 000): the number of items in stock, the price per item and the price per order, for each shop.</li>
</ul>

<p>The desired number of items does not exceed the total number of items available in all shops combined (i.e. n ≤ Σs<sub>i</sub>).</p>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with an integer: the minimum possible total amount of money John needs to spend to obtain n widgets.</li>
</ul>

