cmake_minimum_required(VERSION 3.15)  # 指定 CMake 的最小版本要求

project(EXPR_exe)  # 定义这个子项目的名称

# 搜集源码文件
file(GLOB src_files "*.cpp")

add_executable(EXPRApp ${src_files})