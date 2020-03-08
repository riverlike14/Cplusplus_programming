#include <iostream>

int main() {
	int num, result = 0;
	for (int i = 1; i <= 5; i++) {
		std::cout << "Type " << i << "-th number: ";
		std::cin >> num;
		result += num;
	}

	std::cout << "Total: " << result << std::endl;

	return 0;
}
