//
//  BMWList2.h
//  BMW-test
//
//  Created by Lei Gu on 15/7/12.
//  Copyright (c) 2015年 bmw. All rights reserved.
//

#ifndef __BMW_test__BMWList2__
#define __BMW_test__BMWList2__

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Node2
{
public:
    Node2<T>* mPre;
    Node2<T>* mNext;
    T mData;
    
    Node2(const T& aData, Node2* aPre = NULL, Node2* aNext = NULL)
    : mData(aData), mPre(aPre), mNext(aNext)
    {}
};

template <class T>
class LIST_POS2
{
public:
    LIST_POS2(Node2<T>* aData) : mData(aData) {}
    LIST_POS2();
    Node2<T>* mData;
};

template <class T>
class BMWList2
{
public:
    BMWList2() : mHead(), mTail(), mSize(0)
    {
    }
    
    ~BMWList2()
    {
        removeAll();
    };
    
    void removeAll()
    {
        if(0 != mSize)
        {
            for(int i=0; i<mSize; ++i)
            {
                Node2<T>* temp = mHead->mNext;
                delete mHead;
                mHead = temp;
            }
        }
        mSize = 0;
    };
    
    void remove()
    {
        if(NULL == mHead)
        {
            return;
        }
        
        Node2<T>* pNode = mTail;
        Node2<T>* tailPre = pNode->mPre;
        tailPre->mNext = NULL;
        
        delete mTail;
        mSize--;
    };
    
    void remove(LIST_POS2<T>* aPos)
    {
        if(0 == mSize)
        {
            return;
        }
        
        Node2<T>* posData = aPos->mData;
        
        if(NULL == posData)
        {
            return;
        }
        
        Node2<T>* pre = posData->mPre;
        Node2<T>* next = posData->mNext;
        
        if(NULL == pre)
        {
            mHead = next;
            next->mPre = NULL;
        }
        else
        {
            pre->mNext = next;
            next->mPre = pre;
        }
        
        mSize--;
        delete posData;
    };
    
    void print()
    {
        Node2<T>* pNode = mHead;
        while (NULL != pNode)
        {
            cout << pNode->mData << ", ";
            pNode = pNode->mNext;
        }
        
        cout<<endl;
    };
    
    LIST_POS2<T> add(T aData)
    {
        Node2<T>* pNode = new Node2<T>(aData);
        if(0 == mSize)
        {
            mHead = pNode;
            mTail = pNode;
        }
        else if(1 == mSize)
        {
            mHead->mNext = pNode;
            mHead->mPre = NULL;
            
            pNode->mPre = mHead;
            pNode->mNext = NULL;
            mTail = pNode;
        }
        else
        {
            mTail->mNext = pNode;
            pNode->mPre = mTail;
            mTail = pNode;
        }
        
        mSize++;
        
        LIST_POS2<T> newPos = LIST_POS2<T>(pNode);
        return newPos;
    };
    
    LIST_POS2<T> insert(T aData, LIST_POS2<T> aPos)
    {
        Node2<T>* pNode = new Node2<T>(aData);
        Node2<T>* posNode = aPos.mData;
        if(posNode == mHead)
        {
            pNode->mPre = NULL;
            pNode->mNext = posNode;
            posNode->mPre = pNode;
            mHead = pNode;
        }
        else
        {
            Node2<T>* pre = posNode->mPre;
            pre->mNext = pNode;
            pNode->mPre = pre;
            pNode->mNext = posNode;
        }
        
        mSize++;
        LIST_POS2<T> newPos = LIST_POS2<T>(pNode);
        return newPos;
    };
    
private:
    Node2<T>* mHead;
    Node2<T>* mTail;
    int mSize;
};

#endif /* defined(__BMW_test__BMWList2__) */
