
void Swap(int& a, int& b)
{
    int *pa = &a;
	int *pb = &b;
	a = *pb;
	b = *pa;
}