# [Diamond V] Political Development - 22196 

[문제 링크](https://www.acmicpc.net/problem/22196) 

### 성능 요약

메모리: 28064 KB, 시간: 320 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍, 그래프 이론, 수학

### 제출 일자

2024년 11월 29일 15:00:55

### 문제 설명

<p>A certain political party with N members wants to develop some brand new politics. In order to do so, the party plans to make a committee for new political development. Clearly, the best politics is developed when all committee members disagree with each other, and when the committee is as large as possible.</p>

<p>In order to figure out which pairs of politicians disagree and which don’t, the party then arranged for every possible pair of politicians to discuss a randomly selected topic. Whenever two politicians couldn’t agree on their assigned topic, this was recorded in the party’s <em>Book of Great Achievements</em>.</p>

<p>Armed with this book, you have now been assigned the task of finding the largest comittee where everyone disagrees. However, finding a large comittee can prove challenging; careful analysis have revealed that for <em>any</em> non-empty group of party members, there is always at least one member of the group who disagrees with (strictly) less than K of the other group members. Obviously, then, the committee can not have more than K members. But is there a choice of committee of this size? Find the size of a largest possible committe such that nobody in that committee agrees.</p>

### 입력 

 <p>The first line contains two integers, N the number of members in the party, and K as described above. Each member is indicated by an integer i between 0 and N − 1. After the first line follow N lines, one for each politician i, starting with i = 0. The line for politician i begins with an integer D<sub>i</sub>, and is followed by D<sub>i</sub> integers indicating with which other party members the i-th politician disagrees according to the <em>Book of Great Achievements</em>.</p>

### 출력 

 <p>Output a single integer, the size of the largest possible comittee.</p>

