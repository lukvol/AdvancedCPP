#ifndef DRIVER_HPP_
#define DRIVER_HPP_
#include <iostream>

//Can't be inlined, since 'cei' is only known during runtime.
//Therefore, the compiler has no chance to know how often the recursion
//will happen.
inline int recursive_fac(int step, int cei){
	if(step==cei){
		return step;
	}else{
		return step*recursive_fac(step+1,cei);
	}
}


#endif /* DRIVER_HPP_ */
