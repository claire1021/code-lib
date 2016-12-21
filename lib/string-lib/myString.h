/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file myString.h
 * @author liunan06(com@baidu.com)
 * @date 2016/08/13 10:58:18
 * @brief 
 *  
 **/




#ifndef  __MYSTRING_H_
#define  __MYSTRING_H_

class myString{
public:
    myString(const char* cstr=0);
    myString(const myString &str);
    myString& operator=(const myString &str);
    ~myString();
private:
    char *m_data;
};














#endif  //__MYSTRING_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
