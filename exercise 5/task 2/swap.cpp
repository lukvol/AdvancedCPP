void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

int main() {
	int x1 = 1, x2 = 2;
	swap(x1, x2);
	return 0;
}