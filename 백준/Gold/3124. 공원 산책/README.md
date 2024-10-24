# [Gold II] 공원 산책 - 3124 

[문제 링크](https://www.acmicpc.net/problem/3124) 

### 성능 요약

메모리: 3172 KB, 시간: 4 ms

### 분류

조합론, 수학, 누적 합

### 제출 일자

2024년 10월 24일 20:25:30

### 문제 설명

<p>Ivica has decided to take a walk in a nearby park. The park contains a total of N+1 water fountains, the largest one in the center of the park. The remaining fountains are arranged in a circle around the largest one. The surrounding fountains are numbered 1 to N and the central is marked N+1. </p>

<p>The surrounding fountains are connected by paths to form a cycle. Each of the surrounding fountains is also connected to the central fountain, for a total of 2·N paths in the park. </p>

<p>Some of the paths are being cleaned by volunteers and are temporarily unusable. </p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/14a64f97-6bbd-41ff-912c-4593c3cc8872/-/preview/" style="width: 127px; height: 117px;"></p>

<p style="text-align: center;">Example park for N=6. All paths are usable.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ae8cd9ec-0f9b-4a9c-bece-f6c0fe09c5b0/-/preview/" style="width: 124px; height: 117px;"></p>

<p style="text-align: center;">Same park with some of the paths unusable. </p>

<p>Ivica starts his walk near some fountain. He proceeds to use paths so that he never visits the same fountain or uses the same path twice. The walk ends when Ivica reaches the fountain where he started. </p>

<p>Write a program that calculates the number of distinct walks Ivica can make. Two walks are different if they don't contain the same paths (so the starting fountain and order of traversal don't matter). For the park in the right image above, there are three walks: 1-2-3-7-6-1, 1-2-3-7-4-5-6-1, and 4-5-6-7-4. </p>

### 입력 

 <p>The first line contains an integer N (2 ≤ N ≤ 100 000), the number of fountains other than the central. </p>

<p>Each of the following two lines contains a string of N characters '0' and '1' describing the availabilities of the paths. A zero in some position represents an unavailable path, while a one represents an available path. The two strings are: </p>

<ol>
	<li>The outer paths, connecting the surrounding fountains. The paths are given in counterclockwise order, starting with the path connecting fountains N and 1. </li>
	<li>The inner paths, connecting surrounding fountains to the central one. The paths are again given in counterclockwise order, starting with the path connecting fountain 1 to the central fountain. </li>
</ol>

### 출력 

 <p>Output the number of distinct walks. </p>

