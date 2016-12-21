/***************************************************************************
 * 
 * Copyright (c) 2016 claire. All Rights Reserved
 * 
 **************************************************************************/
 
/**
 * @file binary_file.cpp
 * @author liunan06(com@baidu.com)
 * @date 2016/08/23 08:50:39
 * @brief 
 *  
 **/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


static void write_binary(const char *filename);

static void read_binary(const char *filename);


/*teacher class*/
class Teacher{
public:
    Teacher(){
        age = 33;
        strcpy(name,"");
    }
    Teacher(int _age,char *_name){
        age = _age;
        strcpy(name,_name);
    }
    void print_teacher(){
        cout<<"age:"<<age<<" name:"<<name<<endl;
    }
private:
    int age;
    char name[20];
};


/*@ofstream:从内存到硬盘*/
static void write_binary(const char *filename){
    char fname[256];
    strcpy(fname,filename);
    cout<<"fname="<<fname<<endl;
    ofstream fout(fname);
    if(!fout){
        cout<<"file open error!"<<endl;
        return ;
    }

    Teacher t1(31,"t31");
    Teacher t2(32,"t32");
    fout.write((char*)&t1,sizeof(t1));
    fout.write((char*)&t2,sizeof(t2));
    fout.close();
}


/*@infstream-从硬盘到内存*/
static void read_binary(const char *filename){
    char fname[256];
    strcpy(fname,filename);

    cout<<"fname:"<<fname<<endl;
    ifstream fin(fname);
    Teacher tmp;

    fin.read((char*)&tmp,sizeof(Teacher));
    tmp.print_teacher();
    fin.close();
    return ;
}



int main(){
    const char *fname = "/home/claire/claire/07_testcode/1.dat";
    write_binary(fname);
    read_binary(fname);
    return 0;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
