# [Platinum V] 캔디 분배 - 3955 

[문제 링크](https://www.acmicpc.net/problem/3955) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

확장 유클리드 호제법(extended_euclidean), 수학(math), 정수론(number_theory)

### 문제 설명

<p>Kids like candies, so much that they start beating each other if the candies are not fairly distributed. So on your next party, you better start thinking before you buy the candies.</p>

<p>If there are K kids, we of course need K × X candies for a fair distribution, where X is a positive natural number. But we learned that always at least one kid looses one candy, so better be prepared with exactly one spare candy, resulting in (K × X) + 1 candies. </p>

<p>Usually, the candies are packed into bags with a fixed number of candies C. We will buy some of these bags so that the above constraints are ful lled.</p>

### 입력 

 <p>The fi rst line gives the number of test cases t (0 < t < 100). Each test case is speci ed by two integers K and C on a single line, where K is the number of kids and C the number of candies in one bag (1 ≤ K, C ≤ 10<sup>9</sup>). As you money is limited, you will never buy more than 10<sup>9</sup> candy bags.</p>

### 출력 

 <p>For each test case, print one line. If there is no such number of candy bugs to ful ll the above constraints, print "IMPOSSIBLE" instead. Otherwise print the number of candy bags, you want to buy. If there is more than one solution, any will do.</p>

