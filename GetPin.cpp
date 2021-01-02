#include <iostream>
#include <cstdint>
#include <cstdlib> /* changed to cstdlib */

using pin_t = std::int_fast16_t;

pin_t getPin()
{
	pin_t input1{};
	std::cin >> input1;

	return input1;
}
 
bool isNotValid(pin_t x)			// This function tests whether the pin entered by the user is a 4-digit number.
{
	return (x < 1000 || x > 9999);
}

pin_t confPin(pin_t input2)		// This function asks the user to enter the pin again. The pin is rejected if it doesn't match.
{
	std::cout << "Confirm your 4-digit pin: ";
	if (input2 == getPin())
	{
		std::cout << "Your pin is set.\n";
		return input2;
	}
	else
	{
		std::cout << "Not a match. Start over.";
		exit (EXIT_FAILURE);
	}
}

void logIn(pin_t userPin)		//This function sets the pin as a constant and allows the user to log in to the account.
{
	const pin_t savedPin{ userPin };
	std::cout << "Enter your pin to log in: ";
	pin_t x{};
	std::cin >> x;
	if (x == savedPin)
		std::cout << "Account accessed. Welcome back!";
	else
		std::cout << "Incorrect pin. Try again.";	//You can't actually try again. More functionality needed.
}

int main()
{
	pin_t pin1{0};
	pin_t pin2{ 0 };				//I zero initialized pin2 here to track whether the value changes because the first pin attempt was rejected.
   pin_t userPin{};

	std::cout << "Create your 4-digit pin: "; /* moved out of function */
	pin1 = getPin();
    if (isNotValid(pin1)){
		std::cout << "Invalid pin. Enter a 4-digit pin: "; /* moved out of function */
		pin2 = getPin();	/* another use of getPin() instead */
    }
    userPin = !isNotValid(pin2)?confPin(pin2):confPin(pin1);
	logIn(userPin);
	return 0;
}
