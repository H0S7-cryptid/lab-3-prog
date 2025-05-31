#include "TotalDisciplines.h"

std::ostream& operator<<(std::ostream& out, const TotalDiscip& d) {
	if (d.getDisciplines().empty()) {
		out << "None" << std::endl;
		return out;
	}

	out << "Current Disceplines: " << std::endl;
	for (Discipline data : d.getDisciplines()) {
		out << data;
	}
	return out;
}

std::vector <Discipline> TotalDiscip::getDisciplines() const {
	return disciplines;
}

void TotalDiscip::addDisc(Discipline d) {
	disciplines.push_back(d);
	uniqueDisc();
}

void TotalDiscip::addDisc(short TCU, std::string name) {
	disciplines.push_back(Discipline{ TCU, name });
	uniqueDisc();
}

bool TotalDiscip::uniqueDisc() {
	bool duplicatesFound = false;

	for (auto it = disciplines.begin(); it != disciplines.end(); ++it) {
		for (auto jt = it + 1; jt != disciplines.end(); ) {
			if (*it == *jt) {
				jt = disciplines.erase(jt);
				duplicatesFound = true;
			}
			else ++jt;
		}
	}

	return !duplicatesFound;
}

void TotalDiscip::deleteDisc(Discipline d) {
	disciplines.erase(std::remove(disciplines.begin(), disciplines.end(), d), disciplines.end());
}
