# [Platinum I] Stable Planetary System - 26858 

[문제 링크](https://www.acmicpc.net/problem/26858) 

### 성능 요약

메모리: 37168 KB, 시간: 496 ms

### 분류

분할 정복, 기하학

### 제출 일자

2024년 3월 8일 21:06:07

### 문제 설명

<p>Emma, a young astronomer, has just received an award from the International Cosmic and Planetary Committee (the ICPC) for her discovery of a new planetary system along with her novel method in recording the planetary system.</p>

<p>The new planetary system consists of a single star with N planets orbiting it. All these planets are orbiting on the same plane such that they can be drawn easily on a 2-dimensional surface. Moreover, each of these planets has a perfectly circular orbit centered at the star. All planets revolve around the star in the same counter-clockwise direction.</p>

<p>To simplify this problem, the star and each planet are represented by a point and their sizes are negligible. The star is located at the origin.</p>

<p>Through her research, Emma managed to record the location of each planet along with their revolution period (the time needed for a planet to complete one full orbit around the star). Specifically, Emma records <R<sub>i</sub>, θ<sub>i</sub>, T<sub>i</sub>> for each planet where <R<sub>i</sub>, θ<sub>i</sub>> is its polar coordinate and T<sub>i</sub> is its revolution period. A polar coordinate <R<sub>i</sub>, θ<sub>i</sub>> means that its distance to the star is R<sub>i</sub> and its angle from the polar axis (positive x-axis) is θ<sub>i</sub>. To have an integer input, the degree θ<sub>i</sub> is multiplied by 1000, so the value is between 0 and 359 999 (inclusive) representing any degree between 0<sup>◦</sup> and 359.999<sup>◦</sup>.</p>

<p>Emma records all these planets’ positions at the same time, i.e. at time t = 0. Observe that the position of each planet may differ on t > 0 depends on their revolution period, e.g., a planet at <3, 180 000> at t = 0 with a revolution period of 4 unit will be at <3, 270 000> when t = 1 and at <3, 315 000> when t = 1.5; at t = 4 (its revolution period), this planet will complete its orbit and return to <3, 180 000>.</p>

<p>Emma hypothesizes that a planetary system will be much more stable if the planets are not too close to each other. As no analysis has been done on this new planetary system, Emma wants to know the minimum distance among all pairs of planets in this new planetary system. To measure the distance, Emma simply uses the Euclidean distance on a 2-dimensional plane.</p>

<p>The distance between two planets is defined as the closest distance that these two planets can ever achieve, i.e. for any t ∈ [0, ∞). Note that t can be a real number. For example, let there be two planets <3, 180 000, 4> and <4, 0, 2>. The distance between these two planets at t = 0 is 7 unit; their positions are the opposite to each other from the star, i.e. the first planet is at 180<sup>◦</sup> while the second planet is at 0<sup>◦</sup>. When t = 2, the first planet will travel half of its orbit and its position becomes <3, 0>, at the opposite side from its position when t = 0. On the other hand, the second planet will travel one complete orbit so that its position is the same as in when t = 0, i.e. <4, 0>. In this situation, their distance is 1 unit. This is the closest distance these two planets will ever achieve, thus, the distance between these two planets is 1 unit.</p>

<p>Given the position at time t = 0 and the revolution period of each planet, your task is to determine the minimum distance among all pairs of planets. If there exist two planets colliding (being at the same position) for any t > 0, then simply output 0; such a planetary system is not stable.</p>

### 입력 

 <p>Input begins with an integer N (2 ≤ N ≤ 200 000) representing the number of planets in the new planetary system. The next N lines, each contains three integers R<sub>i</sub> θ<sub>i</sub> T<sub>i</sub> (1 ≤ R<sub>i</sub>, T<sub>i</sub> ≤ 10<sup>8</sup>; 0 ≤ θ<sub>i</sub> < 360 000) representing the i<sup>th</sup> planet’s position in a polar coordinate <R<sub>i</sub>, θ<sub>i</sub>> at t = 0, and its revolution period, respectively. The polar coordinate <R<sub>i</sub>, θ<sub>i</sub>> means that the planet’s distance to the star is R<sub>i</sub> and its angle from the polar axis is θ<sub>i</sub>. It is guaranteed that there are no two planets with the same position at t = 0.</p>

### 출력 

 <p>Output contains a single real number representing the minimum distance among all pairs of planets as defined in the problem description. If there exist two planets colliding at a certain time, then output 0. Your answer will be accepted as long as its absolute or relative error does not exceed 10<sup>−6</sup>.</p>

