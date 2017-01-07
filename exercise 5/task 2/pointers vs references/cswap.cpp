void c_swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int main() {
	int x1 = 1, x2 = 2;
	c_swap(&x1, &x2);
	return 0;
}
