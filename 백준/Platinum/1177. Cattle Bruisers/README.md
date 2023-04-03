# [Platinum V] Cattle Bruisers - 1177 

[문제 링크](https://www.acmicpc.net/problem/1177) 

### 성능 요약

메모리: 6800 KB, 시간: 52 ms

### 분류

수학, 기하학, 많은 조건 분기, 스위핑

### 문제 설명

<p>Canmuu is out for revenge after being utterly defeated by Bessie in paintball and has challenged Bessie to a video game.</p>

<p>In this game, Bessie starts out at point (BX, BY) in the coordinate grid (-1,000 <= BX <= 1,000; -1000 <= BY <= 1,000), and tries to escape, starting at time 0. She moves continuously at a velocity of (BVX, BVY) units/second (-100 <= BVX <= 100; -100 <= BVY <= 100). Thus, at time 1 she will be at point (BX + BVX, BY + BVY); at time 1.5 she will be at (BX + 1.5*BVX, BY + 1.5*BVY).</p>

<p>Unfortunately, Canmuu has sent N (1 <= N <= 50,000) cattle bruisers to pursue Bessie.  At time t=0, cattle bruiser i is at position (X_i, Y_i) (-1,000 <= X_i <= 1,000; -1,000 <= Y_i <= 1,000) with velocity (VX_i, VY_i) units/second (-1,000 <= VX_i <= 1,000; -1,000 <= VY_i <= 1,000).</p>

<p>Each cattle bruiser carries a "proximity" weapon to fire at Bessie; the weapon can hurt Bessie when the cattle bruiser is no further than R (1 <= R <= 2,500) units from her.</p>

<p>Bessie has a shield to protect herself from these attacks. However, she does not want to waste any of her shield's power, so she would like to know the maximum number of cattle bruisers within firing range for any (potentially non-integer) time t >= 0.</p>

<p>In order to avoid precision errors with real numbers, it is guaranteed that the answer produced will be the same whether the attack range is decreased to R-0.0001 or increased to R+0.0001.</p>

### 입력 

 <p>* Line 1: Six space-separated integers: N, R, BX, BY, BVX, and BVY</p>

<p>* Lines 2..N+1: Line i+1 contains four space-separated integers: X_i, Y_i, VX_i, and VY_i</p>

### 출력 

 <p>* Line 1: Print a single integer denoting the maximum number of cattle bruisers within attack range at any point in time.</p>

<p> </p>

