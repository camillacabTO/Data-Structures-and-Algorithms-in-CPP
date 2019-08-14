//
//  phoneRace.cpp
//  Threads
//
//  Created by Camila Barros on 2019-08-13.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

//using namespace std;
//
//mutex m;//you can use std::lock_guard if you want to be exception safe
//int i = 1;
//
//void makeACallFromPhoneBooth(){
//    lock_guard<mutex> locker (m);
//    cout << "Man number " << i << " is making a call" << endl;
//    i++;
//}

//int main()
//{
//    thread man1(makeACallFromPhoneBooth);
//    thread man2(makeACallFromPhoneBooth);
//    thread man3(makeACallFromPhoneBooth);

//    this_thread::sleep_for(chrono::seconds(1));
//    cout << i << endl;

//    man1.join();//man1 finished his phone call and joins the crowd
//    man2.join();//man2 finished his phone call and joins the crowd
//    man3.join();//man3 finished his phone call and joins the crowd
//    return 0;
//}

//std::mutex mtx;           // mutex for critical section
//
//void print_thread_id (int id) {
//    // critical section (exclusive access to std::cout signaled by locking mtx):
//    mtx.lock();
//    std::cout << "thread #" << id << '\n';
//    mtx.unlock();
//}
//
//int main ()
//{
//    std::thread threads[10];
//    // spawn 10 threads:
//    for (int i=0; i<10; ++i)
//        threads[i] = std::thread(print_thread_id,i+1);
//
//    for (auto& th : threads) th.join();
//
//    return 0;
//}
