#include <iostream>
#include <cstdint>
#include <cstdlib> /* changed to cstdlib */

using pin_t = std::int_fast16_t;

bool isValid(pin_t x)			// This function tests whether the pin entered by the user is a 4-digit number.
{
	return (x >= 1000 && x <= 9999);
}

pin_t getPin()
{
	pin_t input1{};
	do{
		std::cin >> input1;
		if(isValid(input1)){
			break;
		}
		std::cout << "4 digit numbers only" << std::endl << ": ";
	}while(1);

	return input1;
}

bool confPin(pin_t input2)		// This function asks the user to enter the pin again. The pin is rejected if it doesn't match.
{
	std::cout << "Confirm your 4-digit pin: ";
	return (input2 == getPin()); /* removed all local variables except input2 */
}

pin_t createPin(void){
 	pin_t userPin{0};
	do{
		std::cout << "Create your 4-digit pin: "; /* moved out of function */
		userPin = getPin();
		if(confPin(userPin)){
			break;
		}
		std::cout << "Not a match. Start over." << std::endl;
	}while(1);

	std::cout << "Your pin is set.\n";

	return userPin;
}
void logIn(pin_t userPin)		//This function sets the pin as a constant and allows the user to log in to the account.
{
	const pin_t savedPin{ userPin };
	std::cout << "Enter your pin to log in: "; 
	while(getPin() != savedPin){ /* removed variabled used to read pin */
		std::cout << "Incorrect pin. Try again.";
	}
	std::cout << "Account accessed. Welcome back!";
}

int main()
{
	pin_t userPin;
	userPin = createPin(); 
	/* could easily write logIn(createPin()); and removed the variable userPin altogether,
		but if creating pin and loggin in are eventually separated, then this may be necessary */ 
	
	logIn(userPin);
	return 0;
}
