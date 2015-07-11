//
//  main.cpp
//  cpp-training
//
//  Created by Lei Gu on 15/7/10.
//  Copyright (c) 2015年 codefreeme. All rights reserved.
//

//#include <iostream>
//#include "Algorithm.h"
//
//void printArray(int a[], int aLength)
//{
//    for (int i=0; i<aLength; ++i) {
//        std::cout << a[i] << std::endl;
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    
//    Algorithm* agm = new Algorithm();
//    
//    int array[] = {10, 20, 2, 5, 98, 1, 0, 18};
//    
//    agm->qSort(array, 0, 7);
//    
//    printArray(array, 8);
//    
//    delete agm;
//    
//    return 0;
//}

#include "gtest/gtest.h"

int Factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

TEST(FactorialTest, Negative) {
    // This test is named "Negative", and belongs to the "FactorialTest"
    // test case.
    EXPECT_EQ(1, Factorial(-5));
    EXPECT_EQ(1, Factorial(-1));
    EXPECT_GT(Factorial(-10), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
