#include <thread>
#include <unistd.h>
#include "basicclass.h"
#include "th.h"

void RunX(string str){
    for(int i=0;i<50;i++){
        std::cout<<str<<": "<<i<<endl;
    }
}

//线程基本测试
void ThreadTest001(){
    //function from difference class
    //调用其他类中的方法
    Th t;
    cout<<"start th_dc1"<<endl;
    thread th_dc1(&Th::Run , &t,  "D_A");
    cout<<"start th_dc2"<<endl;
    thread th_dc2(&Th::Run , &t,  "D_B");

    //join的目的是，等待启动的线程完成，才会继续往下执行
    //    th_dc1.join();
    //    th_dc2.join();

    //Calling function in same class
    //调用同一个类中的方法
    cout<<"start thread1"<<endl;
    thread thread1(RunX, "A");
    cout<<"start thread2"<<endl;
    thread thread2(RunX, "B");

    th_dc1.join();
    th_dc2.join();
    thread1.join();
    thread2.join();
}

//互斥锁
void ThreadTest002(){
    Th t;
    cout<<"start Mutex_A"<<endl;
    thread m_a(&Th::RunMutex , &t,  "Mutex_A");
    cout<<"start Mutex_B"<<endl;
    thread m_b(&Th::RunMutex , &t,  "Mutex_B");

    m_a.join();
    m_b.join();
}

//LockGuard 自动解锁
void ThreadTest003(){
    Th t;
    cout<<"start LG_A"<<endl;
    thread m_a(&Th::RunLockGuard , &t,  "LG_A");
    cout<<"start LG_B"<<endl;
    thread m_b(&Th::RunLockGuard , &t,  "LG_B");

    m_a.join();
    m_b.join();
}

//原子方式锁定互斥体
void ThreadTest004(){
}

int main(int argc, char *argv[])
{
    cout<<"hello"<<endl;
//    ThreadTest001();
//    ThreadTest002();
    //ThreadTest003();
    //ThreadTest004();

    usleep(10000);
    cout<<"test finished."<<endl;
    //    while(true){
    //        usleep(10000);
    //    }
    return 1;
}
