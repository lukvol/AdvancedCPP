#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>

template<typename T>
bool is_num(const T &i){
    return i==5111111;
}


int main(){
    std::vector<int> v;
    for(int i=0; i< 10000000; i++){
        v.push_back(i);
    }

    //time code from http://en.cppreference.com/w/cpp/chrono
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    std::cout << *(std::find_if(v.begin(),v.end(), is_num<int>)) << std::endl;

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;

    std::cout << "It just took us: " << elapsed_seconds.count() << std::endl;
}
