# bug
1. 单行超过 256， 一次读取不完一行。
2. 可能存在内存越界问题
当 ini 有多行配置，总长度超过 4096 时，就会数组越界了，
这个问题在 tv ini 解析的时候遇到过，amp 功放的配置超长，有几万个字符长度。

# 解决方案
1. 使用 std::getline() 函数逐行读取文件 或 使用 C 库的 getline() 函数逐行读取一个文件
2. 使用 std::string 或者 std::stringstream 或者 std::vector<char> 等可变长度数据类型，或者判断数据长度越界时, realloc 内存
