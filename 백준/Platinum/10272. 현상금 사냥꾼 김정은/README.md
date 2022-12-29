# [Platinum V] 현상금 사냥꾼 김정은 - 10272 

[문제 링크](https://www.acmicpc.net/problem/10272) 

### 성능 요약

메모리: 4088 KB, 시간: 140 ms

### 분류

다이나믹 프로그래밍(dp)

### 문제 설명

<p>Spike is a bounty hunter and he is currently tracking a criminal! To investigate he uses his spaceship, the Swordfish II, and travels to N different places on 2D Euclidean space before returning to his crew at the starting location with all the information he has gathered. The starting location is the leftmost place (with the lowest x-coordinate) and Spike wants to travel to every other place before returning. However space fuel costs a lot of Woolongs and Spike would rather spend his money on special beef with bell peppers. Therefore he wants to travel the minimum possible distance.</p>

<p>On top of that he is being chased by the Red Dragon crime syndicate. To make sure they don’t catch him he can only visit places in increasing order of their x-coordinate until he reaches the rightmost place (with the largest x-coordinate), then he can turn around and visit places in decreasing order of their x-coordinate until he reaches his starting location again.</p>

### 입력 

 <p>The input starts with an integer T (1 ≤ T ≤ 100) specifying the number of test cases that follow. Each test case consists of an integer N (2 ≤ N ≤ 512) specifying the number of places in the tour. The coordinates of these places are given as integers in the next N lines, x-coordinate first, y-coordinate second (0 ≤ x, y ≤ 5000). The places are given in ascending order of the x-coordinate. Every place has a unique x-coordinate.</p>

### 출력 

 <p>For each test case, output on a single line the minimum travel distance needed to complete the tour. Your output should have an absolute or relative error of at most 10<sup>-2</sup>.</p>

