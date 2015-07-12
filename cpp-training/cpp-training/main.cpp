//
//  main.cpp
//  cpp-training
//
//  Created by Lei Gu on 15/7/10.
//  Copyright (c) 2015年 codefreeme. All rights reserved.

#include <iostream>
#include "Algorithm.h"
#include "StringOps.h"

using namespace std;

void printArray(int a[], int aLength)
{
    for (int i=0; i<aLength; ++i) {
        std::cout << a[i] << std::endl;
    }
}

int main(int argc, const char * argv[])
{
    
    // Algorithm methods
    Algorithm* agm = new Algorithm();
    
    int array[] = {10, 20, 2, 5, 98, 1, 0, 18};
    
    agm->qSort(array, 0, 7);
    
    printArray(array, 8);
    
    delete agm;
    
    // Algorithm methods
    StringOps* strOps = new StringOps();
    
    int number = 198888;
    char p[7];
    
    strOps->int2str(number, p);
    
    for (int i=0; i<7; ++i) {
        std::cout<<p[i] << "  ";
    }
    
    char strSrc[] = "Hello world!";
    char strDes[14];
    
    strOps->strcpy(strDes, strSrc);
    int i = 0;
    
    cout << (strOps->strLength(strcpy(strDes, strSrc)));

    while (strDes[i] != '\0')
    {
        std::cout << strDes[i] << " ";
        i++;
    }
    
    
    delete strOps;
    
    return 0;
}

#if 0

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
#endif
