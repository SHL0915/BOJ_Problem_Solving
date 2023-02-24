# [Platinum II] 격자 0 만들기 - 11495 

[문제 링크](https://www.acmicpc.net/problem/11495) 

### 성능 요약

메모리: 51384 KB, 시간: 2972 ms

### 분류

최대 유량(flow)

### 문제 설명

<p>You are given a grid of nonnegative integers. There is an operation that performs the following two steps on the grid:</p>

<ul>
	<li>Step 1. It chooses two numbers adjacent vertically or horizontally in the grid.</li>
	<li>Step 2. It decreases each number chosen in Step 1 by 1 if it is positive. </li>
</ul>

<p>For example, Figure 1 shows the result of four successive executions of the operation on a 2-by-2 grid of four numbers.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11495/1.png" style="height:68px; width:412px"></p>

<p style="text-align:center">Figure 1. Four successive executions of the operation on a 2-by-2 grid of four numbers</p>

<p>In the above example, the operation was executed four times to make all the numbers in the initial grid to 0. You can easily check there is no way to do so using less number of executions of the operation. </p>

<p>You are to write a program that calculates the minimum number of executions of the operation to make all the numbers in the grid to 0.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing two integers, n and m (2 ≤ n, m ≤ 50), where n is the row size and m is the column size of a grid. In the following n lines, the elements of the grid are given row by row, that is, the i-th line contains m integers which correspond to the elements of the i-th row of the grid in order, for 1 ≤ i ≤ n. Each integer in the grid is between 0 and 1,000, inclusively.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain an integer representing the minimum number of executions of the operations required in the problem.</p>

