# [Platinum I] 화성 - 2794 

[문제 링크](https://www.acmicpc.net/problem/2794) 

### 성능 요약

메모리: 6116 KB, 시간: 36 ms

### 분류

비트마스킹, 다이나믹 프로그래밍

### 제출 일자

2024년 5월 2일 14:03:30

### 문제 설명

<p>Scientists have discovered some strange bacteria on Mars and are now busy studying them. They have noticed that the number of bacteria is a power of 2, since each bacterium on Mars splits into two new bacteria (dying in the process), and it all started from a single bacterium.</p>

<p>Thus, in the first generation there was a single bacterium. It split into two bacteria of the second generation, which split into four bacteria of the third generation, and so on – until the 2<sup>K</sup> bacteria of generation K+1 that the scientists have discovered. They have numbered the bacteria using numbers from 1 to 2<sup>K</sup> in the following way:</p>

<ul>
	<li>descendants of bacteria of the previous (K<sup>th</sup>) generation are, in this order: {1, 2}, {3, 4}, {5, 6}, ..., {2<sup>K</sup>-1, 2<sup>K</sup>}</li>
	<li>descendants of bacteria of the older ((K-1)<sup>th</sup>) generation are, in this order: {1, 2, 3, 4}, {5, 6, 7, 8}, ..., {2<sup>K</sup>-3, 2<sup>K</sup>-2, 2<sup>K</sup>-1, 2<sup>K</sup>}</li>
	<li>descendants of bacteria of the even older ((K-2)<sup>th</sup>) generation are, in this order: {1, 2, 3, 4, 5, 6, 7, 8}, ..., {2<sup>K</sup>-7, 2<sup>K</sup>-6, 2<sup>K</sup>-5, 2<sup>K</sup>-4, 2<sup>K</sup>-3, 2<sup>K</sup>-2, 2<sup>K</sup>-1, 2<sup>K</sup>}</li>
	<li>...</li>
	<li>descendants of the two bacteria of the second generation are, in this order: {1, 2, ..., 2<sup>K-1</sup>} and {2<sup>K-1</sup> + 1, 2<sup>K-1</sup> + 2, ..., 2<sup>K</sup>}</li>
</ul>

<p>where curly braces denote a set of descendants of a single bacteria. That is, the 2<sup>K</sup> bacteria of the current generation were numbered such that descendants of any older bacterium have consecutive numbers.</p>

<p>Notice that there exist many different permutations of these bacteria which still satisfy the rule that descendants of any older bacterium have consecutive sequence numbers. Scientists want to arrange the bacteria into such a sequence which also has the minimum possible length. The length of a bacteria sequence is the sum of distances between all neighbouring bacteria pairs.</p>

<p>Specifically, there is a certain quantifiable repulsion between every two bacteria, which is the minimum distance between them if they are next to each other in the sequence. (Repulsion plays no role between bacteria that are not immediate neighbours in the sequence.) Given the repulsion values for all bacteria pairs, find the minimum possible length of a bacteria sequence (permutation) satisfying the descendant rule given above.</p>

### 입력 

 <p>The first line of input contains the positive integer K (1 ≤ K ≤ 9) from the problem statement.Each of the following 2<sup>K</sup> lines contains 2<sup>K</sup> integers from the interval [0, 10<sup>6</sup>]. These 2K × 2<sup>K</sup> numbers represent repulsion between bacteria pairs: the number in row m and column n is the repulsion between bacteria m and n. This number will, of course, be equal to the number in row n and column m. For m = n the number will be 0.</p>

### 출력 

 <p style="margin-left: 40px;">The first and only line of output should contain the minimum possible length of a bacteria sequence satisfying the constraints.</p>

