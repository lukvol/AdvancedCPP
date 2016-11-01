/*
 * Driver.cpp
 *
 *  Created on: 01.11.2016
 *      Author: Timothée
 */
#include <vector>
#include <iostream>

<typename T>
bool is_num (T i{
    return i==5111111;
}


int main(){
	std::vector<int> v;
	for(int i=0; i< 10000000; i++){
	v.add(i);
	}

	std::find_if(v.begin(),v.end(), is_num);


}



