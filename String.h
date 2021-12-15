#ifndef _STRING_H_ //if not defined

#define _STRING_H_

#include <stdexcept>
#include <iostream>

class String
{
public:
	String();
	String(const char* c_style_str);

	String(const String& other);
	~String();

	String& operator=(const String& other);

	char operator[](size_t index) const;
	char& operator[](size_t index);

	String operator+(const String& other) const;

	String operator*(size_t count_of_repeat) const;

	friend std::ostream& operator<<(std::ostream& out, const String& object_string);
	friend std::istream& operator>>(std::istream& in, String& object_string);

	String substring(size_t from, size_t to); //to - индекс за подстрокой

	bool isEmpty() const;

	size_t size() const;

	bool operator==(const String& other) const;
	bool operator!=(const String& other) const;

private:
	char* _string;
	size_t _size;

	String(char* string, size_t size);

	static void copy(char* to, const char* from);
	static void copy_n(char* to, const char* from, size_t n);
};

String operator*(size_t count_of_repeat, const String& object_string);
String operator*(int count_of_repeat, const String& object_string);

#endif //!_STRING_H_
