# [Diamond V] Greedy Knapsack - 26856 

[문제 링크](https://www.acmicpc.net/problem/26856) 

### 성능 요약

메모리: 9860 KB, 시간: 36 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘

### 제출 일자

2024년 3월 8일 18:34:12

### 문제 설명

<p>Budi stumbled upon the classical 0-1 Knapsack Problem that he has learned from his class in university. There are N items numbered from 1 to N. The i<sup>th</sup> item has a positive weight of W<sub>i</sub> and a positive value of V<sub>i</sub>. The objective is to take zero or more items such that their total weight does not exceed M while their total value is maximum.</p>

<p>It has been a while since the last time Budi works on this problem, and he couldn’t remember how to solve it. So, Budi devises a greedy algorithm in an attempt to solve this problem. The algorithm goes like this. Each item is processed one by one from the 1<sup>st</sup> item to the N<sup>th</sup> item in sequential order. If the i<sup>th</sup> item can be taken such that the total weight does not exceed M, then you should take that item; otherwise, ignore it. Output the total value of all taken items.</p>

<p>The greedy algorithm can be presented with the following pseudocode.</p>

<pre>GreedyKnapsack(W[1..N], V[1..N], M):
   total_value = 0
   total_weight = 0
   for i = 1 to N:
      if total_weight + W[i] ≤ M:
         total_weight = total_weight + W[i]
         total_value = total_value + V[i]
   return total_value</pre>

<p>Of course, Budi realized that such a greedy algorithm might not produce the optimum solution, but at this point, he doesn’t care. Budi noticed that the output of such a greedy algorithm is sensitive to M. So, he decides to run the greedy algorithm with various M ranging from 1 to a given upper limit T and determines what is the largest output that he can get.</p>

<p>Your task in this problem is to help Budi to determine the largest output that he can get from the greedy algorithm by varying the input M from 1 to T.</p>

<p>For example, let N = 5, T = 10, W<sub>1..5</sub> = {10, 1, 2, 3, 4}, and V<sub>1.5</sub> = {1, 1, 1, 1, 1}. In this example, the largest output that can be obtained is 3, e.g., with M = 6; the greedy algorithm will take the 2<sup>nd</sup> , 3<sup>rd</sup>, and 4<sup>th</sup> items with a total weight of 1 + 2 + 3 = 6 and a total value of 1 + 1 + 1 = 3. Notice that if we set M = 10, then the greedy algorithm will take only the 1<sup>st</sup> item with a total weight of 10 and a total value of 1.</p>

### 입력 

 <p>Input begins with a line containing two integers N T (1 ≤ N ≤ 100 000; 1 ≤ T ≤ 10<sup>10</sup>) representing the number of items and the upper limit, respectively. The second line contains N integers W<sub>i</sub> (1 ≤ W<sub>i</sub> ≤ 100 000) representing the weight of the i<sup>th</sup> item. The third line contains N integers V<sub>i</sub> (1 ≤ V<sub>i</sub> ≤ 100 000) representing the value of the i<sup>th</sup> item.</p>

### 출력 

 <p>Output contains an integer in a line representing the largest output that can be obtained by the presented greedy algorithm.</p>

