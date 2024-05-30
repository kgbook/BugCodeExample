# bug
在使用迭代器 iter 遍历集合（包括 list, set, map 等）中，删除元素，
会使得 iter 失效，继续 iter++ 会导致内存访问错误挂掉。

# 解决方案
erase 函数会返回一个有效的 iter, 我们使用 erase 返回的 iter 继续遍历即可
```c++
for (auto iter = list.begin(); iter != list.end(); ) {
    if (*iter == 2) {
        iter = list.erase(iter);
    } else {
        ++iter;
    }
}
```