//
//  main.cpp
//  cpp-training
//
//  Created by Lei Gu on 15/7/10.
//  Copyright (c) 2015年 codefreeme. All rights reserved.
//

#include <iostream>
#include "Algorithm.h"

void printArray(int a[], int aLength)
{
    for (int i=0; i<aLength; ++i) {
        std::cout << a[i] << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    
    Algorithm* agm = new Algorithm();
    
    int array[] = {10, 20, 2, 5, 98, 1, 0, 18};
    
    agm->qSort(array, 0, 7);
    
    printArray(array, 8);
    
    delete agm;
    
    return 0;
}
