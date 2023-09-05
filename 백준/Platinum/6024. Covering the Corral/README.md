# [Platinum IV] Covering the Corral - 6024 

[문제 링크](https://www.acmicpc.net/problem/6024) 

### 성능 요약

메모리: 44212 KB, 시간: 76 ms

### 분류

자료 구조, 희소 배열

### 문제 설명

<p>The cows are so modest they want Farmer John to install covers around the circular corral where they occasionally gather. The corral has circumference C (1 <= C <= 1,000,000,000), and FJ can choose from a set of M (1 <= M <= 100,000) covers that have fixed starting points and sizes. At least one set of covers can surround the entire corral.</p>

<p>Cover i can be installed at integer location x_i (distance from starting point around corral) (0 <= x_i < C) and has integer length l_i (1 <= l_i <= C).</p>

<p>FJ wants to minimize the number of segments he must install. What is the minimum number of segments required to cover the entire circumference of the corral?</p>

<p>Consider a corral of circumference 5, shown below as a pair of connected line segments where both '0's are the same point on the corral (as are both 1's, 2's, and 3's).</p>

<p>Three potential covering segments are available for installation:</p>

<pre>           Start   Length
      i     x_i     l_i
      1      0       1 
      2      1       2 
      3      3       3 

        0   1   2   3   4   0   1   2   3  ... 
corral: +---+---+---+---+--:+---+---+---+- ...
        11111               1111
            22222222            22222222
                    333333333333
            |..................|</pre>

<p>As shown, installing segments 2 and 3 cover an extent of (at least) five units around the circumference. FJ has no trouble with the overlap, so don't worry about that.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: C and M</li>
	<li>Lines 2..M+1: Line i+1 contains two space-separated integers: x_i and l_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the minimum number of segments required to cover all segments of the circumference of the corral</li>
</ul>

<p> </p>

