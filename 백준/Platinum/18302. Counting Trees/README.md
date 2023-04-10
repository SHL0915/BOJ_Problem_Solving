# [Platinum II] Counting Trees - 18302 

[문제 링크](https://www.acmicpc.net/problem/18302) 

### 성능 요약

메모리: 111280 KB, 시간: 428 ms

### 분류

수학, 자료 구조, 세그먼트 트리, 조합론

### 문제 설명

<p>Your friend Darwin is a very famous naturalist, and tells you that he is currently trying to count the number of varieties of a very particular species of trees he discovered two years ago.</p>

<p>He tells you that these trees are very peculiar. First, they are flat: one of their sides is facing south and the other is facing north. Second, when one of their branches splits, it splits in exactly two sub-branches, which go in two opposite directions: one goes towards the west and the other goes towards the east. All in all, such a tree can be very easily represented as a binary tree such as computer scientists are used to. (Mathematically, a binary tree is either the empty tree or an internal node with exactly two children, which are themselves binary trees.)</p>

<p>As a great programmer, you get excited as soon as you hear about binary trees. Darwin continues his explanations: in such a tree, branches are either horizontal or go up. Still obsessed by binary trees, you figure out that this corresponds to saying that, in the binary tree representation, if internal nodes are labelled by the elevation (distance from the ground) of the corresponding branch split, then the label of a non-root node is always larger than or equal to the label of its parent. Empty trees are not labelled.</p>

<p>While you find this property rather boring and not very interesting, Darwin goes on and tells you a really astonishing and subtle fact he recently discovered about his favorite species of trees. After a lengthy discussion with Darwin, you finally understand that this property can be simply expressed in the binary tree representation. Namely, if one does an inorder traversal of the labelled binary tree of any tree of that species, the resulting sequence of elevations is always the same! (The inorder traversal of the empty tree is the empty sequence and, if a tree is not empty, its inorder traversal is the concatenation of the inorder traversal of the left sub-tree, followed by the label of the top node, followed by the inorder traversal of the right sub-tree.)</p>

<p>After having heard the impressive research results of your friend, you urge him to elaborate on the methodology he uses to count the varieties of this particularly surprising species. This leads him to reveal the hypothesis he is currently working on: every tree of a given variety is represented by the same binary tree, which uniquely identifies that variety. Moreover, every labeled binary tree verifying the conditions above indeed corresponds to an existing variety. Darwin believes that some kind of mathematical tool could then be used to count the varieties, but he has not enough mathematical background to do so.</p>

<p>Now that you are really impressed by Darwin’s work, it is your turn: impress him by writing a program which counts the number of varieties of that species.</p>

### 입력 

 <p>The input consists of the following lines:</p>

<ul>
	<li>on the first line: the number N of elements of the sequence of elevations produced by the inorder traversal of any tree of the species;</li>
	<li>the N following lines represent the sequence of elevations, in millimeters, with one integer per line.</li>
</ul>

### 출력 

 <p>A single line with a single integer, the number of varieties of trees in the species, modulo 1 000 000 007.</p>

