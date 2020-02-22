#include <chrono>
#include <iostream>

using namespace std; 
  
void fun() 
{ 
    int sum = 0;
    for (int i=0; i<1000000; i++) 
    {
        sum = i+1;
        sum = i+1;
        sum = i+1;
        sum = i+1;
        sum = i+1;
        sum = i+1;
    } 
} 
  
int main() 
{ 
    
    auto startTime=std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    fun();
    auto endTime=std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    
    cout<<endTime - startTime<<endl;
    return 0; 
} 