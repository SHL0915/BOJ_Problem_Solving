# [Platinum III] Safe Racing - 13471 

[문제 링크](https://www.acmicpc.net/problem/13471) 

### 성능 요약

메모리: 17644 KB, 시간: 16 ms

### 분류

조합론, 다이나믹 프로그래밍, 수학

### 문제 설명

<p>Tomorrow is racing day. There will be yet another grand prix in yet another country. Beside the safety car, there are various other security measures in order to make sure that everybody is as safe as possible. Among these safety measures are the track marshals: special race officials standing along the track with an assortment of flags that they can use to signal various messages to the drivers. For instance, the yellow flag warns the drivers of a dangerous situation, and the blue flag is used to order a lapped car to make way for one of the faster cars.</p>

<p>Every marshal should be stationed in a so-called marshal booth, a kind of protected cage that is clearly visible from the race track. These booths are located at regular intervals of ten metres (one decametre) along the track. The track is circular and L decametres long and therefore contains exactly L booths.</p>

<p>Not every booth needs to be used. International racing regulations require that the distance between two consecutive marshals should be at most S decametres, meaning that every S consecutive booths should contain at least one marshal. The marshals are not responsible for waving the finish flag, so it is not required (but also not forbidden) to have a marshal at the start/finish.</p>

<p>This leaves you with many ways of assigning marshals to the various booths along the track. Out of sheer curiosity you decide to calculate the total number of valid marshal assignments. Reduce your answer modulo 123 456 789 in case it gets too large.</p>

### 입력 

 <p>The input consists of two integers L, the length of the track, and S, the maximal distance between consecutive marshals along the track, satisfying 1 ≤ S ≤ L ≤ 10<sup>6</sup>.</p>

### 출력 

 <p>Output the integer W, the number of ways to put marshals modulo 123 456 789. (Your answer must satisfy 0 ≤ W < 123 456 789.)</p>

