# [Silver II] 주식 - 11501 

[문제 링크](https://www.acmicpc.net/problem/11501) 

### 성능 요약

메모리: 10336 KB, 시간: 4444 ms

### 분류

그리디 알고리즘(greedy)

### 문제 설명

<p>Mr. Lim enjoys investing in stocks. His investment rules are as follows: Given the stock prices of a company for a series of days, each day his action is one of the followings:</p>

<ol>
	<li>Buy one unit of stock.</li>
	<li>Sell any number of stock units you have already bought.</li>
	<li>Do nothing.</li>
</ol>

<p>He wants to know the difference between the profit he obtained and the maximum possible profit by planning the above actions optimally. So, he is trying to calculate the maximum profit that can be obtained by an optimal plan for given the stock prices for a series of days. For example, let the stock prices of three days be 10, 7, and 6. Then the maximum profit is 0 because the price decreases each day. If the stock prices of three days are 3, 5, and 9, the maximum profit is 10 obtained by buying one unit of stock at each of the first two days and selling two stock units at the third day.</p>

<p>You are to write a program calculating the maximum profit that can be obtained by an optimal plan.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing an integer, n (2 ≤ n ≤ 1,000,000), where n is the number of days in a period. In the following line, n integers representing stock prices of the period are given. Each stock price is given as an integer between 1 and 10,000, inclusively.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain the maximum profit. You may assume that the result fits in a signed 64-bit integer.</p>

