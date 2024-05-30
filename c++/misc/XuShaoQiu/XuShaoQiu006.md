# bug
1. 浮点运算精度丢失问题
非线性映射计算斜率时为浮点运算，会有精度丢失， 浮点数强转成整型时，会直接丢掉小数位，又损失了一部分精度。
实际项目中遇到的问题是ui 层的亮度值（0～100） 经过非线性转换到驱动层的亮度值（实际上是占空比 pwm 0～255），设置给驱动。
再从驱动获取亮度值转换成 ui 层的亮度值时， 跟之前 ui 层设置的值不一样。
比如 ui 层的亮度值 20, 映射到驱动层的亮度值是 104, 再将 104 映射到 ui 层的亮度值是却是 19 了。

# 解决方案
计算结果浮点数转成整数时采用四舍五入法即可
```c++
void mw2SdkNonLinear(uint32_t input, uint32_t *output) {
    ...
    *output = baseValue + (int32_t) (slopValue * diffValue + 0.5);
}

void sdk2MwNonLinear(uint32_t input, uint32_t *output) {
    ...
    *output = baseValue + (int32_t) (slopValue * diffValue + 0.5);
}
```