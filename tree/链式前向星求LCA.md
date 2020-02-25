## 链式前向星求LCA

### 题目描述(POJ-1330)

A rooted tree is a well-known data structure in computer science and engineering. An example is shown below:

<div align=center><img src="/assets/poj1330.jpg"/></div>

In the figure, each node is labeled with an integer from {1, 2,...,16}. Node 8 is the root of the tree. Node x is an ancestor of node y if node x is in the path between the root and node y. For example, node 4 is an ancestor of node 16. Node 10 is also an ancestor of node 16. As a matter of fact, nodes 8, 4, 10, and 16 are the ancestors of node 16. Remember that a node is an ancestor of itself. Nodes 8, 4, 6, and 7 are the ancestors of node 7. A node x is called a common ancestor of two different nodes y and z if node x is an ancestor of node y and an ancestor of node z. Thus, nodes 8 and 4 are the common ancestors of nodes 16 and 7. A node x is called the nearest common ancestor of nodes y and z if x is a common ancestor of y and z and nearest to y and z among their common ancestors. Hence, the nearest common ancestor of nodes 16 and 7 is node 4. Node 4 is nearer to nodes 16 and 7 than node 8 is.

For other examples, the nearest common ancestor of nodes 2 and 3 is node 10, the nearest common ancestor of nodes 6 and 13 is node 8, and the nearest common ancestor of nodes 4 and 12 is node 4. In the last example, if y is an ancestor of z, then the nearest common ancestor of y and z is y.

Write a program that finds the nearest common ancestor of two distinct nodes in a tree.

#### Input

The input consists of T test cases. The number of test cases (T) is given in the first line of the input file. Each test case starts with a line containing an integer N , the number of nodes in a tree, 2<=N<=10,000. The nodes are labeled with integers 1, 2,..., N. Each of the next N -1 lines contains a pair of integers that represent an edge --the first integer is the parent node of the second integer. Note that a tree with N nodes has exactly N - 1 edges. The last line of each test case contains two distinct integers whose nearest common ancestor is to be computed.

#### Output

Print exactly one line for each test case. The line should contain the integer that is the nearest common ancestor.

#### Sample Input

```markdown
2
16
1 14
8 5
10 16
5 9
4 6
8 4
4 10
1 13
6 15
10 11
6 7
10 2
16 3
8 1
16 12
16 7
5
2 3
3 4
3 1
1 5
3 5
```

#### Sample Output

```markdown
4
3
```

### AC

* **倍增法**

```c++
#include<iostream>

using namespace std;

int tree_root;  //最后得到的答案
int total, dept[10001], f[10001][21], head[10001];

struct Edge{
  int to, next;
}e[10001];

/**
 * 因为我们要添加无向边，所以from和to都要设置 
 */
void addEdge(int from, int to){
  e[total].to = to;
  e[total].next = head[from];
  head[from] = total++;

  e[total].to = from;
  e[total].next = head[to];
  head[to] = total++;
}

void dfs(int v, int father){
  dept[v] = dept[father] + 1;
  for(int i = 1; (1 << i) <= dept[v]; i++){
    f[v][i] = f[f[v][i - 1]][i - 1];
  }
  for(int i = head[v]; i; i = e[i].next){
    int p1 = e[i].to;
    if(p1 == father)
      continue;
    f[p1][0] = v;
    dfs(p1, v);
  }
}

int lca(int x, int y){
  if(dept[x] < dept[y])
    swap(x, y);
  for(int i = 20; i >= 0; i--){
    if(dept[f[x][i]] >= dept[y])
      x = f[x][i];
    if(x == y)
      return x;
  }
  for(int i = 20; i >= 0; i--){
    if(f[x][i] != f[y][i]){
      y = f[y][i];
      x = f[x][i];
    }
  }
  return f[x][0];
}
```