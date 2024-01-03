# [Platinum II] Landscape Improved - 11746 

[문제 링크](https://www.acmicpc.net/problem/11746) 

### 성능 요약

메모리: 6044 KB, 시간: 60 ms

### 분류

이분 탐색, 두 포인터

### 제출 일자

2024년 1월 3일 17:47:08

### 문제 설명

<p>Louis L Le Roi-Univers has ordered to improve the landscape that is seen from the royal palace. His Majesty prefers to see a high mountain.</p>

<p>The Chief Landscape Manager is going to raise a mountain for Louis. He represents a landscape as a flat picture on a grid of unit squares. Some of the squares are already filled with rock, while others are empty. This greatly simplifies the design. Unit squares are small enough, and the landscape seems to be smooth from the royal palace.</p>

<p>The Chief Landscape Manager has a plan of the landscape — the heights of all rock-filled columns for each unit of width. He is going to add at most n square units of stones atop of the existing landscape to make a mountain with as high peak as possible. Unfortunately, piles of stones are quite unstable. A unit square of stones may be placed only exactly on top of the other filled square of stones or rock, moreover the squares immediately to the bottom-left and to bottom-right of it should be already filled.</p>

<table class="table">
	<tbody>
		<tr>
			<td style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11746/1.png" style="height:94px; width:163px"></td>
			<td style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/11746/2.png" style="height:107px; width:161px"></td>
		</tr>
		<tr>
			<td style="text-align:center">Existing landscape</td>
			<td style="text-align:center">Improved landscape</td>
		</tr>
	</tbody>
</table>

<p>Your task is to help The Chief Landscape Manager to determine the maximum height of the highest mountain he can build.</p>

### 입력 

 <p>The first line of the input file contains two integers w — the width of the existing landscape and n — the maximum number of squares of stones to add (1 ≤ w ≤ 100 000, 0 ≤ n ≤ 10<sup>18</sup>).</p>

<p>Each of the following w lines contains a single integer h<sub>i</sub> — the height of the existing landscape column (1 ≤ h<sub>i</sub> ≤ 10<sup>9</sup>).</p>

### 출력 

 <p>The output file shall contain the single integer — the maximum possible landscape height after at most n unit squares of stones are added in a stable way.</p>

