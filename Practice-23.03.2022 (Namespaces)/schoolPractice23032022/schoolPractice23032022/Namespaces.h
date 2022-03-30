#pragma once
#include <string>

namespace Countries {
	struct COUNTRY
	{
		std::string capital;
		int population;
	}
	
	Bulgaria{ "Bulgaria", 999932142 }
	;

	namespace Areas
	{
		struct AREAS
		{
			std::string name;
			std::string mayor;
			int population;
		}
		Burgas{"Burgas", "Dimitar", 300000}
		;
	}

}