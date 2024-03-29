# [Gold III] 카드 게임 - 11062 

[문제 링크](https://www.acmicpc.net/problem/11062) 

### 성능 요약

메모리: 5932 KB, 시간: 76 ms

### 분류

다이나믹 프로그래밍(dp), 게임 이론(game_theory)

### 문제 설명

<p>Alice is playing a simple but interesting computer game on her computer. The game plays as follows: when Alice starts the game, the computer shows n cards on the monitor in a line. Each card is associated with a number printed on the face and all the cards are faced up so that she can see every number printed on the cards. She and the computer repeatedly pick up a card in turn either from the front or from the rear of the line until there is no card in the line. She always starts the game. In other words, she always picks up a card first. The goal of the game for Alice is to maximize the sum of all the numbers printed on the cards she picks up. She completely understands a strategy to make the sum maximized. Definitely the computer will prevent Alice from making it.</p>

<p>Here is an example. There are four cards in a line and numbers on the cards are (4, 3, 1, 2). Alice first picks up the card of number 4 from the front of the line. Then the computer picks up the card of number 3 from the front. Then Alice picks up the card of number 2 from the rear. Finally, the computer picks up the last card of number 1. This is the best picking order for both Alice and the computer, and Alice makes the sum 6.</p>

<p>You are to make a program that computes the sum of all the numbers on the cards Alice selects among given n cards.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing an integer, n (1 ≤ n ≤ 1,000), where n is the number of cards. In the following line, n numbers are given each of which denotes the number printed on the cards and is separated by a blank. Each number printed on the cards is between 1 and 10,000, inclusive.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain a number which represents the sum of all the numbers printed on the cards Alice selects. </p>

