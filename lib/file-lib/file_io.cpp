/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file file_io.cpp
 * @author liunan06(com@baidu.com)
 * @date 2016/08/23 08:10:42
 * @brief 
 *  
 **/
#include<iostream>
#include <fstream>
using namespace std;

/* ios::in  ----------- -- 以输入方式打开文件
 * ios::out -------------- 以输出方式打开文件（这是默认的方式）如果已有次名字文件，则将其内容全部清空
 * ios::app -------------- 以输出方式打开，写入的数据添加在文件尾
 * ios::ate -------------- 打开一个已有文件，文件指向文件末尾
 * ios::trunc ----------- -打开一个文件，如果文件已存在，则删除其中全部数据，如文件不存在，
 *                         则建立新文件。如已指定了ios::out方式，而未指定ios::ap,ios::ate,ios::in，则同时默认次方式
 * ios::binary ----------- 以二进制方式打开一个文件如不指定此方式则默认为ASCII方式
 * ios::nocreate---------- 打开一个已有的文件，如文件不存在，则打开失败，nocreate的意思是不建立新文件
 * ios::noreplace--------- 如果文件不存在则建立新文件，如果文件已存在则操作失败，replace的意思是
 *                         不跟新原有文件
 * ios::in|ios::out------- 以输入输出方式打开文件，文件可读可写
 * ios::out|ios::binary--- 以二进制方式打开一个输出文件
 * ios::in|ios::binary---- 以二进制方式打开一个输入文件
 */

int main(){

    //文件路径
    char *fname = "/home/users/liunan06/claire_test/file/1.txt";

    //建立一个输出流对象与文件关联
    //ofstream fout(fname,ios::app);        //ios::app 追加，每运行一次都会追加内容在后面呢，默认覆盖
    
      ofstream fout(fname,ios::ate);        //ios::ate打开 一个已有文件，文件指针指向文件末尾
      if(!fout){                            //失败检测
       cout<<"打开文件失败"<<endl;
      }
     

  // fstream fout(fname);       
    //写入文件
    fout<<"hello......"<<endl;
    //关闭
    fout.close();



    //读文件
    //建立一个输出流对象与文件关联
    ifstream fin(fname);
    char ch;
    while(fin.get(ch)){
        cout<<ch;
    }
    fin.close();

    return 0;
}























/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
