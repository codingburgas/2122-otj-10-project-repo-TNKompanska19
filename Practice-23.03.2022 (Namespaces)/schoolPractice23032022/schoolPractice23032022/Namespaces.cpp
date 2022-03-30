#include <iostream>
#include "Namespaces.h"
using namespace std;

int main()
{
	cout << Countries::Bulgaria.capital << " " << Countries::Bulgaria.population << endl;
	cout << Countries::Areas::Burgas.name << " " << Countries::Areas::Burgas.mayor << " " << Countries::Areas::Burgas.population;
}
