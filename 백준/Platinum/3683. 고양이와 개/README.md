# [Platinum II] 고양이와 개 - 3683 

[문제 링크](https://www.acmicpc.net/problem/3683) 

### 성능 요약

메모리: 2708 KB, 시간: 4 ms

### 분류

이분 매칭

### 제출 일자

2024년 4월 13일 14:41:55

### 문제 설명

<p>The latest reality show has hit the TV: “Cat vs. Dog”. In this show, a bunch of cats and dogs compete for the very prestigious BEST PET EVER title. In each episode, the cats and dogs get to show themselves off, after which the viewers vote on which pets should stay and which should be forced to leave the show.</p>

<p>Each viewer gets to cast a vote on two things: one pet which should be kept on the show, and one pet which should be thrown out. Also, based on the universal fact that everyone is either a cat lover (i.e. a dog hater) or a dog lover (i.e. a cat hater), it has been decided that each vote must name exactly one cat and exactly one dog.</p>

<p>Ingenious as they are, the producers have decided to use an advancement procedure which guarantees that as many viewers as possible will continue watching the show: the pets that get to stay will be chosen so as to maximize the number of viewers who get both their opinions satisﬁed. Write a program to calculate this maximum number of viewers.</p>

### 입력 

 <p>On the ﬁrst line one positive number: the number of testcases, at most 100. After that per testcase:</p>

<ul>
	<li>One line with three integers c, d, v (1 ≤ c, d ≤ 100 and 0 ≤ v ≤ 500): the number of cats, dogs, and voters.</li>
	<li>v lines with two pet identiﬁers each. The ﬁrst is the pet that this voter wants to keep, the second is the pet that this voter wants to throw out. A pet identiﬁer starts with one of the characters ‘C’ or ‘D’, indicating whether the pet is a cat or dog, respectively. The remaining part of the identiﬁer is an integer giving the number of the pet (between 1 and c for cats, and between 1 and d for dogs). So for instance, “D42” indicates dog number 42.</li>
</ul>

### 출력 

 <p>Per testcase:</p>

<ul>
	<li>One line with the maximum possible number of satisﬁed voters for the show.</li>
</ul>

