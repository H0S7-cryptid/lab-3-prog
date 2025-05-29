#include "MAPS.h"

extern std::map <LvlOfEdu, std::string> NameLvl = {
	{Bachelor, "Bachelor`s course"},
	{Master, "Master`s course"},
	{Postgraduate, "Postgraduate course"},
	{UNDEFL, "Unsetted course"}
};

extern std::map <SylStatus, std::string> NameStatus = {
	{Active, "Syllabus is active"},
	{Inactive, "Syllabus is not active"},
};
