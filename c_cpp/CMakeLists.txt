
cmake_minimum_required(VERSION 3.4.1)
project(ndk)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES
        Src/test.c
        Src/common/c_1.c
        Src/common/c_1.h

        Src/common/c_2.c
        Src/common/c_2.h

        Src/common/file_io.c
        Src/common/file_io.h

)

add_executable(ndk ${SOURCE_FILES})

