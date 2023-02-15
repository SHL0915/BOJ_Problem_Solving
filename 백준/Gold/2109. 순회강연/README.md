# [Gold III] 순회강연 - 2109 

[문제 링크](https://www.acmicpc.net/problem/2109) 

### 성능 요약

메모리: 2140 KB, 시간: 0 ms

### 분류

자료 구조(data_structures), 그리디 알고리즘(greedy), 우선순위 큐(priority_queue), 정렬(sorting)

### 문제 설명

<p>A supermarket has a set Prod of products on sale. It earns a profit p<sub>x</sub> for each product x∈Prod sold by a deadline d<sub>x</sub> that is measured as an integral number of time units starting from the moment the sale begins. Each product takes precisely one unit of time for being sold. A selling schedule is an ordered subset of products Sell⊆Prod such that the selling of each product x∈Sell, according to the ordering of Sell, completes before the deadline d<sub>x</sub> or just when d<sub>x</sub> expires. The profit of the selling schedule is Profit(Sell)=∑<sub>x∈Sell</sub> p<sub>x</sub> . An optimal selling schedule is a schedule with a maximum profit. </p>

<p>For example, consider the products Prod={a,b,c,d} with (p<sub>a</sub>,d<sub>a</sub>)=(50,2), (p<sub>b</sub>,d<sub>b</sub>)=(10,1), (p<sub>c</sub>,d<sub>c</sub>)=(20,2), and (p<sub>d</sub>,d<sub>d</sub>)=(30,1). The possible selling schedules are listed in table 1. For instance, the schedule Sell={d,a} shows that the selling of product d starts at time 0 and ends at time 1, while the selling of product a starts at time 1 and ends at time 2. Each of these products is sold by its deadline. Sell is the optimal schedule and its profit is 80. </p>

<p>Write a program that reads sets of products from an input text file and computes the profit of an optimal selling schedule for each set of products. </p>

### 입력 

 <p>A set of products starts with an integer 0≤n≤10000, which is the number of products in the set, and continues with n pairs p<sub>i</sub> d<sub>i</sub> of integers, 1≤p<sub>i</sub>≤10000 and 1≤d<sub>i</sub>≤10000, that designate the profit and the selling deadline of the i-th product. White spaces can occur freely in input. Input data terminate with an end of file and are guaranteed correct. </p>

### 출력 

 <p>For each set of products, the program prints on the standard output the profit of an optimal selling schedule for the set. Each result is printed from the beginning of a separate line. </p>

