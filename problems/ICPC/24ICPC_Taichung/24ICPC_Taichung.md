Contest Link: https://codeforces.com/contest/2041

# D. Drunken Maze
#r1700 #最短路 #图论 
题意：困在一个迷宫里，找一条从起点到终点的最短路，且路上只能向同一个方向走3格。
题解：给哥们三观干碎了。其实不难想，图论最短路的底子。
- 四个维度：x，y，方向，走了几格
- 然后用 [[Dijkstra's algorithm]] 的底子，写一个最短路。如果在一个方向上连续走 3 格了就跳过。
- 递推：`dis[tx][ty][i][(i == d ? c + 1 : 0)] = dis + 1`
- Dijkstra：`dis[tx][ty][i][(i == d ? c + 1 : 0)] > dis + 1`，意味存在更优
- 走三格：`if (i == 2) continue;`
补充几个要点：
1. 一个自己的问题：为什么不会走回头路。因为 Dijkstra 初始化所有点无穷大，然后用一步判断保证不会给队列加入路线更短的格子。

代码：![[CodeForces folder/24ICPC_Taichung/D.cpp]]
