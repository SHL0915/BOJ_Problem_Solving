# [Platinum III] 피보나치 문제해결전략 - 10327 

[문제 링크](https://www.acmicpc.net/problem/10327) 

### 성능 요약

메모리: 2020 KB, 시간: 4 ms

### 분류

확장 유클리드 호제법(extended_euclidean), 수학(math), 정수론(number_theory)

### 문제 설명

<p><a href="https://xkcd.com/587/"><img alt="" src="https://www.acmicpc.net/upload/images2/crime_scene.png" style="float:right; height:425px; width:286px"></a>Undoubtedly you know of the Fibonacci numbers. Starting with F<sub>1</sub> = 1 and F<sub>2</sub> = 1, every next number is the sum of the two previous ones. This results in the sequence 1, 1, 2, 3, 5, 8, 13, . . ..</p>

<p>Now let us consider more generally sequences that obey the same recursion relation</p>

<p style="text-align:center">G<sub>i</sub> = G<sub>i-1</sub> + G<sub>i-2</sub> for i > 2</p>

<p>but start with two numbers G<sub>1</sub> ≤ G<sub>2</sub> of our own choice. We shall call these Gabonacci sequences. For example, if one uses G<sub>1</sub> = 1 and G<sub>2</sub> = 3, one gets what are known as the Lucas numbers: 1, 3, 4, 7, 11, 18, 29, . . .. These numbers are – apart from 1 and 3 – different from the Fibonacci numbers.</p>

<p>By choosing the first two numbers appropriately, you can get any number you like to appear in the Gabonacci sequence. For example, the number n appears in the sequence that starts with 1 and n − 1, but that is a bit lame. It would be more fun to start with numbers that are as small as possible, would you not agree?</p>

### 입력 

 <p>On the first line one positive number: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line with a single integer n (2 ≤ n ≤ 10<sup>9</sup>): the number to appear in the sequence.</li>
</ul>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line with two integers a and b (0 < a ≤ b), such that, for G<sub>1</sub> = a and G<sub>2</sub> = b, G<sub>k</sub> = n for some k. These numbers should be the smallest possible, i.e., there should be no numbers a' and b' with the same property, for which b' < b, or for which b' = b and a' < a.</li>
</ul>

