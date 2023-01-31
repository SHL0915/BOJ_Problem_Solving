# [Gold IV] 전기 요금 - 5710 

[문제 링크](https://www.acmicpc.net/problem/5710) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

이분 탐색(binary_search), 구현(implementation), 수학(math)

### 문제 설명

<p>It’s year 2100. Electricity has become very expensive. Recently, your electricity company raised the power rates once more. The table below shows the new rates (consumption is always a positive integer):</p>

<table class="table table-bordered" style="width:40%">
	<thead>
		<tr>
			<th>Range (Crazy-Watt-hour)</th>
			<th>Price (Americus)</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>1 ~ 100</td>
			<td>2</td>
		</tr>
		<tr>
			<td>101 ~ 10000</td>
			<td>3</td>
		</tr>
		<tr>
			<td>10001 ~ 1000000</td>
			<td>5</td>
		</tr>
		<tr>
			<td>> 1000000</td>
			<td>7</td>
		</tr>
	</tbody>
</table>

<p>This means that, when calculating the amount to pay, the ﬁrst 100 CWh have a price of 2 Americus each; the next 9900 CWh (between 101 and 10000) have a price of 3 Americus each and so on.</p>

<p>For instance, if you consume 10123 CWh you will have to pay 2×100+3×9900+5×123 = 30515 Americus.</p>

<p>The evil mathematicians from the company have found a way to gain even more money. Instead of telling you how much energy you have consumed and how much you have to pay, they will show you two numbers related to yourself and to a random neighbor:</p>

<ul>
	<li>A: the total amount to pay if your consumptions were billed together; and</li>
	<li>B: the absolute value of the diﬀerence between the amounts of your bills.</li>
</ul>

<p>If you can’t ﬁgure out how much you have to pay, you must pay another 100 Americus for such a “service”. You are very economical, and therefore you are sure you cannot possibly consume more than any of your neighbors. So, being smart, you know you can compute how much you have to pay. For example, suppose the company informed you the following two numbers: A = 1100 and B = 300. Then you and your neighbor’s consumptions had to be 150 CWh and 250 CWh respectively. The total consumption is 400 CWh and then A is 2×100+3×300 = 1100. You have to pay 2×100+3×50 = 350 Americus, while your neighbor must pay 2 × 100 + 3 × 150 = 650 Americus, so B is |350 − 650| = 300.</p>

<p>Not willing to pay the additional fee, you decided to write a computer program to ﬁnd out how much you have to pay.</p>

### 입력 

 <p>The input contains several test cases. Each test case is composed of a single line, containing two integers A and B, separated by a single space, representing the numbers shown to you (1 ≤ A, B ≤ 10<sup>9</sup>). You may assume there is always a unique solution, that is, there exists exactly one pair of consumptions that produces those numbers. The last test case is followed by a line containing two zeros separated by a single space.</p>

### 출력 

 <p>For each test case in the input, your program must print a single line containing one integer, representing the amount you have to pay.</p>

