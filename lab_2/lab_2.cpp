#include <iostream>
#include "circularbuffer.h"

int main() {
	setlocale(LC_ALL, "rus");
	CircularBuffer<int> buffer(5);
	try {
		buffer.enqueue(10);
		buffer.enqueue(20);
		buffer.enqueue(30);
		buffer.enqueue(40);
		buffer.enqueue(50); //размер 5
		std::cout << "Элементы успешно добавлены" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	try {
		buffer.enqueue(10);
		std::cout << "Элементы добавлен, хотя должно быть исключение" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение, как и ожидалось. Ошибка: " << e.what() << std::endl;
	}
	try {
		int result = buffer.dequeue(); //размер 4
		if (result != 10 && buffer.peek() != 20 && buffer.size() != 4) { std::cout << "Ошибка выполнения метода" << std::endl; }
		else { std::cout << "Элемент успешно взят" << std::endl; }
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	int result = buffer.dequeue();
	if (result != 20 && buffer.size() != 3) { std::cout << "Ошибка выполнения метода" << std::endl; }
	else { std::cout << "Элемент успешно взят" << std::endl; }
	result = buffer.dequeue();
	if (result != 30 && buffer.size() != 2) { std::cout << "Ошибка выполнения метода" << std::endl; }
	else { std::cout << "Элемент успешно взят" << std::endl; }
	result = buffer.dequeue();
	if (result != 40 && buffer.size() != 1) { std::cout << "Ошибка выполнения метода" << std::endl; }
	else { std::cout << "Элемент успешно взят" << std::endl; }
	result = buffer.dequeue(); //размер 0
	if (result != 50 && buffer.size() != 0) { std::cout << "Ошибка выполнения метода" << std::endl; }
	else { std::cout << "Элемент успешно взят" << std::endl; }
	try {
		result = buffer.dequeue();
		std::cout << "Элементы взят, хотя должно быть исключение" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	try {
		buffer.enqueue(10); //размер 1
		int result = buffer.peek();
		std::cout << "Элемент успешно получен" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	try {
		int result = buffer.dequeue(); //размер 0
		result = buffer.peek();
		std::cout << "Элементы получен, хотя должно быть исключение" << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
	}
	buffer.enqueue(10);
	buffer.enqueue(20);
	buffer.enqueue(30); //размер 3
	if (buffer.size() == 3) {
		std::cout << "Размер: " << buffer.size() << std::endl;
	}
	else { std::cout << "Размер получен неправильно" << std::endl; }
	buffer.clear();
	if (buffer.isEmpty()) { std::cout << "Очищено успешно и буфер пустой" << std::endl; }
	else { std::cout << "При выполнении очистки произошла ошибка и буфер не пуст" << std::endl; }

	return 0;
}