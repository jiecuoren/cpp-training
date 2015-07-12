//
//  main.cpp
//  cpp-training
//
//  Created by Lei Gu on 15/7/10.
//  Copyright (c) 2015年 codefreeme. All rights reserved.

#include <iostream>
#include "Algorithm.h"
#include "StringOps.h"
#include "BMWList.h"
#include "BMWList2.h"
#include "BMWList3.h"

using namespace std;

void printArray(int a[], int aLength)
{
    for (int i=0; i<aLength; ++i) {
        std::cout << a[i] << std::endl;
    }
}

void doTest1()
{
    BMWList myList;
    myList.removeAll();
    myList.remove();
    myList.print();
    
    LIST_POS pos3 = myList.add(3);
    LIST_POS pos5 = myList.add(5);
    
    myList.add(2);
    myList.print();
    
    myList.remove();
    
    LIST_POS pos4 = myList.insert(4, pos5);
    myList.print();
    
    myList.remove(pos3);
    myList.print();
    
    myList.insert(3, pos4);
    myList.print();
}

void doTest2()
{
    BMWList2<string> myList2;
    myList2.removeAll();
    myList2.remove();
    myList2.print();
    
    LIST_POS2<string> pos3 = myList2.add(string("three"));
    LIST_POS2<string> pos5 = myList2.add(string("five"));
    myList2.add(string("two"));
    
    myList2.print();
    
    myList2.remove();
    
    LIST_POS2<string> pos4 = myList2.insert(string("four"), pos5);
    myList2.print();
    
    myList2.remove(&pos3);
    myList2.print();
    
    myList2.insert(string("three"), pos4);
    myList2.print();
}

void doTest3()
{
    BMWList2<string*> myList3;
    myList3.removeAll();
    myList3.remove();
    myList3.print();
    
    string* three = new string("three");
    string* five = new string("five");
    string* two = new string("two");
    string* four = new string("four");
    
    
    LIST_POS2<string*> pos3 = myList3.add(three);
    LIST_POS2<string*> pos5 = myList3.add(five);
    myList3.add(two);
    
    myList3.print();
    
    myList3.remove();
    myList3.print();
    
    
    LIST_POS2<string*> pos4 = myList3.insert(four, pos5);
    myList3.print();
    
    myList3.remove(&pos3);
    myList3.print();
    
    myList3.insert(three, pos4);
    myList3.print();
    
    delete three;
    delete five;
    delete two;
    delete four;
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
    
    doTest1();
    doTest2();
    doTest3();

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
