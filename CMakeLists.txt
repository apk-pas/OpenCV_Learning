#规定cmake最小版本
cmake_minimum_required(VERSION 3.10.0)

#设置项目名称
project(opencv_test)

#设置OpenCV的库路径和cmake的前缀路径
set(OpenCV_DIR "D:\\Opencv\\opencv\\build\\x64\\cv\\install")
find_package(OpenCV REQUIRED)

#设置GTest的库路径和cmake的前缀路径
set(CMAKE_PREFIX_PATH "D:\\googletest-1.17.0\\install\\lib\\cmake\\GTest")
find_package(GTest REQUIRED)

#生成可执行文件
#file(GLOB_RECURSE SOURCES "src/*.cpp")
#add_executable(opencv ${SOURCES})
add_executable(opencv "src/video.cpp")
add_executable(gtest "src/add.cpp")

#链接OpenCV库
target_link_libraries(opencv PUBLIC ${OpenCV_LIBS})
target_include_directories(opencv PUBLIC ${OpenCV_INCLUDE_DIRS})

#链接GTest库
target_link_libraries(gtest PUBLIC GTest::gtest GTest::gtest_main)
target_include_directories(gtest PUBLIC ${GTest_INCLUDE_DIRS})
