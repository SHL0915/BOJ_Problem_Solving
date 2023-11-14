# [Platinum II] Travelling Merchant - 15843 

[문제 링크](https://www.acmicpc.net/problem/15843) 

### 성능 요약

메모리: 3840 KB, 시간: 8 ms

### 분류

이분 탐색, 플로이드–워셜, 그래프 이론, 매개 변수 탐색, 최단 경로

### 제출 일자

2023년 11월 14일 14:18:35

### 문제 설명

<p>After many days' journey through the great Australian outback, you have finally arrived at the great city of Cobar with nothing but a small backpack. Enamoured by the wonder and beauty of its markets, you decide to become a merchant and make Cobar your new home. Cobar has N markets, numbered from 1 to N, connected by M one-way footpaths, each taking a particular number of minutes to walk along.</p>

<p>The markets of Cobar trade in K different items, numbered from 1 to K. Each market has a fixed price for buying or selling each item. Not every market will trade in every item, and it is possible that for any given item, a market may only support buying it, but not selling it, or vice-versa. You may assume that each market that has a given item for sale has an infinite quantity of it available, and similarly, if a market wants to buy a given item, it is willing to buy it repeatedly, forever.</p>

<p>To earn money as quickly as possible, you would like to find the most efficient profit cycle. A profit cycle is a walk through Cobar that starts at some market v with your backpack empty, continues along Cobar's footpaths and through its markets (possibly buying and selling items along the way), and finally returns to v, again with an empty backpack. It may visit a market and/or walk along a footpath multiple times. Once an item is bought, it must be placed immediately in your backpack and since your backpack is small, it can only hold up to a single item at any point in time. You may assume that you are always able to buy an item if it is available, regardless of the amount of money you possess so far and that you are prohibited from selling an item that you do not possess.</p>

<p>The profit earned from such a cycle is the total amount of money you earned from selling items, minus the total amount of money you spent buying them. The duration of a cycle is the total number of minutes you spend walking along its constituent footpaths. The efficiency of a profit cycle is the profit earned from it, divided by its duration. Note that a profit cycle that does not involve buying or selling any items has an efficiency of 0.</p>

<p>Your task is to find the maximum efficiency among all profit cycles with strictly positive duration. You should report this value rounded down, to the nearest integer. If no such profit cycle exists, you should report 0.</p>

### 입력 

 <p>Your program should read from standard input.</p>

<p>The first line will contain 3 integers, N, M and K : the number of markets, footpaths and items respectively.</p>

<p>N lines follow. The ith of these lines contains 2K integers B<sub>i,1</sub>, S<sub>i,1</sub>, B<sub>i,2</sub>, S<sub>i,2</sub>, ..., B<sub>i,K</sub>, S<sub>i,K</sub> describing a market. For all 1 ≤ j ≤ K, the pair of integers B<sub>i,j</sub> and S<sub>i,j</sub> describe the price at which you can buy and sell item j at market i, respectively. If an item cannot be bought or sold, then -1 will be used as a placeholder.</p>

<p>M lines follow. The pth of these contains 3 integers, V<sub>p</sub>, W<sub>p</sub> and T<sub>p</sub>, describing a one-way footpath from market V<sub>p</sub> to another market W<sub>p</sub>, taking T<sub>p</sub> minutes to traverse.</p>

### 출력 

 <p>Your program should write to standard output.</p>

<p>Print a single integer, the maximum efficiency among all profit cycles, rounded down to the nearest integer.</p>

