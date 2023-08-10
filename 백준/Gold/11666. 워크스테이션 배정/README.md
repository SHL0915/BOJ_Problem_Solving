# [Gold III] 워크스테이션 배정 - 11666 

[문제 링크](https://www.acmicpc.net/problem/11666) 

### 성능 요약

메모리: 7568 KB, 시간: 112 ms

### 분류

자료 구조, 그리디 알고리즘, 우선순위 큐, 정렬

### 문제 설명

<p>Penelope is part of the admin team of the newly built supercomputer. Her job is to assign workstations to the researchers who come here to run their computations at the supercomputer.</p>

<p>Penelope is very lazy and hates unlocking machines for the arriving researchers. She can unlock the machines remotely from her desk, but does not feel that this menial task matches her qualifications. Should she decide to ignore the security guidelines she could simply ask the researchers not to lock their workstations when they leave, and then assign new researchers to workstations that are not used any more but that are still unlocked. That way, she only needs to unlock each workstation for the first researcher using it, which would be a huge improvement for Penelope.</p>

<p>Unfortunately, unused workstations lock themselves automatically if they are unused for more than m minutes. After a workstation has locked itself, Penelope has to unlock it again for the next researcher using it. Given the exact schedule of arriving and leaving researchers, can you tell Penelope how many unlockings she may save by asking the researchers not to lock their workstations when they leave and assigning arriving researchers to workstations in an optimal way? You may assume that there are always enough workstations available.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with two integers n (1 ≤ n ≤ 300 000), the number of researchers, and m (1 ≤ m ≤ 10<sup>8</sup>), the number of minutes of inactivity after which a workstation locks itself;</li>
	<li>n lines each with two integers a and s (1 ≤ a, s ≤ 10<sup>8</sup>), representing a researcher that arrives after a minutes and stays for exactly s minutes.</li>
</ul>

### 출력 

 <p>Output the maximum number of unlockings Penelope may save herself.</p>

