#include <gtest/gtest.h>  
#include <unistd.h>  
// 定义一个简单的加法函数  
int add(int a, int b) {  
    return a + b;  
}  
  
// 使用TEST()宏定义测试用例  
TEST(AddTest, PositiveNumbers) {  
    EXPECT_EQ(add(1, 2), 3); // 预期add(1, 2)的结果为3  
}  
  
TEST(AddTest, NegativeNumbers) {  
    EXPECT_EQ(add(-1, -2), -3); // 预期add(-1, -2)的结果为-3  
}  
  
// 主函数，用于运行所有测试用例  
int main(int argc, char **argv) {  
    testing::InitGoogleTest(&argc, argv); // 初始化Google Test  
    return RUN_ALL_TESTS(); // 运行所有测试用例  
}