# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# cmake 增加对C++11支持
add_definitions(-std=c++11)

# 项目信息
project (cpplab)

#查找当前目录下所有源文件，并命名为DIR_SRCS变量
aux_source_directory(. DIR_SRCS)

#添加子目录
add_subdirectory(math)
add_subdirectory(virtual)
add_subdirectory(string)

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})

#添加静态链接库
target_link_libraries(${PROJECT_NAME} math)
target_link_libraries(${PROJECT_NAME} virtual)
target_link_libraries(${PROJECT_NAME} string)


#设置执行程序支持gdb调试
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")