# 問題

## 1.

正の整数Nが与えられます. 
以下の条件を満たすような整数(a,b,c)の組の個数を求めて下さい.


<img src=
"https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+%0A%5Cbegin%7Balign%2A%7D%0A%261.+%5Cquad+%5Csqrt%7Ba%7D+%2B+%5Csqrt%7Bb%7D+%3D+%5Csqrt%7Bc%7D+%5C%5C%0A%262.+%5Cquad+1+%5Cleq+a%2Cb%2Cc+%5Cleq+N%0A%5Cend%7Balign%2A%7D" 
alt="
\begin{align*}
&1. \quad \sqrt{a} + \sqrt{b} = \sqrt{c} \\
&2. \quad 1 \leq a,b,c \leq N
\end{align*}">

### 制約

<img src=
"https://render.githubusercontent.com/render/math?math=%5Cdisplaystyle+%0A%5Cbegin%7Balign%2A%7D%0A1+%5Cleq+N+%5Cleq+10%5E5%0A%5Cend%7Balign%2A%7D" 
alt="
\begin{align*}
1 \leq N \leq 10^5
\end{align*}">

### 入力
入力は以下の形式で与えられます.

```
N
```

### 出力

条件を満たす(a,b,c)の組の個数を出力してください.

### 入力例1

```
9
```

### 出力例1

```
4
```

(a,b,c)=(1,1,4),(1,4,9),(4,1,9),(2,2,8)の4つがあります.

解答コードは1.cpp
