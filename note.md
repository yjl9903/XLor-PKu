# PKu2251

> 2018 - 5 - 18

DFS+回溯超时，BFS可以AC。

# PKu2299 Ultra-QuickSort

> 2018 - 5 - 23

题目要求一个序列的逆序数，使用一个树状数组bit维护了从小到大每个数字出现次数的和，用这个有序的树状数组求得小于等于某个位置所有数的个数。

# PKu1077 Eight

> 2018 - 6 - 22

单向BFS+Hash判重。

Hash判重：

将一个状态压缩成为一个整数，添加到Hash表中，但是由于可能有1e9个状态，内存开不了这么大，故采用取模然后链表的方式。

将Hash压缩的整数取模后得到的Hash值，添加到类似于领接表的大链表中，通过链表进行查找。

> 2018 - 6 - 23

交错双向BFS。

https://blog.csdn.net/thudaliangrx/article/details/50659007

# PKu1611 The Suspects

> 2018 - 6 - 23

并查集裸题。

# PKu2492 A Bug's Life

> 2018 - 6 - 23

二元的权值并查集模板。

# PKu1852 Ants

> 2018 - 6 - 25

忽略两个蚂蚁之间的区别，本质都是交错前进。

# PKu2386 Lake Counting

> 2018 - 6 - 25

dfs求联通块。