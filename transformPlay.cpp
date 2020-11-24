#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stdio.h>
#include <functional> 
#include <algorithm> 


using namespace std;

int main(){
    class divide{
        public:
        int div = 0;
        divide();
        divide(int d):div{d}{}
        int operator()(int dev){
            if(dev % div == 0)
                return dev;
            return 0;
        }
    };

    int divisor;
    vector<int> v1 = {3,15,60,89,76,25,55,33,21};
    vector<int> b1(v1.size());
    cout << "Enter divisor" << endl;
    cin>>divisor;
    divide d1(divisor);
    transform(v1.begin(),v1.end(),b1.begin(),d1);

    for(auto const &e : b1)
        if(e) cout << e << " is divisor of " << divisor << endl;

        

return 0;

}
 