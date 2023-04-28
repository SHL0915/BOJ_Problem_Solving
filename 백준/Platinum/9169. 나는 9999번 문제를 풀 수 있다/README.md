# [Platinum II] 나는 9999번 문제를 풀 수 있다 - 9169 

[문제 링크](https://www.acmicpc.net/problem/9169) 

### 성능 요약

메모리: 3160 KB, 시간: 44 ms

### 분류

최대 유량, 최대 유량 최소 컷 정리

### 문제 설명

<p>A group of n castle guards are voting to determine whether African swallows can carry coconuts. While each guard has his own personal opinion on the matter, a guard will often vote contrary to his beliefs in order to avoid disagreeing with the votes of his friends.</p>

<p>You are given a list of guards who either do or do not believe in the coconut-carrying capacity of African swallows, and a list of all pairs of guards who are friends. Your task is to determine how each guard must vote in order to minimize the sum of the total number of disagreements between friends and the total number of guards who must vote against their own beliefs.</p>

### 입력 

 <p>The input to this problem will contain multiple test cases. Each test case begins with a single line containing an integer n (where 2 ≤ n ≤ 300), the number of guards, and an integer m (where 0 ≤ m ≤ n(n-1)/2), the number of pairs of guards who are friends. The second line of the test case contains n integers, where the ith integer is 1 if the ith guard believes in the ability of African swallows to carry coconuts, and 0 otherwise. Finally, the next m lines of the test case each contain two distinct integers i and j (where 1 ≤ i, j ≤ n), indicating that guards i and j are friends. Guards within each pair of friends may be listed in any order, but no pair of guards will be repeated. The input is terminated by an invalid test case with n = m = 0, which should not be processed.</p>

### 출력 

 <p>For each input test case, print a single line containing the minimum possible sum of the total number of disagreements between all friends plus the total number of guards who must vote against their own beliefs.</p>

