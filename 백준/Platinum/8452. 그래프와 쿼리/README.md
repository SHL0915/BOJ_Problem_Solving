# [Platinum I] 그래프와 쿼리 - 8452 

[문제 링크](https://www.acmicpc.net/problem/8452) 

### 성능 요약

메모리: 10396 KB, 시간: 620 ms

### 분류

너비 우선 탐색(bfs), 그래프 이론(graphs), 그래프 탐색(graph_traversal), 오프라인 쿼리(offline_queries)

### 문제 설명

<p>Bajtocka Republika Bitowa organizuje przyszłoroczne finały Mistrzostw Świata w Piłce Bitowej. W przygotowaniach bierze udział Bajtazar, który odpowiada za opracowanie planu ewakuacji ze stadionu w każdym mieście, w którym rozgrywane będą mecze. Najwięcej problemów sprawia mu plan ewakuacji dla Bajtogrodu, bo co rusz dostaje informacje o ulicach, które będą zamknięte w trakcie trwania finałów, i musi poprawiać wcześniejsze ustalenia. Co jakiś czas dostaje pytania od działaczy z Bajtockiego Związku Piłki Bitowej. Chcą oni wiedzieć jak szybko można się ewakuować ze stadionu do wskazanego skrzyżowania w mieście.</p>

<p>W Bajtogrodzie jest <em>n</em> skrzyżowań połączonych jednokierunkowymi ulicami. Ewakuacja musi przebiegać zgodnie z kierunkiem ulic. Przebycie każdej ulicy łączącej dwa skrzyżowania zajmuje dokładnie jedną minutę.</p>

<p>Napisz program, który pomoże Bajtazarowi w pracy. Dla podanych informacji o zamknięciach ulic powinien on obliczać odpowiedzi na pytania działaczy.</p>

### 입력 

 <p>W pierwszym wierszu wejścia znajdują się trzy liczby całkowite <em>n</em>, <em>m</em> i <em>q</em> (1 ≤ <em>n</em> ≤ 1 000, 1 ≤ <em>m</em> ≤ 100 000, 1 ≤ <em>q</em> ≤ 200 000) oznaczające kolejno liczbę skrzyżowań w Bajtogrodzie, liczbę łączących je ulic oraz liczbę zapytań. Skrzyżowania są ponumerowane liczbami od 1 do <em>n</em>. Stadion znajduje się przy skrzyżowaniu numer 1. Każdy z kolejnych <em>m</em> wierszy zawiera opis jednej ulicy w postaci dwóch liczb całkowitych <em>a<sub>i</sub></em>, <em>b<sub>i</sub></em> (1 ≤ <em>a<sub>i</sub></em>, <em>b<sub>i</sub></em> ≤ <em>n</em>, <em>a<sub>i</sub></em> ≠ <em>b<sub>i</sub></em>), które oznaczają, że z <em>a<sub>i</sub></em> do <em>b<sub>i</sub></em> prowadzi jednokierunkowa ulica, której przebycie zajmuje jedną minutę. Pomiędzy parą skrzyżowań będzie co najwyżej jedna ulica w każdym kierunku.</p>

<p>W kolejnych <em>q</em> wierszach znajdują się opisy zapytań w kolejności chronologicznej. Opis jednego zapytania składa się ze znaku <em>t<sub>i</sub></em> (<em>t<sub>i</sub></em> ∈ {U, E}) oraz liczby całkowitej <em>p<sub>i</sub></em>.</p>

<p>Zapytanie rozpoczynające się od <em>t<sub>i</sub></em> = U opisuje informację o zamknięciu ulicy. Liczba <em>p<sub>i</sub></em> zawiera się wówczas w przedziale [1,<em>m</em>] i oznacza numer zamkniętej ulicy. Ulice numerujemy zgodnie z kolejnością na wejściu.</p>

<p>Zapytanie rozpoczynające się od <em>t<sub>i</sub></em> = E oznacza pytanie o możliwość ewakuacji do skrzyżowania numer <em>p<sub>i</sub></em> (w tym przypadku 2 ≤ <em>p<sub>i</sub></em> ≤ <em>n</em>). Możesz założyć, że co najmniej jedno zapytanie na wejściu będzie typu <tt>E</tt>.</p>

### 출력 

 <p>Należy wypisać po jednym wierszu dla każdego zapytania typu <tt>E</tt>, w kolejności zgodnej z tą na wejściu. Odpowiedzią dla jednego zapytania jest najkrótszy czas potrzebny na dotarcie ze stadionu do skrzyżowania numer <em>p<sub>i</sub></em>, korzystając jedynie z ulic, które nie zostały wcześniej zamknięte. Jeśli dotarcie do skrzyżowania <em>p<sub>i</sub></em> jest niemożliwe, należy wypisać -1.</p>

