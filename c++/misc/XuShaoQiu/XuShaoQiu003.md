# bug
createThread函数中的filePath变量是一个局部变量，它的地址被传递给了theadLoop函数。
由于createThread函数执行完毕后filePath的生命周期结束，这可能导致theadLoop函数中使用到一个无效的指针。
虽然在theadLoop函数中使用了tmpPath数组来复制文件路径，但这个复制发生在theadLoop函数内部，潜在的问题在于传递给线程的原始指针可能已经失效。

# 解决方案
theadLoop 的参数使用 std::string
```c++
void theadLoop(std::string path) 

// createThread函数中
thread = std::thread(theadLoop, std::string(filePath));
```