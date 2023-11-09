# [Bronze I] 패스트 푸드 상금 - 9329 

[문제 링크](https://www.acmicpc.net/problem/9329) 

### 성능 요약

메모리: 2020 KB, 시간: 4 ms

### 분류

그리디 알고리즘, 구현

### 제출 일자

2023년 11월 9일 23:45:26

### 문제 설명

<p>Around regional contest time, the Canadian branch of a popular fast food restaurant usually runs a game to promote its business. Certain food items provide stickers, and certain collection of different stickers can be converted to cash prizes. If a prize requires sticker types T<sub>1</sub>, T<sub>2</sub>, ... , T<sub>k</sub>, then you can claim the prize if you have 1 sticker of each type T<sub>1</sub>, T<sub>2</sub>, ... , T<sub>k</sub>. Each sticker can only be used to claim one prize. However, you may claim a prize multiple times if you have multiple stickers of the same type. No two prizes will require the same type of stickers. There may be some stickers that cannot be used to claim a cash prize (e.g. a sticker for a free milkshake).</p>

<p>On your road trip to the regional contest, your coach forced you to eat at this restaurant and collected all the stickers together. How much cash can your coach claim?</p>

### 입력 

 <p>The input consists of multiple test cases. The ﬁrst line of input is a single integer, not more than 1000, indicating the number of test cases to follow. Each case starts with a line containing two integers n (1 ≤ n ≤ 10) and m (1 ≤ m ≤ 30), where n is the number of different types of prizes, and m is the number of different types of stickers (the types are labelled 1, 2, ... , m). The next n lines specify the prizes. Each of these lines starts with an integer k (1 ≤ k ≤ m) specifying the number of sticker types required to claim the prize. This is followed by k integers specifying the types of the stickers required. The ﬁnal integer on each line is the (positive) cash value of the prize (at most 1,000,000). The last line of each case gives m nonnegative integers, with the ith integer giving the number of stickers of type i your coach has collected. There are no more than 100 stickers of each type.</p>

### 출력 

 <p>For each case, display on a single line the total value of the cash prizes that can be claimed.</p>

<p> </p>

