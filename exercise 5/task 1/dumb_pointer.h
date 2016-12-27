#ifndef DUMB_POINTER_H
#define DUMB_POINTER_H

template<typename Object>
class dumb_pointer {
protected:
	Object raw_object;
public:
	dumb_pointer(Object obj) : raw_object(obj) {}
	Object& operator* () { return raw_object; }
	Object* operator-> () { return &raw_object; }
};

#endif