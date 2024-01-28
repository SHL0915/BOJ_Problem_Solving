# [Platinum IV] 네온 사인 - 8907 

[문제 링크](https://www.acmicpc.net/problem/8907) 

### 성능 요약

메모리: 9920 KB, 시간: 996 ms

### 분류

조합론, 수학

### 제출 일자

2024년 1월 28일 17:10:12

### 문제 설명

<p>JungHeum recently opened a restaurant called 'Triangle' and has ordered the following neon sign for his restaurant. The neon sign has N corners positioned on the circumference of a circle, and N*(N-1)/2 luminous tubes that connect the corners. There are only two colors for luminous tubes, red and blue.</p>

<p>JungHeum wants the sign to show only one shape of a triangle at a time, whose luminous tubes colors are same, continuously. Hence, he wants to know the number of uni-color triangles.</p>

<p>For example, the following neon sign has only two uni-color triangles (1, 3, 5) and (2, 3, 4). </p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/neonsign.png" style="height:312px; width:344px"></p>

<p>Given the number of corners of the neon sign and the colors of the luminous tubes in the sign, write a program that finds the number of uni-color triangles.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with an integer N (3 ≤ N ≤ 1,000), which represents the number of corners of the neon sign. In the following N-1 lines, the information about the color of the luminous tubes are given. For the i-th line of these lines, the color information of the luminous tubes that connect corner i to corners from corner i+1 to N are given. Note that the color red is represented as 1 and the color blue is represented as 0.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain the number of uni-color triangles.</p>

