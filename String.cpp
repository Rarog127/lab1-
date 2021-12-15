#include "String.h"

String::String() : _string(nullptr), _size(0u) {
	/*_str = nullptr;
	_size = 0u;*/
}

String::String(const char* c_style_string) {
	_size = 0u;

	for (size_t i = 0u; c_style_string[i] != '\0'; i++)
		_size++;

	if (_size != 0u)
		_string = new char[_size];
	else
		_string = nullptr;

	copy(_string, c_style_string);
}

String::String(const String& other) :_size(other._size) {
	if (_size == 0u)
		_string = nullptr;
	else {
		_string = new char[_size];

		copy_n(_string, other._string, other._size);
	}
}

//приватный конструктор строки
String::String(char* string, size_t size) : _string(string), _size(size) {

}

String::~String() {
	delete[] _string;

	_string = nullptr;
	_size = 0u;
}

String& String::operator=(const String& other) {
	if (this != &other) {
		delete[] _string;

		_size = other._size;
		_string = new char[_size];
		copy_n(_string, other._string, other._size);
	}

	return *this;
}

char String::operator[](size_t index) const {
	if (index >= _size)
		throw std::range_error("Index is out of string range.\n");

	return _string[index];
}

char& String::operator[](size_t index) {
	if (index >= _size)
		throw std::range_error("Index is out of string range.\n");

	return _string[index];
}

String String::operator+(const String& other) const {
	size_t new_size = _size + other._size;
	char* new_string = nullptr;

	if (new_size != 0u) {
		new_string = new char[new_size];

		copy_n(new_string, _string, _size);
		copy_n(new_string + _size, other._string, other._size);
	}

	return String(new_string, new_size);
}

String String::operator*(size_t count_of_repeat) const { //коммутативность
	size_t new_size = _size * count_of_repeat;
	char* new_string = nullptr;

	if (new_size != 0u) {
		new_string = new char[new_size];

		for (size_t i = 0; i < count_of_repeat; i++)
			copy_n(new_string + i * _size, _string, _size);
	}

	return String(new_string, new_size);
}

String String::substring(size_t from, size_t to) { //to - индекс за подстрокой
	if (to > _size)
		throw std::range_error("Index \"to\" is out of string range.\n");

	if (from > to)
		throw std::range_error("Indexes is wrong.\n");

	size_t new_size = to - from;
	char* new_string = nullptr;

	if (new_size != 0u) {
		new_string = new char[new_size];

		copy_n(new_string, _string + from, new_size);
	}

	return String(new_string, new_size);
}

bool String::isEmpty() const {
	return _size == 0;
}

size_t String::size() const {
	return _size;
}

bool String::operator==(const String& other) const {
	if (_size != other._size)
		return false;

	for (size_t i = 0; i < _size; i++)
		if (_string[i] != other._string[i])
			return false;

	return true;
}

bool String::operator!=(const String& other) const {
	return !operator==(other);
}


void String::copy(char* to, const char* from) {
	for (size_t i = 0u; from[i] != '\0'; i++)
		to[i] = from[i];
}

void String::copy_n(char* to, const char* from, size_t n) {
	for (size_t i = 0u; i < n; i++)
		to[i] = from[i];
}

String operator*(size_t count_of_repeat, const String& object_string) {
	return object_string * count_of_repeat;
}

String operator*(int count_of_repeat, const String& object_string) {
	if (count_of_repeat < 0)
		throw std::invalid_argument("Count of repeat can't be negative.\n");

	return object_string * count_of_repeat;
}

std::ostream& operator<<(std::ostream& out, const String& object_string) {
	for (size_t i = 0u; i < object_string._size; i++)
		out << object_string._string[i];

	return out;
}

std::istream& operator>>(std::istream& in, String& object_string) {
	char c = in.get();
	if (c == '\n')
		c = in.get();

	int n = 200;
	char* buffer = new char[n];

	int i = 0;
	while (c != '\n') {
		if (i == n) {
			int new_n = n * 1.5;
			char* new_buffer = new char[new_n];

			String::copy_n(new_buffer, buffer, n);

			delete[] buffer;

			buffer = new_buffer;
			n = new_n;
		}

		buffer[i] = c;
		i++;
		c = in.get();
	}

	in.putback(c);

	buffer[i] = '\0';

	object_string = buffer;

	delete[] buffer;

	return in;
}