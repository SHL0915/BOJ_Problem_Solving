# [Platinum IV] 라디오 전송 - 3356 

[문제 링크](https://www.acmicpc.net/problem/3356) 

### 성능 요약

메모리: 8056 KB, 시간: 8 ms

### 분류

KMP(kmp), 문자열(string)

### 문제 설명

<p>A radio station needs to transmit a message to several recipients. To ensure all listeners get it, the message is played again and again in a continuous loop.</p>

<p>You’re given a sequence of characters received by one of the recipients. It is known the sequence is at least as long as the message.</p>

<p>Your task is to write a program that extracts the message transmitted by the station. More formally, your program needs to ﬁnd the shortest subsequence S′ of the input sequence S such that S in turn is a subsequence of the (sufﬁciently long) repetition S′ + S′ + ··· + S′</p>

### 입력 

 <p>The input is read from standard input. The ﬁrst line contains a single integer L, the length of the sequence S. The second line contains exactly L characters, the sequence S itself. The sequence consists of lowercase letters (a...z).</p>

### 출력 

 <p>The program should write one line to standard output containing a single integer: the length L′ of the message S′. Note that L′ must be the smallest possible.</p>

