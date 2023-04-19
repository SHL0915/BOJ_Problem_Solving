# [Silver II] 뒤집어진 소수 - 10859 

[문제 링크](https://www.acmicpc.net/problem/10859) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 수학, 정수론, 소수 판정

### 문제 설명

<p>Last night, I must have dropped my alarm clock. When the alarm went off in the morning, it showed 51:80 instead of 08:15. This made me realize that if you rotate a seven segment display like it is used in digital clocks by 180 degrees, some numbers still are numbers after turning them upside down.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/f1.png" style="height:80px; width:302px"></p>

<p style="text-align: center;">Figure K.1: Prime number 18115211 on a seven segment display (see third sample).</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/f2.png" style="height:75px; width:300px"></p>

<p style="text-align: center;">Figure K.2: 18115211 turned upside down (i.e. rotated by 180 degrees) gives 11251181, which is not prime.</p>

<p>As you can see,</p>

<ul>
	<li><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/0.png" style="height:34px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/2.png" style="height:34px; line-height:20.7999992370605px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/5.png" style="height:34px; line-height:20.7999992370605px; width:21px">, and <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/8.png" style="height:34px; line-height:20.7999992370605px; width:21px"> still are <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/0.png" style="height:34px; line-height:20.7999992370605px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/2.png" style="height:34px; line-height:20.7999992370605px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/5.png" style="height:34px; line-height:20.7999992370605px; width:21px">, and <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/8.png" style="height:34px; line-height:20.7999992370605px; width:21px">.</li>
	<li><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/1.png" style="height:34px; line-height:20.7999992370605px; width:21px"> is still readable as <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/11.png" style="height:34px; line-height:20.7999992370605px; width:21px"> (only moved left).</li>
	<li><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/6.png" style="height:34px; line-height:20.7999992370605px; width:21px"> turns into <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/9.png" style="height:34px; line-height:20.7999992370605px; width:21px">, while <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/9.png" style="height:34px; line-height:20.7999992370605px; width:21px"> turns into <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/6.png" style="height:34px; line-height:20.7999992370605px; width:21px">.</li>
	<li><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/3.png" style="height:34px; line-height:20.7999992370605px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/4.png" style="height:34px; line-height:20.7999992370605px; width:21px">, and <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/7.png" style="height:34px; line-height:20.7999992370605px; width:21px"> are no longer valid numbers (<img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/E.png" style="height:34px; line-height:20.7999992370605px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/h.png" style="height:34px; line-height:20.7999992370605px; width:21px"> and <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/L.png" style="height:34px; line-height:20.7999992370605px; width:21px">)</li>
</ul>

<p>My favourite numbers are primes, of course. Your job is to check whether a number is a prime and still a prime when turned upside down.</p>

### 입력 

 <p>One line with the integer N in question (1 ≤ N ≤ 10<sup>16</sup>). N will not have leading zeros.</p>

### 출력 

 <p>Print one line of output containing “yes” if the number is a prime and still a prime if turned upside down, “no” otherwise.</p>

