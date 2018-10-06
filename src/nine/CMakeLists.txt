#查找当前目录下所有源文件，并命名为DIR_LIB_SRCS变量
aux_source_directory(. DIR_LIB_SRCS)

# 生成静态链接库
add_library(nine ${DIR_LIB_SRCS})