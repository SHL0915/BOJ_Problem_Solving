# [Gold IV] 사탕 줍기 대회 - 5721 

[문제 링크](https://www.acmicpc.net/problem/5721) 

### 성능 요약

메모리: 19720 KB, 시간: 76 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>Little Charlie is a nice boy addicted to candies. He is even a subscriber to All Candies Magazine and was selected to participate in the International Candy Picking Contest.</p>

<p>In this contest a random number of boxes containing candies are disposed in M rows with N columns each (so, there are a total of M × N boxes). Each box has a number indicating how many candies it contains.</p>

<p>The contestant can pick a box (any one) and get all the candies it contains. But there is a catch (there is always a catch): when choosing a box, all the boxes from the rows immediately above and immediately below are emptied, as well as the box to the left and the box to the right of the chosen box. The contestant continues to pick a box until there are no candies left.</p>

<p>The ﬁgure bellow illustrates this, step by step. Each cell represents one box and the number of candies it contains. At each step, the chosen box is circled and the shaded cells represent the boxes that will be emptied. After eight steps the game is over and Charlie picked 10 + 9 + 8 + 3 + 7 + 6 + 10 + 1 = 54 candies.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/candy.png" style="height:322px; width:633px"></p>

<p>For small values of M and N, Charlie can easily ﬁnd the maximum number of candies he can pick, but when the numbers are really large he gets completely lost. Can you help Charlie maximize the number of candies he can pick?</p>

### 입력 

 <p>The input contains several test cases. The ﬁrst line of a test case contains two positive integers M and N (1 ≤ M × N ≤ 10<sup>5</sup>), separated by a single space, indicating the number of rows and columns respectively. Each of the following M lines contains N integers separated by single spaces, each representing the initial number of candies in the corresponding box. Each box will have initially at least 1 and at most 10<sup>3</sup> candies.</p>

<p>The end of input is indicated by a line containing two zeroes separated by a single space.</p>

### 출력 

 <p>For each test case in the input, your program must print a single line, containing a single value, the integer indicating the maximum number of candies that Charlie can pick.</p>

