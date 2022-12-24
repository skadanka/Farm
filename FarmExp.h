#include <exception>
using namespace std;

class CowException : public exception{
	const char* what() const noexcept override
	{ return "Insert valid number of cow farms";}
};

class SheepException : public exception{
	const char* what() const noexcept override
	{ return "Insert valid number of sheep farms";}
};

class ChickenException : public exception{
	const char* what() const noexcept override
	{ return "Insert valid number of chicken farms";}
};
