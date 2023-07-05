# [Platinum V] Random Number Generator - 1160 

[문제 링크](https://www.acmicpc.net/problem/1160) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

분할 정복을 이용한 거듭제곱, 수학

### 문제 설명

<p>DongDong recently became obsessed with randomization, and random number generators is the foundation of randomization. DongDong plans to use the linear congruential method to generate a number sequence. This method requires for non-negative integer parameters m, a, c, X<sub>0</sub>. Then, a random sequence <X<sub>n</sub>> can be generated using the following formula:</p>

<p>X<sub>n+1</sub> = (aX<sub>n</sub> + c) mod m</p>

<p>where "mod m" means to take the remainder after the left hand expression has divided m. It can be observed from this equation that the next number in a sequence will always be based off of the current number.</p>

<p>Sequences generated this way are very random in nature, which is why this method has been used extensively. Even randomization functions in the widely used standard libraries of C++ and Pascal employ this method.</p>

<p>DongDong knows that sequences produced this way are very random, but he is also impatient about wanting to know the value X<sub>n</sub> as soon as possible. Since DongDong needs a random number that's one of 0, 1, …, g-1, he will have to modulo the number X<sub>n</sub> by g to get the final result. All you have to do is determine the value of X<sub>n</sub> mod g for DongDong.</p>

### 입력 

 <p>The input consists of 6 space-separated integers m, a, c, X<sub>0</sub>. n, and g (m, a, c, X<sub>0</sub>, n ≤ 10<sup>18</sup>, g ≤ 10<sup>8</sup>). Here, a, c, and X<sub>0</sub> are non-negative while m, n, g are positive.</p>

### 출력 

 <p>Output a single integer, the value of X<sub>n</sub> mod g.</p>

