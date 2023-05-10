# [Platinum III] 로버트 후드 - 9240 

[문제 링크](https://www.acmicpc.net/problem/9240) 

### 성능 요약

메모리: 3740 KB, 시간: 32 ms

### 분류

볼록 껍질, 기하학, 회전하는 캘리퍼스

### 문제 설명

<p>Robert Hood, a less famous sibling of the Robin Hood, is fed up. Despite him being a young, talented archer he never seems to reach quite the same level as his legendary brother, and so he decided to come up with rules for a new archery contest, in which he will stand a better chance of winning. </p>

<p>The rules for the new kind of archery contest are quite simple: the winner is no longer the one who can score the most points, but instead the one who can achieve the longest distance between any pair of arrows hitting the target. Your task is to write the code to calculate that distance.</p>

<p>A contestant is allowed a number of arrow shots, and the coordinates of the arrows successfully hitting the target are given as a list of pairs. The coordinate system is Cartesian with the origin in the centre of the archery butt. If a contestant does not hit the target with at least two arrows he or she is disqualiﬁed and removed from the input data.</p>

<p>Your task is to calculate the score for one contestant that has not been disqualiﬁed.</p>

### 입력 

 <p>The input starts with a line containing a single positive integer C, 2 ≤ C ≤ 100 000, representing the number of shots successfully hitting the target for this particular contestant. Each following line contains a pair of integer coordinates separated by a space, representing the x-and y-coordinates of a successful shot. The absolute value of any coordinate does not exceed 1 000.</p>

### 출력 

 <p>Print the longest distance between any pair of arrows as a floating point number on a single line. The answer is considered correct if it has a relative or absolute error of less than 10<sup>-6</sup>.</p>

