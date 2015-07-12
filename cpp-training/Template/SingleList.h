//
//  SingleList.h
//  cpp-training
//
//  Created by Lei Gu on 15/7/12.
//  Copyright (c) 2015年 codefreeme. All rights reserved.
//

#ifndef __cpp_training__SingleList__
#define __cpp_training__SingleList__

#include <stdio.h>

template<class T>
class SingleList
{
public:
    class Node
    {
    public:
        Node();
        ~Node();
        T mData;
        Node* mNext;
    };
    
public:
    SingleList() {}
    ~SingleList() {}
    
private:
    void initSinglist() {}
    
private:
    Node* mHead;
};

#endif /* defined(__cpp_training__SingleList__) */
