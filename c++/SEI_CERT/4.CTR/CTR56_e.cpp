
#include <iostream>

// ... definitions for S, T, globI, globD ...
// 假设 S 是一个含有整数变量 i 的简单结构体
struct S {
    int i;
};

// T 可以是 S 的派生类型
struct T : S {
    // 可以添加额外成员，不过因为示例函数 f 只访问了 i，这里不需要额外成员。
};

// 假设 globI 是一个全局的整数变量
int globI = 10;

// 假设 globD 是一个全局的双精度浮点数变量
double globD = 20.0;

void f(const S *someSes, std::size_t count) {
    for (const S *end = someSes + count; someSes != end; ++someSes) {
        std::cout << someSes->i << std::endl;
    }
    for (std::size_t i = 0; i < count; ++i) {
        std::cout << someSes[i].i << std::endl;
    }
}

int main() {
    T test[5];
    f(test, 5);
}
