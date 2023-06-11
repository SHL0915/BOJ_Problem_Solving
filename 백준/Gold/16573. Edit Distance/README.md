# [Gold II] Edit Distance - 16573 

[문제 링크](https://www.acmicpc.net/problem/16573) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

해 구성하기

### 문제 설명

<p>A binary string is a non-empty sequence of 0’s and 1’s, e.g., 010110, 1, 11101, etc. The edit distance of two binary strings S and T, denoted by edit(S, T), is the minimum number of single-character edit (insert, delete, or substitute) to modify S into T. For example, the edit distance of 0011 and 1100 is 4, i.e. 0011 → 011 → 11 → 110 → 1100. The edit distance of 1100101 and 1110100 is 2, i.e. 1100101 → 1110101 → 1110100.</p>

<p>Ayu has a binary string S. She wants to find a binary string with the same length as S that maximizes the edit distance with S. Formally, she wants to find a binary string Tmax such that |S| = |Tmax| and edit(S, Tmax) ≥ edit(S, T') for all binary string T' satisfying |S| = |T'|.</p>

<p>She needs your help! However, since she wants to make your task easier, you are allowed to return any binary string T with the same length as S such that the edit distance of S and T is more than half the length of S. Formally, you must return a binary string T such that |S| = |T| and edit(S, T) > |S|/2.</p>

<p>Of course, you can still return Tmax if you want, since it can be proven that edit(S, Tmax) > |S|/2 for any binary string S. This also proves that there exists a solution for any binary string S. If there is more than one valid solution, you can output any of them.</p>

### 입력 

 <p>Input contains a binary string S (1 ≤ |S| ≤ 2000).</p>

### 출력 

 <p>Output in a line a binary string T with the same length as S that satisfies edit(S, T) > |S|/2.</p>

