# [Platinum I] Bookshelf Sorting - 23857 

[문제 링크](https://www.acmicpc.net/problem/23857) 

### 성능 요약

메모리: 22332 KB, 시간: 408 ms

### 분류

자료 구조, 세그먼트 트리

### 문제 설명

<p>Irma works in a library. Every day she watches visitors take a couple of books from the bookshelf, read them, and put books back in the same places they took them. Usually people mess up the order and swap two books they read. Let's take a look at one specific bookshelf with $n$ books in some order, numbered from $1$ to $n$ from left to right. The $i$-th visitor takes books from positions $x_i$ and $y_i$ and puts them back on the same positions, but in the wrong order. After the $i$-th visitor, the book that was at $x_i$ is now at position $y_i$ and vice versa. </p>

<p>In the evening, after the library is closed, Irma wants to put all the books back on their places. For each book there is a number $p_i$ --- a position where that book should end up in the end. To rearrange books, Irma can take any book from the shelf and insert it in the beginning or in the end (so it ends up in the first or in the last place on the shelf).</p>

<p>What is the minimum number of moves Irma can do to put all books in order? Answer this question for some initial placement of books, determined by $p_i$, and after each visitor that swapped places of some two books.</p>

### 입력 

 <p>The first line contains two integers $n$ and $q$ ($2 \le n \le 2 \cdot 10^5$; $0 \le q \le 2 \cdot 10^5$) --- the number of books on the shelf and the number of visitors. The next line contains $n$ distinct integers $p_i$ ($1 \le p_i \le n$), meaning that the book in the $i$-th position must end up in position $p_i$.</p>

<p>Next $q$ lines describe library's visitors. Each line contains two integers $x_i$, $y_i$ ($1 \le x_i < y_i \le n$), that mean that the $i$-th visitor swapped two books on positions  $x_i$ and $y_i$.</p>

### 출력 

 <p>Print $q + 1$ integers --- the minimum number of moves required to sort all books for the initial order, then for the order the after the first visitor, \ldots, after all $q$ visitors.</p>

