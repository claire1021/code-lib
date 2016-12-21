/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file myString.cpp
 * @author liunan06(com@baidu.com)
 * @date 2016/08/13 11:02:05
 * @brief 
 *  
 **/

#include"myString.h"

inline myString::myString(const char *cstr){
    if(cstr){                                    //if cstr is null
        m_data = new char[strlen(cstr)+1];
        strcpy(m_data,cstr);
    }else{                                       //create an empty str
        m_data = new char[1];
        *m_data = '\0';
    }
}


inline myString::myString(const myString& str){
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data,str.m_data);
}

inline myString& operator=(const myString& str){
    if(this==&str)                                    //self assignment
        return *this;
    delete[] m_data;
    m_data = new char[strlen(str.m_data)+1];
    strcpy(m_data,str);
    return *this;
}

inline myString::~myString(){
    delete[] m_data;
}


















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
