# [Gold III] 고득점 - 3663 

[문제 링크](https://www.acmicpc.net/problem/3663) 

### 성능 요약

메모리: 9916 KB, 시간: 176 ms

### 분류

브루트포스 알고리즘, 그리디 알고리즘

### 문제 설명

<p>You’ve just been playing a video game in which you had to move a worm through a maze using a joystick. You got the high score, and now you have to enter your name using this joystick. This works as follows.</p>

<p>The initial name displayed on the screen is a string consisting only of 'A' characters. Initially the first letter of the string is selected. When you move the joystick forward, the selected letter is changed to the letter that immediately follows it in the alphabet. When you move the joystick backward, the selected letter is changed to the letter that immediately precedes it in the alphabet. The alphabet wraps around , so the letter following 'Z' is 'A' and the letter preceding 'A' is 'Z'.</p>

<p>Moving the joystick left or right changes the selection one step to the left or right, respectively. The selection also wraps around, so moving left when the first letter is selected will select the last letter and vice versa.</p>

<p>Because you would like to spend as little time as possible on entering your name, you want to know the smallest possible number of joystick moves needed to do this. Given the name you want to enter, write a program that calculates the minimum number of moves needed. You may assume that the length of the initial string is the same as the length of the name that you want to enter. Furthermore, it does not matter which letter is selected at the end of the process.</p>

### 입력 

 <p>On the ﬁrst line a positive integer: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>One line with a string s (1 ≤ length(s) ≤ 1 000) consisting of uppercase letters: the name that you want to enter.</li>
</ul>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>One line with an integer: the minimum number of joystick moves needed.</li>
</ul>

