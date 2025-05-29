#ifndef CIPHER
#define CIPHER

#include "Needed_libs.h"

class Cipher {
private:
	std::string pt1, pt2, pt3;
	bool isNum(std::string s);
public:
	// Полный конструктор
	Cipher(std::string p1 = "00", std::string p2 = "00", std::string p3 = "00");

	// Установка полного шифра
	void setParts(std::string p1, std::string p2, std::string p3);

	// Оператор сравнения и присвоения
	Cipher& operator=(const Cipher& other);
	bool operator==(const Cipher& other) const;
	friend std::ostream& operator<<(std::ostream& out, const Cipher& c);

	// Получение полного шифра учебного плана
	std::string getCipher() const;
};

#endif 
