#include "driver.hpp"


int main(){
	std::cout<<"Enter number for factorial" <<std::endl;
	int a;
	std::cin >> a;
	int c=recursive_fac(1, a);
	std::cout <<"result: " << c << std::endl;
}
