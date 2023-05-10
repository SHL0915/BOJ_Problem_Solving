# [Platinum II] 고속도로 - 10254 

[문제 링크](https://www.acmicpc.net/problem/10254) 

### 성능 요약

메모리: 6292 KB, 시간: 640 ms

### 분류

볼록 껍질, 기하학, 회전하는 캘리퍼스

### 문제 설명

<p>There is a country that has n cities. The country decides to build the longest straight highway connecting two cities. The highway may pass through some cities. That is, they want to find two cities that have maximum Euclidean distance over all pairs of the cities. The location of the cities is given by the integral coordinates of 2-dimensional plane. </p>

<p>For the case of following example, the two cities located in (12,0) and (-6,3) are the pairs that has maximum Euclidean distance. </p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images2/highway(1).png" style="height:267px; width:347px"></p>

<p style="text-align:center">Figure 1. An example. </p>

<p>Write a program to find the location of two cities with the maximum Euclidean distance.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with an integer n, the number of cities of the country, where 2 ≤ n ≤ 200,000. Each of the following n lines contains a pair of integers x and y, representing the coordinate of a city. Note that all the coordinates of the cities are distinct, and -10,000,000 ≤ x, y ≤ 10,000,000.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain four integers x1, y1, x2, and y2 that represent two city coordinates (x1, y1) and (x2, y2). If there are multiple such two cities, any one of them will be accepted.</p>

