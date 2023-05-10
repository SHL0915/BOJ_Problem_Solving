# [Platinum III] 쓰레기 슈트 - 4225 

[문제 링크](https://www.acmicpc.net/problem/4225) 

### 성능 요약

메모리: 2044 KB, 시간: 4 ms

### 분류

볼록 껍질, 기하학

### 문제 설명

<p>Allied Chute Manufacturers is a company that builds trash chutes. A trash chute is a hollow tube installed in buildings so that trash dropped in at the top will fall down and be collected in the basement. Designing trash chutes is actually highly nontrivial. Depending on what kind of trash people are expected to drop into them, the trash chute needs to have an appropriate size. And since the cost of manufacturing a trash chute is proportional to its size, the company always would like to build a chute that is as small as possible. Choosing the right size can be tough though.</p>

<p>We will consider a 2-dimensional simplification of the chute design problem. A trash chute points straight down and has a constant width. Objects that will be dropped into the trash chute are modeled as polygons. Before an object is dropped into the chute it can be rotated so as to provide an optimal fit. Once dropped, it will travel on a straight path downwards and will not rotate in flight. The following figure shows how an object is first rotated so it fits into the trash chute.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images/chute.png" style="height:303px; opacity:0.9; width:387px"></p>

<p>Your task is to compute the smallest chute width that will allow a given polygon to pass through.</p>

### 입력 

 <p>The input contains several test cases. Each test case starts with a line containing an integer n (3 ≤ n ≤ 100), the number of points in the polygon that models the trash item.</p>

<p>The next n lines then contain pairs of integers x<sub>i</sub> and y<sub>i</sub> (0 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 10<sup>4</sup>), giving the coordinates of the polygon vertices in order. All points in one test case are guaranteed to be mutually distinct and the polygon sides will never intersect. (Technically, there is one inevitable exception of two neighboring sides sharing their common vertex. Of course, this is not considered an intersection.)</p>

<p>The last test case is followed by a line containing a single zero.</p>

### 출력 

 <p>For each test case, display its case number followed by the width of the smallest trash chute through which it can be dropped. Display the minimum width with exactly two digits to the right of the decimal point, rounding up to the nearest multiple of 1/100. Answers within 1/100 of the correct rounded answer will be accepted.</p>

<p>Follow the format of the sample output.</p>

