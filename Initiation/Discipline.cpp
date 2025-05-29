#include "Discipline.h"

Discipline::Discipline() : CCU{ 0 }, discName{ "" } {}

Discipline::Discipline(short TCU, std::string discName) {
	this->CCU = CCU;
	this->discName = discName;
}

Discipline& Discipline::operator=(const Discipline& d) {
	if (this != &d) {
		this->CCU = d.CCU;
		this->discName = d.discName;
	}
	return *this;
}

bool Discipline::operator==(const Discipline& d) const {
	return ((CCU == d.CCU) && (discName == d.discName));
}

std::ostream& operator<<(std::ostream& out, const Discipline& d) {
	out << "Number of current credit units: " << d.CCU;
	out << "Name of the discipline: " << d.discName;
	out << std::endl;
	return out;
}

short Discipline::getCurrentCU() const {
	return CCU;
}
std::string Discipline::getDiscName() const {
	return discName;
}

void Discipline::setCurrentCU(short ccu) {
	CCU = ccu;
}
void Discipline::setDName(std::string name) {
	discName = name;
}
