# [Gold II] Kitchen Combinatorics - 11676 

[문제 링크](https://www.acmicpc.net/problem/11676) 

### 성능 요약

메모리: 6132 KB, 시간: 68 ms

### 분류

브루트포스 알고리즘, 조합론, 수학

### 문제 설명

<p>The world-renowned Swedish Chef is planning a gourmet three-course dinner for some muppets: a starter course, a main course, and a dessert. His famous Swedish cook-book offers a wide variety of choices for each of these three courses, though some of them do not go well together (for instance, you of course cannot serve chocolate moose and sooted shreemp at the same dinner).</p>

<p>Each potential dish has a list of ingredients. Each ingredient is in turn available from a few different brands. Each brand is of course unique in its own special way, so using a particular brand of an ingredient will always result in a completely different dinner experience than using another brand of the same ingredient.</p>

<p>Some common ingredients such as pølårber may appear in two of the three chosen dishes, or in all three of them. When an ingredient is used in more than one of the three selected dishes, Swedish Chef will use the same brand of the ingredient in all of them.</p>

<p>While waiting for the meecaroo, Swedish Chef starts wondering: how many different dinner experiences are there that he could make, by different choices of dishes and brands for the ingredients?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line containing five integers r, s, m, d, n, where 1 ≤ r ≤ 1 000 is the number of different ingredients that exist, 1 ≤ s, m, d ≤ 25 are the number of available starter dishes, main dishes, and desserts, respectively, and 0 ≤ n ≤ 2 000 is the number of pairs of dishes that do not go well together.</li>
	<li>one line containing r integers b<sub>1</sub>, . . . , b<sub>r</sub>, where 1 ≤ b<sub>i</sub> ≤ 100 is the number of different brands of ingredient i.</li>
	<li>s + m + d lines describing the s starter dishes, then the m main dishes, then the d desserts. Each such line starts with an integer 1 ≤ k ≤ 20 denoting the number of ingredients of the dish, and is followed by k distinct integers i<sub>1</sub>, . . . , i<sub>k</sub>, where for each 1 ≤ j ≤ k, 1 ≤ i<sub>j</sub> ≤ r is an ingredient.</li>
	<li>n lines each containing two incompatible dishes. Each dish is identified by an integer 1 ≤ j ≤ s + m + d, referring to the j’th dish given in the input (so 1 ≤ j ≤ s refers to the starter dishes, s < j ≤ s + m refers to the main dishes, and s + m < j ≤ s + m + d refers to the desserts).</li>
</ul>

<p>Each pair of incompatible dishes in the input consists of two dishes of different types, and any one pair of dishes is listed at most once.</p>

### 출력 

 <p>If the number of different dinner experiences Swedish Chef can make is at most 1018, then output that number. Otherwise, output “too many”.</p>

