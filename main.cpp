#include <iostream>
#include "String.h"

void print_menu() {
	system("cls");
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "1. read symbol" << std::endl;
	std::cout << "2. write symbol" << std::endl;
	std::cout << "3. sum" << std::endl;
	std::cout << "4. mult" << std::endl;
	std::cout << "5. substring" << std::endl;
	std::cout << "6. checking for equal" << std::endl;
	std::cout << "7. exit" << std::endl;
}

int get_variant(int count) {
	int variant;
	std::cin >> variant;

	while (!std::cin || variant < 1 || variant > count) {
		std::cout << "Incorrect input. Try again: " << std::endl;
		std::cin.clear();
		std::cin >> variant;
	}

	return variant;
}


int main() {
	int variant;

	String s1, s2;
	int number, number2;
	char c;

	do {
		print_menu();

		variant = get_variant(7);

		switch (variant) {
		case 1:
			std::cout << "Input string: " << std::endl;
			std::cin >> s1;

			std::cout << "Input index of element: " << std::endl;
			std::cin >> number;

			std::cout << "Result: " << std::endl;
			std::cout << s1[number] << std::endl;
			break;

		case 2:
			std::cout << "Input string: " << std::endl;
			std::cin >> s1;

			std::cout << "Input index of element: " << std::endl;
			std::cin >> number;

			std::cout << "Input symbol to put into element: " << std::endl;
			c = std::cin.get();
			while (c == '\n')
				c = std::cin.get();

			s1[number] = c;

			std::cout << "Result: " << std::endl;
			std::cout << s1 << std::endl;
			break;

		case 3:
			std::cout << "Input first string: " << std::endl;
			std::cin >> s1;

			std::cout << "Input second string: " << std::endl;
			std::cin >> s2;

			std::cout << "Result: " << std::endl;
			std::cout << s1 + s2 << std::endl;
			break;

		case 4:
			std::cout << "Input string: " << std::endl;
			std::cin >> s1;

			std::cout << "Input number for multiplication: " << std::endl;
			std::cin >> number;

			std::cout << "Result: " << std::endl;
			std::cout << s1 * number << std::endl;
			break;

		case 5:
			std::cout << "Input string: " << std::endl;
			std::cin >> s1;

			std::cout << "Input index for substring (start & after end): " << std::endl;
			std::cin >> number >> number2;

			std::cout << "Result: " << std::endl;
			std::cout << s1.substring(number, number2) << std::endl;
			break;

		case 6:
			std::cout << "Input first string: " << std::endl;
			std::cin >> s1;

			std::cout << "Input second string: " << std::endl;
			std::cin >> s2;

			std::cout << "Result: " << std::endl;
			std::cout << "Is equal?\t" << (s1 == s2 ? "true" : "false") << std::endl;
			std::cout << "Is not equal?\t" << (s1 != s2 ? "true" : "false") << std::endl;
			break;
		}
		if (variant != 7) {
			std::cout << std::endl;
			system("pause");
		}
	} while (variant != 7);

	std::cout << "Program is over." << std::endl;

	return 0;
}