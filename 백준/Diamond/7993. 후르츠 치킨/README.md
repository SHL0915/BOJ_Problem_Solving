# [Diamond V] 후르츠 치킨 - 7993 

[문제 링크](https://www.acmicpc.net/problem/7993) 

### 성능 요약

메모리: 127656 KB, 시간: 1224 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 트리

### 제출 일자

2023년 11월 16일 12:20:28

### 문제 설명

<p>International agreements signed by the Awfully Vast State impose on it transit obligations - it has to enable the transport of nuclear waste from its eastern neighbours power plants to recycling facilities in the West, by means of its railway system. Ecological reasons impose such traffic organization, that the waste-carrying trains leave the territory of the state as quickly as possible.</p>

<p>The railway network in this country has a very peculiar structure. It consists of n cities - railway junctions and n-1 two-way railway track segments, connecting the junctions. Transport is possible between each pair of cities. Furthermore, there is a section of the railway track, whose ends are not border cities and every connection from the eastern to the western border has to lead through that very section.</p>

<p>All waste-carrying trains arrive at the eastern border on the same day, before dawn, at distinct checkpoints, however. For safety reasons the trains only move during the day. Only a single waste-carrying train can move on a given track section at a time, but an unlimited amount of them can wait at a junction. It takes one day for a train to traverse a section of the track. The traffic has to be organized in such a way, that allows each waste-carrying train to reach a distinct destination on the western border.</p>

<p>How many days, at least, do the waste-carrying trains have to spend on the territory of the Awfully Vast State?</p>

<p>Your task is to write a programme which:</p>

<ul>
	<li>reads from the standard input a description of the railway network and border checkpoints at which the waste-carrying trains have arrived,</li>
	<li>finds the minimal number of days the transit has to last,</li>
	<li>writes the solution to the standard output.</li>
</ul>

### 입력 

 <p>The first line of the input contains three integers 1 ≤ n, w, z ≤ 10<sup>6</sup>, n ≥ w+z+2, separated by single spaces. n denotes the number of junctions (which are labelled with 1,…,n), while w and z denote the number of border checkpoints on the eastern and western border, respectively. The checkpoints on the eastern border are labelled with 1,…,w, while those on the western border with n-z+1,…,n.</p>

<p>In the following n-1 lines there is a description of the railway network. Each line contains two distinct integers, 1 ≤ a, b ≤ n, separated by a single space. They denote junctions connected by a section of the railway.</p>

<p>The (n+1)’st line contains a single integer p, 1 ≤ p ≤ w, 1 ≤ p ≤ z, denoting the number of waste-carrying trains. In the next (and last) line of the input there are p distinct integers, all of which are not greater than w, separated by single spaces. These are the numbers of checkpoints on the eastern border, at which the waste-carrying trains have arrived.</p>

### 출력 

 <p>The first and only line of the output should contain exactly one integer, denoting the minimal amount of days the waste have to spend on the territory of the state.</p>

