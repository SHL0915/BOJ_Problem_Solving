# [Platinum IV] 시저 암호 - 1893 

[문제 링크](https://www.acmicpc.net/problem/1893) 

### 성능 요약

메모리: 7108 KB, 시간: 1500 ms

### 분류

브루트포스 알고리즘(bruteforcing), KMP(kmp), 문자열(string)

### 문제 설명

<p>In cryptography, a Caesar cipher, also known as Caesar's cipher, the shift cipher, Caesar's code or Caesar shift, is one of the simplest and most widely known encryption techniques. It is a type of substitution cipher in which each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet (wrapping around in the end). For example, given an alphabet of capital letters in usual order, with a shift of 3, A would be replaced by D, B would become E, and so on, with Z being replaced by C. The method is named after Julius C Caesar, who used it in his private correspondence.</p>

<p>We are given an alphabet A, a string S which is encrypted using a shift cipher and a plaintext word W.</p>

<p>Find the possible values of shifts (in the range [0, |A|-1]) used in encryption if we know that the unencrypted text contains exactly one occurrence of the word W.</p>

### 입력 

 <p>Input starts with an integer N on a line, the number of test cases. Each cases contains three strings on separate lines, alphabet A, plaintext word W and encrypted text S. Alphabet A will contain only letters and digits ([A-Z][a-z][0-9]) and its symbol order is not necessarily lexicographical (see the third sample case). A will not contain duplicate symbols. The constraints are as given: 3<=|A|<=62, 1<=|W|<=50,000, 3<=|S|<=500,000.</p>

### 출력 

 <p>For each test case print one line of output. If there are no shifts that would satisfy the condition of W being a part of the unencrypted S, print "no solution". If there is exactly one shift that could have been used, print "unique: #" where # is the shift value. It there are more than one possible shifts print "ambiguous: " followed by the sorted list of shift values.</p>

<p>For clarification, see the sample output.</p>

