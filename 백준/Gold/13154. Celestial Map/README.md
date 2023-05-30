# [Gold III] Celestial Map - 13154 

[문제 링크](https://www.acmicpc.net/problem/13154) 

### 성능 요약

메모리: 2500 KB, 시간: 32 ms

### 분류

기하학, 3차원 기하학

### 문제 설명

<p>In the distant future humanity has developed into a highly evolved race with vast knowledge of the universe. In particular, they now have an exhaustive map of all stars in the universe and know their trajectory as well as their speed.</p>

<p>Bob works at the center for interplanetary communication. This is usually the most boring job on the planet, since you sit around all day waiting for other yet unknown races to send messages. Today however, as Bob comes back from his daily ping-pong session, he sees a red light blinking away in his control station. As the light is very annoying and keeps him from napping, he decides to look up its meaning in his manual. It says:</p>

<blockquote>
<p>Congratulations! You have just made contact with another race. Please submit the coordinates of the newly discovered race to the administration office for proper filing. They can be found on panel 42.</p>
</blockquote>

<p>“Neat!” Bob thinks and takes a look at panel 42. Unfortunately, something seems to be broken since instead of showing the coordinates it shows two vectors, a number and “Warning 54816”. Another look at the manual reveals:</p>

<blockquote>
<p>Warning 54816: Something went wrong while calculating the exact coordinates of the message’s origin. Instead a plane from which the message must have come from as well as the origin’s distance were computed.</p>
</blockquote>

<p>After a quick check, Bob finds out that there are quite a few stars whose trajectories intersect with the plane at the given distance, but none that intersect at a slightly different distance (up to 0.1 lightyears). Also, stars which have not been in the plane at the time of the signal transmission were at a distance of at least 0.1 lightyears to the plane. Furthermore, the trajectories of all stars seem to intersect the given plane at an angle between 10 and 90 degrees.</p>

<p>Since Bob wants to plan his afternoon, he first wants to know how many stars he needs to check individually to find out from which one the message originated.</p>

<p>Can you help Bob figure out how many stars fit the description?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with an integer n (1 ≤ n ≤ 10<sup>4</sup>) and a real number d (1.0 ≤ d ≤ 10<sup>5</sup>), where n is the number of stars in the universe and d is the distance from Bob to the message’s origin;</li>
	<li>two lines each with three real numbers p<sub>x</sub>, p<sub>y</sub>, and p<sub>z</sub> (0.0 ≤ p<sub>x</sub>, p<sub>y</sub>, p<sub>z</sub> ≤ 10.0, |(p<sub>x</sub>, p<sub>y</sub>, p<sub>z</sub>)| ≥ 0.1) describing a vector (p<sub>x</sub>, p<sub>y</sub>, p<sub>z</sub>), where the two vectors span a plane from Bob’s location in which the message’s origin must have been in when the message was sent;</li>
	<li>2n lines describing the stars. Each star is described by:
	<ul>
		<li>one line with three real numbers s<sub>x</sub>, s<sub>y</sub>, and s<sub>z</sub> (−1 · 10<sup>6</sup> ≤ s<sub>x</sub>, s<sub>y</sub>, s<sub>z</sub> ≤ 10<sup>6</sup>) where (s<sub>x</sub>, s<sub>y</sub>, s<sub>z</sub>) describes the current location of the star;</li>
		<li>one line with three real numbers t<sub>x</sub>, t<sub>y</sub>, and t<sub>z</sub> (0.1 ≤ |(t<sub>x</sub>, t<sub>y</sub>, t<sub>z</sub>)| ≤ 0.95) where (t<sub>x</sub>, t<sub>y</sub>, t<sub>z</sub>) describes the trajectory of the star. |(t<sub>x</sub>, t<sub>y</sub>, t<sub>z</sub>)| gives the speed at which the star is traveling.</li>
	</ul>
	</li>
</ul>

<p>You can assume the following:</p>

<ul>
	<li>The other civilization’s message travels at the speed of light.</li>
	<li>All speeds are given in lightyears per year, and distances are in lightyears.</li>
	<li>Bob’s location is fixed at (0, 0, 0).</li>
	<li>Stars never collide.</li>
	<li>There are no intersection points of the given plane and any trajectory at distance d ± 0.1 lightyears except for intersection points at distance exactly d lightyears.</li>
	<li>Stars which have not been in the plane at the time of the signal transmission were at a distance of at least 0.1 lightyears to the plane.</li>
	<li>All trajectories intersect the given plane at an angle between 10 and 90 degrees.</li>
</ul>

### 출력 

 <p>Output the number of stars that fit the description.</p>

