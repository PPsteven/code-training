// https://leetcode.cn/problems/range-addition/solution/ren-shi-chai-fen-shu-zu-java-1mstong-guo-nap7/
// 差分数组
// 数组 a[0..n-1] 的差分数组 d[0..n-1]，其定义为：

// 当i=0时，d[0]=a[0]
// 当i>0时，d[i] = a[i]-a[i-1]
// 求差分数组的过程，就是求前缀和数组的逆过程。
// [[1,3,2],[2,4,3],[0,2,-2]]
// 0 0 0 0 0
// 0 2 0 0 -2
// 0 2 3 0 -2
// -2 2 3 2 -2
// 前缀和
// -2 0 3 5 3
