template <typename T>
class Class {
	T a;
public:
	T method();
	Class(const T);
};

int main()
{
	Class <int> A(5);
	int a = A.method();
	Class <double> B(6.66);
	double b = B.method();
	return 0;
}

template<typename T>
Class<T>::Class(const T value){
	a = value;
}
template<typename T>
T Class<T>::method() {
	return(a * a);
}