# [Platinum IV] Excellent Views - 22268 

[문제 링크](https://www.acmicpc.net/problem/22268) 

### 성능 요약

메모리: 10136 KB, 시간: 96 ms

### 분류

자료 구조, 누적 합, 정렬, 스택, 트리를 사용한 집합과 맵

### 문제 설명

<p>Shiny City is a beautiful city, famous for three things: the fact that it only has one street, the fact that all buildings have different heights, and the breathtaking views from the top of said buildings.</p>

<p>Since the pandemic began, the amount of tourists that visit Shiny City has gone down significantly. You are determined to write an amazing blog to attract more tourists and impede financial doom to your lovely, but terribly inefficient city. Unfortunately, there is still some information missing from the blog.</p>

<p>In Shiny City there are N buildings, and the i-th building is identified by its position i. Going from building i to building j takes |i − j| minutes. Each building has a different height H<sub>i</sub>, and the taller the building, the better the view from its top.</p>

<p>If you are at a certain building, it might be worth going to a different building that has a better view. Because of transportation costs, it’s never worth it to go to a building if there is a taller one that you can reach without using more time.</p>

<p>Formally, we can say that going from building i to another building j is worth it if there is no k such that |i − k| ≤ |i − j| and H<sub>j</sub> < H<sub>k</sub>. Note that k may be equal to i.</p>

<p>You want to write on your blog, for each building, how many other buildings are worth going to from it. Please gather this information, otherwise Shiny City will be forever doomed.</p>

### 입력 

 <p>The first line contains an integer N (1 ≤ N ≤ 10<sup>5</sup>), the number of buildings in Shiny City. The second line contains N different integers H<sub>1</sub>, H<sub>2</sub>, . . . , H<sub>N</sub> (1 ≤ H<sub>i</sub> ≤ 10<sup>9</sup> for i = 1, 2, . . . , N), where H<sub>i</sub> is the height of building i.</p>

### 출력 

 <p>Output a single line with N integers, such that the i-th of them represents the number of buildings worth going to from building i.</p>

