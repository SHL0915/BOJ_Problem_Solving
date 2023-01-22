# [Gold III] 폰트 - 9997 

[문제 링크](https://www.acmicpc.net/problem/9997) 

### 성능 요약

메모리: 2024 KB, 시간: 96 ms

### 분류

비트마스킹(bitmask), 브루트포스 알고리즘(bruteforcing), 재귀(recursion)

### 문제 설명

<p>Little Ivica got himself a summer job at a company that produces computer fonts. The branch of the company where Ivica works at specialises in testing computer fonts and Ivica's team is responsible of testing only lowercase letters of the English alphabet. </p>

<p>The letters are tested so that various sentences using those letters are printed out and then manually (more accurately, visually) checked if everything is arranged properly. Only sentences which contain all 26 lowercase letter of the English alphabet (a-z) are used for testing purposes. These sentences are called test sentences. </p>

<p>You've probably already assumed that Ivica's job is to find test sentences. He has a dictionary which consists of N words and has to calculate how many different test sentences can be made out of those words. Every word from the dictionary can be used only once in the sentence and the order of the words in the sentence is irrelevant (i.e. “uvijek jedem sarmu” and “jedem sarmu uvijek” are equal sentences). </p>

### 입력 

 <p>The first line of input contains the integer N (1 ≤ N ≤ 25), the number of words in the dictionary. </p>

<p>Each of the following N lines contains a single word from the dictionary, its length not exceeding 100. All the words from the dictionary are going to be unique. </p>

### 출력 

 <p>The first and only line of output must contain the required number from the task. </p>

<p> </p>

