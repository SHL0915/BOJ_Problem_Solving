# [Gold IV] Binary String - 16584 

[문제 링크](https://www.acmicpc.net/problem/16584) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

그리디 알고리즘

### 문제 설명

<p>A binary string is a non-empty sequence of 0’s and 1’s, e.g., 010110, 1, 11101, etc. Ayu has a favorite binary string S which contains no leading zeroes. She wants to convert S into its decimal representation with her calculator.</p>

<p>Unfortunately, her calculator cannot work on any integer larger than K and it will crash. Therefore, Ayu may need to remove zero or more bits from S while maintaining the order of the remaining bits such that its decimal representation is no larger than K. The resulting binary string also must not contain any leading zeroes.</p>

<p>Your task is to help Ayu to determine the minimum number of bits to be removed from S to satisfy Ayu’s need.</p>

<p>For example, let S = 1100101 and K = 13. Note that 1100101 is 101 in decimal representation, thus, we need to remove several bits from S to make it no larger than K. We can remove the 3<sup>rd</sup>, 5<sup>th</sup>, and 6<sup>th</sup> most significant bits, i.e. 1100101 → 1101. The decimal representation of 1101 is 13, which is no larger than K = 13. In this example, we removed 3 bits, and this is the minimum possible (If we remove only 2 bits, then we will have a binary string of length 5 bits; notice that any binary string of length 5 bits has a value of at least 16 in decimal representation).</p>

### 입력 

 <p>Input begins with a line containing an integer K (1 ≤ K ≤ 2<sup>60</sup>) representing the limit of Ayu’s calculator. The second line contains a binary string S (1 ≤ |S| ≤ 60) representing Ayu’s favorite binary string. You may safely assume S contains no leading zeroes.</p>

### 출력 

 <p>Output contains an integer in a line representing the minimum number of bits to be removed from S.</p>

