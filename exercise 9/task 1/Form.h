#include <ostream>

struct Form {
	int prc, wdt;
	double value;
	bool single_time = false;
	std::ios_base::fmtflags fmt;

	Form (int p = 6) : prc(p) { wdt = 0; }
	Form& scientific() { 
		fmt = std::ios_base::scientific;
		return *this;
	}

	Form& precision(int p) {
		prc = p;
		return *this;
	}

	Form& operator() (double val)  {
		value = val;
		single_time = true;
		return *this;
	}
};

std::ostream& operator<<(std::ostream& os, Form &f) {
	os.setf(f.fmt, std::ios_base::floatfield);
	if (f.single_time) {
		os << f.value << std::defaultfloat;
		f.single_time = false;
	}
	return os;
}