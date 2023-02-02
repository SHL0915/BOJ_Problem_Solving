# [Platinum II] 문자열의 주기 예측 - 1787 

[문제 링크](https://www.acmicpc.net/problem/1787) 

### 성능 요약

메모리: 11928 KB, 시간: 44 ms

### 분류

KMP(kmp), 문자열(string)

### 문제 설명

<p>A string is a finite sequence of lower-case (non-capital) letters of the English alphabet. Particularly, it may be an empty sequence, i.e. a sequence of 0 letters. By A = BC we denotes that A is a string obtained by concatenation (joining by writing one immediately after another, i.e. without any space, etc.) of the strings B and C (in this order). A string P is a prefix of the string A, if there is a string B, that A = PB. In other words, prefixes of A are the initial fragments of A. In addition, if P ≠ A and P is not an empty string, we say, that P is a proper prefix of A.</p>

<p>A string Q is a period of A, If Q is proper prefix of A and A is a prefix (not necessarily a proper one) of the string QQ. For example, the strings <code>abab</code> and <code>ababab</code> are both periods of the string <code>abababa</code>. The maximum period of a string A is the longest of its periods or the empty string, If A doesn't have any period. For example, the maximum period of <code>ababab</code> is <code>abab</code>. The maximum period of <code>abc</code> is the empty string.</p>

<p>Write a programme that:</p>

<ul>
	<li>reads from the standard input the string's length and the string itself,</li>
	<li>calculates the sum of lengths of maximum periods of all its prefixes,</li>
	<li>writes the result to the standard output.</li>
</ul>

### 입력 

 <p>In the first line of the standard input there is one integer k (1 ≤ k ≤ 1 000 000) - the length of the string. In the following line a sequence of exactly k lower-case letters of the English alphabet is written - the string.</p>

<p> </p>

### 출력 

 <p>In the first and only line of the standard output your programme should write an integer - the sum of lengths of maximum periods of all prefixes of the string given in the input.</p>

<p> </p>

