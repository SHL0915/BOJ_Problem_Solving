# [Gold II] 동전 옮기기 - 20047 

[문제 링크](https://www.acmicpc.net/problem/20047) 

### 성능 요약

메모리: 2784 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>Suppose pennies and nickels are arranged on the row. Now we define the ‘two-finger sliding’ on these coins as follows:</p>

<ul>
	<li>Step 1. Choose any two arbitrary coins on the row.</li>
	<li>Step 2. Move them to any position on the row, while keeping their relative order. Note that ‘any position’ contains their original positions (that means one can move only one, or none of coins for the twofinger sliding if their relative order is preserved).</li>
</ul>

<p>The relative order of unchosen coins is also preserved after the two-finger sliding. For example, suppose the initial arrangement of coins is <code>oxox<strong>ox</strong>xxoo</code>, where <code>o</code> and <code>x</code> represent pennies and nickels respectively. Then the following example shows four possible arrangements after one chooses two coins marked in bold and performs exactly one two-finger sliding (note that there are other possible arrangements).</p>

<ul>
	<li><code><strong>ox</strong>oxoxxxoo</code></li>
	<li><code>ox<strong>o</strong>oxxx<strong>x</strong>oo</code></li>
	<li><code>oxox<strong>o</strong>xxo<strong>x</strong>o</code></li>
	<li><code>oxox<strong>ox</strong>xxoo</code></li>
</ul>

<p>Given two arrangements <em>S</em> and <em>T</em> of <em>n</em> coins and the positions of two chosen coins for the two-finger sliding, write a program to decide whether one can change the arrangement from <em>S</em> to <em>T</em> by exactly one two-finger sliding for the specified two coins.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer <em>n</em>, (3 ≤ <em>n</em> ≤ 10,000), where <em>n</em> is the number of coins on the row. In the following two lines, two arrangements <em>S</em> and <em>T</em> of <em>n</em> coins are given where each arrangement is a string of size <em>n</em> from the lowercase alphabet <code>o</code> and <code>x</code>. The next line contains two nonnegative integers <em>i</em> and <em>j</em> which represent the positions of chosen coins for the two-finger sliding. The coin positions are indexed from 0 to <em>n</em> − 1 from left to right, and <em>i</em> is smaller than <em>j</em> (0 ≤ <em>i</em> < <em>j</em> ≤ <em>n</em> − 1).</p>

### 출력 

 <p>Your program is to write to standard output. Print <code>YES</code> if one can change the arrangement from <em>S</em> to <em>T</em> by exactly one two-finger sliding for the specified two coins, and print <code>NO</code> otherwise.</p>

