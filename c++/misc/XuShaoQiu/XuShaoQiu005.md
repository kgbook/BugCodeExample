# bug
1. 生命周期和临时对象问题
在 showConfigContent 函数中，通过 getConfigPath().c_str(); 获取的 filePath 指针实际上指向了一个临时 std::string 对象的内部数据。
在该行执行结束后，临时对象会被销毁，这使得 filePath 指向的数据变得无效。尝试访问该指针可能会导致未定义行为。

# 解决方案
```c++
void showConfigContent() {
    std::string path = getConfigPath();
    const char *filePath = path.c_str();
    // 其余代码不变
}
```