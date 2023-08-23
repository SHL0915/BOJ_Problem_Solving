# [Silver I] 심심한 준규 - 2892 

[문제 링크](https://www.acmicpc.net/problem/2892) 

### 성능 요약

메모리: 2056 KB, 시간: 0 ms

### 분류

애드 혹, 비트마스킹

### 문제 설명

<p>Mirko received a message from his friend Slavko. Slavko, being a world class cryptologist, likes to encrypt messages he sends to Mirko. This time, he decided to use One Time Pad encryption. OTP is impenetrable if used correctly, and Slavko knows this. He however, doesn't want Mirko to bang his head on an impossible task, so he sent a few hints along with his message.</p>

<p>Mirko knows that Slavkos original plaintext contained only small letters of the English alphabet ('a' - 'z'), full stop '.' and space ' ' (ASCII 32<sub>10</sub>). Also, he knows that Slavko used only digits '0' to '9' as his key. After much thought, he realized he can determine locations of all spaces and full stops in the plaintext. He now asked you to write a program that will do so automatically.</p>

<p>From his previous dealings with Slavko, Mirko knows how OTP encryption works. Let's look at a simple example. Suppose you want to encode the string "abc efg" using "0120123" as key.</p>
<table class="table table-bordered td-center th-center">
	<tbody>
		<tr>
			<td>
			<pre>abc efg
0120123</pre>
			</td>
			<td>
			<pre>61 62 63 20 65 66 67
30 31 32 30 31 32 33</pre>
			</td>
			<td>
			<pre>51 53 51 10 54 54 54</pre>
			</td>
		</tr>
	</tbody>
	<tfoot>
		<tr>
			<th>Start</th>
			<th>ASCII hexadecimal</th>
			<th>excrypted message</th>
		</tr>
	</tfoot>
</table>


<p>First, you transform both the key and plaintext into hexadecimal numbers using ASCII encoding. Then you align them and preform XOR operation on each pair. The resulting sequence is the encrypted message.</p>

### 입력 

 <p>The first line of input contains one integer N (1 ≤ N ≤ 1000), number of characters in the encrypted message.</p>

<p>Next line contains N integers, written in hexadecimal, larger than or equal to 0<sub>10</sub> and smaller than or equal to 127<sub>10</sub>, the encrypted message.</p>

### 출력 

 <p>The first and only line of output should contain N characters, each representing one character in the plaintext. If the i<sup>th</sup> character of plaintext is a letter, the i<sup>th</sup> character of output should be a dash '-', if not, you should output a full stop '.'.</p>

