#ifndef SYLLABUS
#define SYLLABUS

#include "Cipher.h"
#include "Person.h"
#include "TotalDisciplines.h"

//Необходимо разработать класс Учебный план для автоматизирующей разработку учебных планов подсистемы информационной системы университета.
//Учебный план состоит из дисциплин.
//За прохождение каждой дисциплины даётся некоторое количество зачётных единиц.
//Сумма зачётных единиц за все дисциплины, включенные в учебный план, должна совпадать с целевым количеством зачётных единиц учебного плана.
//Количество дисциплин и суммарное количество зачётных единиц за них могут быть равны 0 только одновременно.
//План может быть введён в действие, только если сумма зачётных единиц за дисциплины совпадает с целевый количеством зачётных единиц, а также все поля заполнены.
//Введённый в действие учебный план нельзя редактировать.

class Syllabus {
private:
	Cipher cipher; Person creator;
	LvlOfEdu lvl; SylStatus stat;
	TotalDiscip disciplines;
	std::string name;
	short TargetCreditUnit;
	short TotalCreditUnit;
public:
	// Конструкторы 
	Syllabus();
	Syllabus(Cipher cipher, Person creator, LvlOfEdu lvl,
		std::string name, SylStatus stat, short NOD, short TOD);

	// Оператор вывода в поток
	friend std::ostream& operator<<(std::ostream& out, const Syllabus& s);

	// Геттеры
	Cipher getCipher() const;
	Person getPerson() const;
	LvlOfEdu getLvlOfEdu() const;
	SylStatus getSylStatus() const;
	TotalDiscip getDisciplines() const;
	std::string getSylName() const;
	short getTotalCU() const;
	short getTargetCU() const;

	// Сеттеры
	void setCipher(Cipher c);
	void setCipher(std::string p1, std::string p2, std::string p3);
	void setPerson(Person p);
	void setPerson(std::string p);
	void setLvlOfEdu(LvlOfEdu l);
	void setSylName(std::string s);
	void setDiscipline(Discipline d);
	void setDiscipline(short TCU, std::string name);
	void setTargetCU(short TCU);

	// Ввод плана в действие
	void Activate();

	// обновление общего числа зачётных единиц по данному учебному плану
	void updateTotalCU();
};

#endif
