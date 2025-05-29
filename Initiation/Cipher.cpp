#include "Cipher.h"

bool Cipher::isNum(std::string s) {
	return std::all_of(s.begin(), s.end(), isdigit);
}

Cipher::Cipher(std::string p1, std::string p2, std::string p3) {
	setParts(p1, p2, p3);
}

void Cipher::setParts(std::string p1, std::string p2, std::string p3) {
	if (!(isNum(p1) && isNum(p2) && isNum(pt3))) return;

	if ((p1.size() > 2 || p1.size() == 0) &&
		(p2.size() > 2 || p2.size() == 0) &&
		(p3.size() > 2 || p3.size() == 0)) {
		pt1 = "00"; pt2 = "00"; pt3 = "00";
		return;
	}

	if (p1.size() > 2 || p1.size() == 0) {
		pt1 = "00";
		return;
	}
	else if (p2.size() > 2 || p2.size() == 0) {
		pt2 = "00";
		return;
	}
	else if (p3.size() > 2 || p3.size() == 0) {
		pt3 = "00";
		return;
	}

	pt1 = p1;
	pt2 = p2;
	pt3 = p3;
}

Cipher& Cipher::operator=(const Cipher& other) {
	if (this != &other) {
		pt1 = other.pt1;
		pt2 = other.pt2;
		pt3 = other.pt3;
	}
	return *this;
}

bool Cipher::operator==(const Cipher& other) const {
	return ((pt1 == other.pt1) && (pt2 == other.pt2) && (pt2 == other.pt3));
}

std::ostream& operator<<(std::ostream& out, const Cipher& c) {
	out << c.pt1 << "." << c.pt2 << "." << c.pt3;
	return out;
}

std::string Cipher::getCipher() const {
	std::string s;
	s.append(pt1); s.append(".");
	s.append(pt2); s.append(".");
	s.append(pt3);
	return s;
}
