#include "SYLLABUS.h"

int main() {
	std::cout <<
	Cipher c{};
	std::cout << c << std::endl;
	std::string GETSIP = c.getCipher();
	std::cout << GETSIP << std::endl;
	c.setFullCipher("09.01.03");
	std::cout << c << std::endl;
	c.setParts("03", "01", "09");
	std::cout << c << std::endl;

	Person p{};
	std::cout << p << std::endl;
	std::string GETPER = p.getFname();
	std::cout << GETPER << std::endl;
	p.setFullName("Ivan Ivanov Ivanovich");
	std::cout << p << std::endl;

	Discipline d{12, "Mathematical Analisys"};
	Discipline d1{ d };
	std::cout << d << std::endl;
	std::cout << d1 << std::endl;
	d.setCurrentCU(10);
	d.setDName("Linear Algebra");
	std::cout << d << std::endl;

	TotalDiscip t{};
	t.addDisc(12, "Mathematical Analisys");
	Discipline d{ 5, "Linear Algebra" };
	t.addDisc(d);
	t.addDisc(4, "OLKK");
	std::cout << t;
	
	Syllabus s{ Cipher{"01", "03", "09"}, Person{"Ivan Ivanovich Ivanov"}, Master, "AVTF Syllabus", 18, 0};
	s.setDiscipline(5, "Lin Alg");
	s.setDiscipline(13, "Mat Anal");

	Syllabus* s1 = new Syllabus{ Cipher{"11", "23", "79"}, Person{"Ivan", "Ivanovich", "Ivanov"}, Master, "AVTF Syllabus", 18, 0 };
	s1->setDiscipline(Discipline{ 5, "Linear Algebra" });
	s1->setDiscipline(Discipline{ 13, "Mat Anal" });
	
	return 0;
}
