#include <stdio.h>
#include <thread>


void function(){
    printf("Hello world!");
    
}


int main(){
    function();
    std::thread t(function);
    t.join();

    return 0;

}