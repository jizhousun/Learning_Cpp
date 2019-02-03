#ifndef TH_H
#define TH_H
#include "basicclass.h"
#include <thread>         // std::thread
#include <mutex>


class Th
{
public:
//    struct CriticalData{
//        mutex m_communal;
//    };

    std::mutex mtx;
    Th();
    void Run(string str);
    void RunMutex(string str);
    void RunLockGuard(string str);
    //void RunUniqueLock(CriticalData &a, CriticalData &b);
};

#endif // TH_H
