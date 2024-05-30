cmake_minimum_required(VERSION 3.15)  # 指定 CMake 的最小版本要求

project(CON_exe)  # 定义这个子项目的名称

# 搜集源码文件
file(GLOB src_files "*.cpp")

# 创建可执行文件 “CONApp” 从给定的源码文件
add_executable(CONApp ${src_files})