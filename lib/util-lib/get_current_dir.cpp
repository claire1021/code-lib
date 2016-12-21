/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file getdir.cpp
 * @author liunan06(com@baidu.com)
 * @date 2016/08/23 11:44:22
 * @brief 
 *  
 **/
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<iostream>
#include<unistd.h>
#include<string>
int main(){
    
    char file_path[512] = {0};
    
    if(getcwd(file_path,512)!=NULL){                //得到当前目录
        if(file_path[strlen(file_path)-1]!='/'){
            file_path[strlen(file_path)]='/';       //目录后加上‘/’
        }
    }
    std::cout<<"path:"<<file_path<<std::endl;
     
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
