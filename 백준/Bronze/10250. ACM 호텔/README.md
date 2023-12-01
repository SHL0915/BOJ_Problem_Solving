# [Bronze III] ACM 호텔 - 10250 

[문제 링크](https://www.acmicpc.net/problem/10250) 

### 성능 요약

메모리: 1112 KB, 시간: 0 ms

### 분류

사칙연산, 구현, 수학

### 제출 일자

2023년 12월 2일 02:27:06

### 문제 설명

<p><img alt="" src="https://www.acmicpc.net/upload/images2/acmhotel.png" style="float:right; height:202px; line-height:20.7999992370605px; opacity:0.9; width:294px"></p>

<div> </div>

<p>Jiwoo, the manager of the ACM Hotel, is about to assign the vacant rooms to the guests upon their arrival. According to customers’ survey, the customers prefer the rooms which are close to the main entrance on-walk. Jiwoo likes to assign the rooms on this policy. Write a program to help Jiwoo on assigning the rooms for the guests.</p>

<p>For simplicity, let’s assume that the ACM hotel is a rectangular shape, an H story building with W rooms on each floor (1 ≤ H, W ≤ 99)  and that the only one elevator is on the leftmost side (see Figure 1). Let’s call this kind of hotel as H × W shaped. The main entrance is located on the first floor near the elevator. You may ignore the distance between the gate and the elevator. Also assume that the distances between neighboring rooms are all the same, the unit distance, and that all the rooms only in the front side of the hotel.</p>

<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images2/elevator.png" style="height:312px; line-height:20.7999992370605px; opacity:0.9; text-align:center; width:521px"></p>

<p style="text-align:center">Figure 1. An abstract view of an H × W hotel where H = 6 and W = 12</p>

<p>The rooms are numbered in YXX or YYXX style where Y or YY denotes the number of the floor and XX, the index of the room counted from the left. Therefore the room shaded in Figure 1 should be 305.</p>

<p>The customers do not concern the distance moved in the elevator though the room on the lower floor is preferred than that on the higher floor if the walking distance is same. For instance, the room 301 is preferred than the room 102 since the customer should walk for two units for the latter but one unit, for the former. Additionally, the room 2101 is preferred than the room 102.</p>

<p>Your program should compute the room number which should be assigned for the N-th guest according to this policy assuming that all the rooms are vacant initially. The first guest should be assigned to 101, the second guest to 201, and so on. In Figure 1, for example, the 10th guest should be assigned to the room 402 since H = 6.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case consists of a single line containing and integers H, W, and N: the number of floors, the number of rooms on each floor, and the index of the arrival time of the guest to be assigned a room, respectively, where 1 ≤ H, W ≤ 99 and 1 ≤ N ≤ H × W.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain the room number of the given hotel, where the N-th guest should be assigned.</p>

