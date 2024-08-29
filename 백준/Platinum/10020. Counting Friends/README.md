# [Platinum III] Counting Friends - 10020 

[문제 링크](https://www.acmicpc.net/problem/10020) 

### 성능 요약

메모리: 2028 KB, 시간: 176 ms

### 분류

차수열, 그래프 이론

### 제출 일자

2024년 8월 30일 00:16:55

### 문제 설명

<p>Farmer John's N cows (2 <= N <= 500) have joined the social network "MooBook".</p><p>Each cow has one or more friends with whom they interact on MooBook.  Just for fun, Farmer John makes a list of the number of friends for each of his cows, but during the process of writing the list he becomes distracted, and he includes one extra number by mistake (so his list contains N+1 numbers, instead of N numbers as he intended).</p><p>Please help Farmer John figure out which numbers on his list could have been the erroneous extra number.</p>

### 입력 

 <ul><li>Line 1: The integer N.</li><li>Lines 2..2+N: Line i+1 contains the number of friends for one of FJ's cows, or possibly the extra erroneous number.</li></ul>

### 출력 

 <ul><li>Line 1: An integer K giving the number of entries in FJ's list that could be the extra number (or, K=0 means that there is no number on the list whose removal yields a feasible pairing of friends).</li><li>Lines 2..1+K: Each line contains the index (1..N+1) within the input ordering of a number of FJ's list that could potentially be the extra number -- that is, a number that can be removed such that the remaining N numbers admit a feasible set of friendships among the cows.  These lines should be in sorted order.</li></ul>

