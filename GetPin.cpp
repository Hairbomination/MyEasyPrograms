#include <iostream>
#include <cstdint>
#include <stdlib.h>

using pin_t = std::int_fast16_t;	//I'm still confused by what types are best to store numbers. I'm aiming for the most efficient type 
									//that will take a 4-digit number. I'm also not sure whether this is the appropriate location within the
									//program to put the type alias. Need to revisit this later.

pin_t getPin()						// This function asks the user to enter a pin to create an account
{
	std::cout << "Create your 4-digit pin: ";
	pin_t input1{};
	std::cin >> input1;

	return input1;
}
 
bool isNotValid(pin_t x)			// This function tests whether the pin entered by the user is a 4-digit number.
{
	return (x < 1000 || x > 9999);
}

pin_t pinAttempt2()					// This function asks the user to enter the pin again if the first attempt was rejected because it was not a 4-digit number.
{									// The program is easy to break here. It assumes the user will enter a valid pin on the 2nd attempt
	std::cout << "Invalid pin. Enter a 4-digit pin: ";
	pin_t input1{};
	std::cin >> input1;

	return input1;
}
							
pin_t confPin(pin_t input2)		// This function asks the user to enter the pin again. The pin is rejected if it doesn't match.
{
	std::cout << "Confirm your 4-digit pin: ";
	pin_t input3{};
	std::cin >> input3;
	if (input2 == input3)
	{
		std::cout << "Your pin is set.\n";
		return input3;
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
	pin_t pin1{ getPin() };
	pin_t pin2{ 0 };				//I zero initialized pin2 here to track whether the value changes because the first pin attempt was rejected.
	if (isNotValid(pin1))
		pin2 = pinAttempt2();		
	if (pin2 > 0)					//The if else statements are my solution to the problem of which pin to use if the user's first pin was rejected
	{								//and they had to enter a 2nd value. I'm sure I'll be able to improve this once I know the language better.
		pin_t userPin{ confPin(pin2) };
		logIn(userPin);
	}
	else
	{
		pin_t userPin2{ confPin(pin1) };
		logIn(userPin2);
	}
	return 0;
}
