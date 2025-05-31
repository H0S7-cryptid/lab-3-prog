#include "SYLLABUS.h"

int main() {
	
	std::cout << "\t\tCipher test" << std::endl << std::endl;
	Cipher c{};
	std::cout << c << std::endl;
	std::string GETSIP = c.getCipher();
	std::cout << GETSIP << std::endl;
	c.setFullCipher("09.01.03");
	std::cout << c << std::endl;
	c.setParts("03", "01", "09");
	std::cout << c << std::endl;
	std::cout << std::endl;

	std::cout << "\t\tPerson test" << std::endl << std::endl;
	Person p{};
	std::cout << p << std::endl;
	std::string GETPER = p.getFname();
	std::cout << GETPER << std::endl;
	p.setFullName("Ivan Ivanov Ivanovich");
	std::cout << p << std::endl;
	std::cout << std::endl;
	
	std::cout << "\t\tDiscipline test" << std::endl << std::endl;
	Discipline d_{ 12, "Mathematical Analisys" };
	Discipline d1{ d_ };
	std::cout << d_ << std::endl;
	std::cout << d1 << std::endl;
	d_.setCurrentCU(10);
	d_.setDName("Linear Algebra");
	std::cout << d_ << std::endl;
	std::cout << std::endl;

	std::cout << "\t\tDiscipline list test" << std::endl << std::endl;
	TotalDiscip t{};
	t.addDisc(12, "Mathematical Analisys");
	Discipline d{ 5, "Linear Algebra" };
	t.addDisc(d);
	t.addDisc(4, "OLKK");
	std::cout << t;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "\t\tSyllabus test" << std::endl << std::endl;
	Syllabus s{ Cipher{"01", "03", "09"}, Person{"Ivan Ivanovich Ivanov"}, Master, "AVTF Syllabus", 18, 0 };
	s.setDiscipline(5, "Linear Algebra");
	s.setDiscipline(13, "Mathematical Analisys");

	std::cout << s << std::endl;

	Syllabus* s1 = new Syllabus{ Cipher{"11", "23", "79"}, Person{"Ivan", "Ivanovich", "Ivanov"}, Master, "AVTF Syllabus", 18, 0 };
	s1->setDiscipline(Discipline{ 5, "Linear Algebra" });
	s1->setDiscipline(Discipline{ 13, "OLKK" });

	std::cout << *s1 << std::endl;

	return 0;
}
