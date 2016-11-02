#ifndef DRIVER_HPP_
#define DRIVER_HPP_
#include <iostream>

inline int recursive_fac(int step, int cei){
	if(step==cei){
		return step;
	}else{
		return step*recursive_fac(step+1,cei);
	}
}


#endif /* DRIVER_HPP_ */
