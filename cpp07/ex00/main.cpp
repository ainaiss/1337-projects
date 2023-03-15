#include "whatever.hpp"

class Awesome
{
private:
	int n;

public:
	Awesome()
	{
		n = 0;
	}
	Awesome(const int x)
	{
		this->n = x;
	}

	bool operator>(Awesome const &rhs)
	{
		return this->n > rhs.getN();
	}

	bool operator<(Awesome const &rhs)
	{
		return this->n < rhs.getN();
	}

	const int &getN(void) const
	{
		return this->n;
	}
};

int main(void)
{
	// int
	{
		int a = 8;
		int b = 10;
		std::cout << "A: " << a << "\t B: " << b << std::endl;
		std::cout << "min: " << ::min(a, b) << std::endl;
		std::cout << "max: " << ::max(a, b) << std::endl;
		swap(a, b);
		std::cout << "swap A: " << a << "\tB: " << b << std::endl
				  << std::endl;
	}
	// Double
	{
		double a = 13.37;
		double b = 42.42;
		std::cout << "A: " << a << "\t B: " << b << std::endl;
		std::cout << "min: " << ::min(a, b) << std::endl;
		std::cout << "max: " << ::max(a, b) << std::endl;
		swap(a, b);
		std::cout << "swap A: " << a << "\tB: " << b << std::endl
				  << std::endl;
	}
	// float
	{
		float a = 13.37f;
		float b = 42.42f;
		std::cout << "A: " << a << "\t B: " << b << std::endl;
		std::cout << "min: " << ::min(a, b) << std::endl;
		std::cout << "max: " << ::max(a, b) << std::endl;
		swap(a, b);
		std::cout << "swap A: " << a << "\tB: " << b << std::endl;
	}
	// string
	{
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "C: " << c << "\t D: " << d << std::endl;
		swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	}

	// User-defined class testing
	{
		Awesome a(40);
		Awesome b(2);

		std::cout << (a < b) << std::endl;
	}
}
