template <typename T>
inline void swap(T &a, T &b) {
	T c(a);
	a = b;
	b = c;
}

template <typename T>
T gcf(T a, T b) {
	if (a < b) swap(a, b);
	while (b != 0) {
		a = a - b;
		if (a < b) swap(a, b);
	}
	return a;
}

template <typename T>
inline T lcm(T a, T b) {
	return (a/gcf(a, b)) * b;
}