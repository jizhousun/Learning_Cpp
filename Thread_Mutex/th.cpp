#include "th.h"
Th::Th(){}

void Th::Run(string str){
    for(int i=0;i<50;i++){
        std::cout<<str<<": "<<i<<endl;
    }
}

void Th::RunMutex(string str){
    mtx.lock();
    Run(str);
    mtx.unlock();
}

//LockGuard 自动解锁
void Th::RunLockGuard(string str){
    {//lock_guard lg生命周期开始
        lock_guard<mutex> lg(mtx);
        Run(str);
    }//lock_guard lg生命周期结束
}


//相同互斥体在不同方法中被调用
//未完成
//void Th::RunUniqueLock(CriticalData &a, CriticalData &b){
//    unique_lock<mutex> guard1(a.m_communal,defer_lock);
//    cout<<"thread:"<< this_thread::get_id()<<"mutex a"<<endl;

//    this_thread::sleep_for(chrono::milliseconds(1));

//    unique_lock<mutex> guard2(b.m_communal,defer_lock);
//    cout<<" thread:"<< this_thread::get_id()<<"mutex b"<<endl;

//    cout<<"     thread:"<<this_thread::get_id()<<" get both mutex"<<endl;
//    lock(guard1, guard2);
//}


