#include "SYLLABUS.h"

Syllabus::Syllabus() : cipher{ Cipher{} }, creator{ Person{} },
lvl{ UNDEFL }, stat{Inactive}, name {" "}, TargetCreditUnit{0}, TotalCreditUnit{ 0 } {}

Syllabus::Syllabus(Cipher cipher, Person creator, LvlOfEdu lvl,
	std::string name, short TargetCreditUnit, short NumberOfDisc) {
	this->cipher = cipher; 
	this->creator = creator; 
	this->lvl = lvl; 
	this->name = name; 
	this->stat = Inactive; 
	this->TargetCreditUnit = TargetCreditUnit; 
	this->TotalCreditUnit = TotalCreditUnit; 
	this->NumberOfDisc = NumberOfDisc; 
}

std::ostream& operator<<(std::ostream& out, const Syllabus& s) {
	out << "\tName of the Syllabus: " << s.name << std::endl;
	out << "Cipher: " << s.cipher << std::endl;
	out << "Creator: " << s.creator << std::endl;
	out << "Level of Higher Education: " << NameLvl[s.lvl] << std::endl;
	out << s.disciplines;
	out << "Target Number of disciplines: " << s.NumberOfDisc << std::endl;
	out << "Target unist of all disciplines: " << s.TargetCreditUnit << std::endl;
	out << "Total credit unit of all disciplines: " << s.TotalCreditUnit << std::endl;
	return out;
}

Cipher Syllabus::getCipher() const {
	return cipher;
}

Person Syllabus::getPerson() const {
	return creator;
}

LvlOfEdu Syllabus::getLvlOfEdu() const {
	return lvl;
}

SylStatus Syllabus::getSylStatus() const {
	return stat;
}

TotalDiscip Syllabus::getDisciplines() const {
	return disciplines;
}

std::string Syllabus::getSylName() const {
	return name;
}

short Syllabus::getTotalCU() const {
	return TargetCreditUnit;
}

short Syllabus::getTargetCU() const {
	return TargetCreditUnit;
}

void Syllabus::setCipher(Cipher c) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	cipher = c;
}

void Syllabus::setCipher(std::string p1, std::string p2, std::string p3) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	cipher.setParts(p1, p2, p3);
}

void Syllabus::setPerson(Person p) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	creator = p;
}

void Syllabus::setPerson(std::string p) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	creator.setFullName(p);
}

void Syllabus::setLvlOfEdu(LvlOfEdu l) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	lvl = l;
}

void Syllabus::setDiscipline(Discipline d) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	if (disciplines.uniqueDisc()) disciplines.addDisc(d);
	updateTotalCU();
}

void Syllabus::setDiscipline(short TCU, std::string name) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	if (disciplines.uniqueDisc()) disciplines.addDisc(TCU, name);
	updateTotalCU();
}

void Syllabus::setSylName(std::string s) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	name = s;
}

void Syllabus::setTargetCU(short TCU) {
	if (stat == Active) throw std::runtime_error("The Syllabus is an active!\nYou can`t redact it, until it is inactive");
	TargetCreditUnit = TCU;
}

void Syllabus::updateTotalCU() {
	TotalCreditUnit = 0;
	for (const Discipline& d : disciplines.getDisciplines()) {
		TotalCreditUnit += d.getCurrentCU();
	}
}

void Syllabus::Activate() {
	if ((TotalCreditUnit == TargetCreditUnit) && !disciplines.getDisciplines().empty() && (name != "") &&
		!(cipher == Cipher{}) && !(creator == Person{}))
		stat = Active;
	else throw std::exception("Incorrect/not full fields data!");
}
