/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file cond.cpp
 * @author liunan06(com@baidu.com)
 * @date 2016/08/15 13:17:48
 * @brief 
 *  
 **/

//global variable
std::deque<int> q;
std::mutex mu;
std::condition_variable cond;

//producer
void function_1(){
    int count=10;
    while(count>0){
        std::unique_lock<mutex> locker(mu);                       
        q.push_front(count);                                   //push back count
        locker.unlock();
        cond.notify_one();                                     //Nodify one waiting thread,if there is one.
        cond.notify_all();
        std::this_thread::sleep_for(chrono::seconds(1));       //sleep
        count--;
    }
}

//consumer
/*
void function_2(){
    int data=0;
    while(data!=1){                   
        std::unique_lock<mutex> locker(mu);
        cond.wait(locker);                                    //this will put thread2 into sleep,until waked by thread1
        if(!q.empty()){                                        //keeps checking if queue is empty
            data = q.back();
            q.pop_back();
            locker.unlock();
            cout<<"t2 got a value from t1:"<<data<<endl;
        }else{                                                 //busy looping is not ineffient
            locker.unlock();
            std::this_thread::sleep_for(chrono::milliseconds(10));    //how do we decide the time duriation of the sleep
        }
    }
}
*/

void function_2(){
    int data=0;
    while(data!=1){
        std::unique_lock<mutex> locker(mu);
        cond.wai(locker,[](){return !q.empty();});   //spurious wake
        data = q.back();
        q.pop_back();
        locker.unlock();
        cout<<"t2 got a value from t1:"<<data<<endl;
    }
}


int main(){
    std::thread t1(function_1);
    std::thread t2(function_2);
    t1.join();
    t2.join();
    return 0;
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
