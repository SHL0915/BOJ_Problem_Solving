# [Platinum IV] 암호화 알고리즘의 약점 - 2271 

[문제 링크](https://www.acmicpc.net/problem/2271) 

### 성능 요약

메모리: 99968 KB, 시간: 1244 ms

### 분류

자료 구조, 세그먼트 트리, 희소 배열

### 문제 설명

<p>Cheolsoo is a cryptographer in ICPC(International Cryptographic Program Company). Recently, Cheolsoo developed a cryptographic algorithm called ACM(Advanced Cryptographic Method). ACM uses a key to encrypt a message. The encrypted message is called a cipher text. In ACM, to decrypt a cipher text, the same key used in the encryption should be applied. That is, the encryption key and the decryption key are the same. So, the sender and receiver should agree on a key before they communicate securely using ACM. Soon after Cheolsoo finished the design of ACM, he asked its analysis on security to Younghee who is a cryptanalyst in ICPC.</p>

<p>Younghee has an interest in breaking cryptosystems. Actually, she developed many attacking methods for well-known cryptographic algorithms. Some cryptographic algorithms have weak keys. When a message is encrypted with a weak key, the message can be recovered easily without the key from the cipher text. So, weak key should not be used when encrypting a message. After many trials, she found the characteristic of weak keys in ACM. ACM uses a sequence of mutually distinct positive integers (N<sub>1</sub>, N<sub>2</sub>, ..., N<sub>k</sub>) as a key.</p>

<p>Younghee found that weak keys in ACM have the following two special patterns:</p>

<p>There are four integers N<sub>p</sub>, N<sub>q</sub>, N<sub>r</sub>, N<sub>s</sub> (1 ≤ p < q < r < s ≤ k) in the key such that<br>
(1) N<sub>q</sub> > N<sub>s</sub> > N<sub>p</sub> > N<sub>r</sub> or (2) N<sub>q</sub> < N<sub>s</sub> < N<sub>p</sub> < N<sub>r</sub></p>

<p>For example, the key (10, 30, 60, 40, 20, 50) has the pattern in (1); (_ , 30, 60, _ , 20, 50). So, the key is a weak key in ACM. But, the key (30, 40, 10, 20, 80, 50, 60, 70) is not weak because it does not have any pattern in the above.</p>

<p>Now, Younghee wants to find an efficient method to determine, for a given key, whether it is a weak key or not. Write a program that can help Younghee.</p>

### 입력 

 <p>The input consists of T test cases. The number of test cases T is give in the first line of the input file. Each test case starts with a line containing an integer k, the length of a sequence representing a key, 4 ≤ k ≤ 5,000. In the next line, k mutually distinct positive integers are given. There is a single space between the integers, and the integers are between 1 and 100,000, both inclusive.</p>

### 출력 

 <p>Print exactly one line for each test case. Print YES if the sequence is a weak key. Otherwise, print NO.</p>

