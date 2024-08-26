# [Platinum II] 홍준이와 울타리 - 2905 

[문제 링크](https://www.acmicpc.net/problem/2905) 

### 성능 요약

메모리: 29972 KB, 시간: 604 ms

### 분류

자료 구조, 덱, 슬라이딩 윈도우

### 제출 일자

2024년 8월 26일 13:54:12

### 문제 설명

<p>Matija needs to paint his old fence. The fence is made from N planks, each 1 cm in width and varying in height. To do this easy and fast, he bought himself a Super Paint Roller Deluxe. The paint roller is X cm wide. The Super Paint Roller Deluxe model comes with a catch, however. Matija must at all times touch the planks with full width of the roller, otherwise paint drops all around and stains everything. Also, the roller must always be parallel to the ground to prevent leakage. This means that in order for Matija to use the roller safely, he needs to select X planks, and paint them from bottom to the top of the lowest plank in one swoop. Then he selects some other X planks, paints them and so on.</p>

<p>This leaves parts of some planks unpainted. Matija will have to paint such parts with a toothbrush. This is obviously quite tedious so he asked you to help him paint as much as possible using the Super Paint Roller Deluxe. Since there is more than one way to do this he is also interested in the painting that requires the minimal number of swoops.</p>

### 입력 

 <p>The first line of input contains two integers N (1 ≤ N ≤ 1 000 000), number of planks, and X (1 ≤ X ≤ 100 000), width of the Super Paint Roller. Width of the Super Paint</p>

<p>Roller will not exceed the width of the fence. The second line of input contains N positive integers, smaller than 1 000 000, heights of planks in the fence.</p>

### 출력 

 <p>The first line of output should contain the smallest possible area Matija will have to paint manually.</p>

<p>The second line of output should contain the smallest number of swoops needed.</p>

