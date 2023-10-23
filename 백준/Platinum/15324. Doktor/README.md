# [Platinum IV] Doktor - 15324 

[문제 링크](https://www.acmicpc.net/problem/15324) 

### 성능 요약

메모리: 44548 KB, 시간: 184 ms

### 분류

애드 혹, 누적 합, 정렬

### 제출 일자

2023년 10월 23일 14:36:58

### 문제 설명

<blockquote>
<p>And the Mrs, Ms, says:<br>
“I’ve been riding horses for fifteen years, and it is impossible to shoe a horse upside down!” (...)</p>
</blockquote>

<p>“Yes, that’s upside down” - whispers Domagoj, looking at Mate’s hand while playing, for the purposes of this task, a heavily modified version of the card game Hanabi. For the sake of simplicity, Mate is holding N cards in his hands, numbered from 1, 2, …, N in a certain order. (Each number from 1 to N appears exactly once.) As when playing the real game, he cannot voluntarily change the card order.</p>

<p>Just so the task is at least somewhat related to the story, Domagoj will point for Mate to a contiguous subarray of cards. (He can point to a single card too, but he will point to at least one card.) Mate will then “rotate” that contiguous subarray and put it back.</p>

<p>(The rotating can be thought of as taking all the cards in the given subarray and rotating all of them for 180 degrees. This means that the first and last card swap places, as well as the second and the second to last card, and so on.)</p>

<p>Like all of us, Domagoj is very fond of fixed points. In other words, cards whose numbers match their position in hand, counting from Domagoj’s left side. Therefore, he’d like the number of fixed points to be as great as possible after rotating the given subarray.</p>

<p>Help Domagoj find out which contiguous subarray he needs to point out so that the number of fixed points in Mate’s hand after rotating that subarray is maximal.</p>

### 입력 

 <p>The first line of input contains the positive integer N (1 ≤ N ≤ 500 000), the number of cards in Mate’s hand.</p>

<p>The following line contains the numbers on the cards in Mate’s hand in the order that Domagoj sees them.</p>

### 출력 

 <p>You must output a single line containing A and B, the numbers on the cards that are the beginning and the end of the required contiguous subarray, in that order. If there are multiple options, output any of them.</p>

