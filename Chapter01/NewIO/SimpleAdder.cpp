#include <iostream>

int main() {
	int val1;
	std::cout << "Type the first number: ";
	std::cin >> val1;

	int val2;
	std::cout << "Type the second number: ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "Add result: " << result << std::endl;

	return 0;
}
