#include <iostream>

int main() {
	int sell;

	while (1) {
		std::cout << "Type the sales of this month(-1 to end): ";
		std::cin >> sell;
		if (sell == -1) {
			std::cout << "End the program." << std::endl;
			break;
		}

		std::cout << "This month's salary: " << 50 + (sell * 12) / 100 << std::endl;
	}

	return 0;
}
