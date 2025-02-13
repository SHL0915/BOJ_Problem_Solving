# [Bronze I] 단어 사다리 - 9229 

[문제 링크](https://www.acmicpc.net/problem/9229) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 구현, 문자열

### 제출 일자

2025년 2월 13일 20:54:34

### 문제 설명

<p>There is a class of word puzzles where you are given two words, such as BEAK and MAKE, and have to get from one to another by changing one letter at a time. Solving such puzzles requires a good vocabulary and some lateral thinking, but checking the solution once you have one is merely tedious and suitable for a computer to do. Note that even correct solutions are not guaranteed to be minimal.</p>

<p>A solution is correct if, for each pair of adjacent words in the ladder, the following apply:</p>

<ul>
	<li>they are the same length</li>
	<li>there is exactly one letter changed.</li>
</ul>

<p>Write a program that will check proposed solutions.</p>

### 입력 

 <p>Input will be a series of solutions. Each solution consists of a series of words, one per line, terminated by a line containing a single #. A word is a sequence of between three and twenty uppercase letters. The file will be terminated by an empty ladder, i.e. another #.</p>

### 출력 

 <p>For each word ladder in the input, output the word ‘Correct’ or ‘Incorrect’ as appropriate.</p>

