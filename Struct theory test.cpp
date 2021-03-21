#include<iostream>

struct Person
{
	int age{};
	long height{};
	long weight{};
};

Person getDets()
{
	Person temp{};
	std::cout << "Enter your age: ";
	std::cin >> temp.age;
	std::cout << "Enter your height in cm: ";
	std::cin >> temp.height;
	std::cout << "Enter your weight in kg: ";
	std::cin >> temp.weight;
	return temp;
}

void* checkAddresses(void* temp)
{
	std::cout << "The integer storing your age is at memory address: " << temp << '\n';
	temp = static_cast<int*>(temp) + 1;
	std::cout << "The long value storing your height is at memory address: " << temp << '\n';
	temp = static_cast<long*>(temp) + 1;
	std::cout << "The long value storing your weight is at memory address: " << temp << '\n';

	return temp;
}

int main()
{
	std::cout << "Hypothesis: That structs are laid out sequentially in memory. Wrote a program to find "
		<< "out the answer because looking it up would be cheating. \n";
	Person a{ getDets() };
	std::cout << "Your age is stored in memory address: " << &a.age << '\n' 
		<< "Your height is stored in memory address: " << &a.height << '\n' 
		<< "Your weight is stored in memory address: "<< &a.weight << '\n';
	void* ptr(checkAddresses(&a.age));
	if (ptr == &a.weight)
	{
		std::cout << "Hypothesis confirmed.";
	}
	
	return 0;
}
