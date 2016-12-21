/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file test_cin.cpp
 * @author liunan06(com@baidu.com)
 * @date 2016/08/23 07:59:24
 * @brief 
 *  
 **/
#include <iostream>
using namespace std;
//标准输入流对象cin
//     cin.get()    //一次只能读取一个字符
//     cin.get(一个参数)   //读一个字符
//     cin.get(三个参数)   //可以读字符串
//     cin.getline()
//     cin.ignore()
//     cin.peek()
//     cin.putback()

int main(){

    char mybuf[1024];
    int myInt;
    long myLong;

    cin>>myInt;
    cin>>myLong;
    cin>>mybuf;      //遇到空格停止接收数据
    cout<<"myInt:"<<myInt<<"myLong:"<<myLong<"<mybuf:"<<mybuf<<endl;
    return 0;

}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
