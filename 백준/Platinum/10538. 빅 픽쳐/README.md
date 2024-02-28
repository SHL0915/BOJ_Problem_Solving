# [Platinum I] 빅 픽쳐 - 10538 

[문제 링크](https://www.acmicpc.net/problem/10538) 

### 성능 요약

메모리: 37732 KB, 시간: 168 ms

### 분류

아호-코라식, 자료 구조, 해싱, KMP, 문자열, 트리, 트라이

### 제출 일자

2024년 2월 28일 20:12:40

### 문제 설명

<p>Samuel W. E. R. Craft is an artist with a growing reputation. Unfortunately, the paintings he sells do not provide him enough money for his daily expenses plus the new supplies he needs. He had a brilliant idea yesterday when he ran out of blank canvas: "Why don’t I create a gigantic new painting, made of all the unsellable paintings I have, stitched together?". After a full day of work, his masterpiece was complete.</p>

<p>That’s when he received an unexpected phone call: a client saw a photograph of one of his paintings and is willing to buy it now! He had forgotten to tell the art gallery to remove his old works from the catalog! He would usually welcome a call like this, but how is he going to find his old work in the huge figure in front of him?</p>

<p>Given a black-and-white representation of his original painting and a black-and-white representation of his masterpiece, can you help S.W.E.R.C. identify in how many locations his painting might be?</p>

### 입력 

 <p>The first line consists of 4 space-separated integers: h<sub>p</sub> w<sub>p</sub> h<sub>m</sub> w<sub>m</sub>, the height and width of the painting he needs to find, and the height and width of his masterpiece, respectively. The next h<sub>p</sub> lines have w<sub>p</sub> lower-case characters representing his painting. After that, the next h<sub>m</sub> lines have w<sub>m</sub> lower-case characters representing his masterpiece. Each character will be either ‘x’ or ‘o’.</p>

### 출력 

 <p>A single integer representing the number of possible locations where his painting might be.</p>

