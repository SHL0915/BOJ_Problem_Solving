# [Gold I] Charles in Charge - 13465 

[문제 링크](https://www.acmicpc.net/problem/13465) 

### 성능 요약

메모리: 7616 KB, 시간: 156 ms

### 분류

이분 탐색, 데이크스트라, 그래프 이론

### 문제 설명

<p>Every day, Charles drives from his home to work and back. He uses the highways of the country that run from one city to another. Charles has decided that he wants to help the environment by buying an electrical car. Electrical cars, however, are not very common in his country yet. They can only be charged inside a city; there are no charging stations along the highways in between the cities. Moreover, all electrical cars are identical except for one thing: the size of the battery. As batteries are very expensive, Charles would like to buy a car with battery that is as small as possible.</p>

<p>However, this greatly increases the time it takes for him to get home, much to the distaste of his wife, Charlotte. This has spawned an argument, and after much discussion they have decided to compromise: Charlotte is fine with Charles taking a longer route, as long as it its length is at most X% longer than the length of shortest route that Charles could have taken to get home from work by using a regular car. Charles has agreed with this, and he now wants to find a route that minimizes the size of the car battery that he needs, i.e. the route that minimizes the maximum distance that Charles has to drive on a highway without passing through a city.</p>

<p>The amount of time Charles spends to charge his car can be neglected.</p>

### 입력 

 <p>The input starts with integers 2 ≤ N ≤ 10 000, 1 ≤ M ≤ 100 000 and 0 ≤ X ≤ 10 000: the number of cities, the number of highways connecting the cities and the aforementioned percentage X. City 1 is the place where Charles lives and city N is where he works.</p>

<p>Then follow M lines with on each line three integers: 1 ≤ C<sub>1</sub> ≤ N, 1 ≤ C<sub>2</sub> ≤ N, 1 ≤ T ≤ 10<sup>9</sup>. This means that there is a highway of length T connecting cities C<sub>1</sub> and C<sub>2</sub> (Charles can traverse the highway in both directions) without passing through any other cities. You may assume that there exists a path from city 1 to city N.</p>

### 출력 

 <p>The output is a single integer: the smallest maximum distance that Charles has to travel on a highway without passing through a city, such that the route he takes is at most X% longer than the shortest route.</p>

