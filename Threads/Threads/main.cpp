//
//  main.cpp
//  Threads
//
//  Created by Camila Barros on 2019-08-13.
//  Copyright © 2019 Camila Barros. All rights reserved.
//

#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <chrono>

using namespace std;
//
//void sayHello(int i){
//    for(i=0;i<5;i++)
//        cout << " " <<i<< endl;
//}
//
//int TripleIt(future<int> &fu){
//    int x = fu.get();
//    return x * 3;
//}

////int main(){
////
////    promise<int> p;
////    future<int> f = p.get_future();
////    future<int> myfut = async(launch::async,TripleIt,ref(f));
//////    int x = myfut.get();
////    thread t1 {sayHello,1};
//////    thread t2 {TripleIt,2};
////    p.set_value(5);
////
////    this_thread::sleep_for(chrono::seconds(1));
////
////    cout << myfut.get() << endl;
////
////    t1.join();
//////    t2.join();
////    return 0;
////}


int Input(){
    int val;
    cout << "Please enter a value for to calculate Square" << endl;
    cin>>val;
    return val;
}

void CalculateSquare(promise<int> &pro2, future<int> &fut2){
    int x = fut2.get();
    pro2.set_value(x*x);
}

int main(){
    
    future<int> inputf = async(launch::async,Input);
    
    promise<int> p1;
    future<int> f1 = p1.get_future();
    
    thread calc (CalculateSquare,ref(p1),ref(inputf));
    
    cout << f1.get() << endl;
    
    calc.join();
    
    
    return 0;
}
