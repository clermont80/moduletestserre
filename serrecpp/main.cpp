#include "VerifSeuil.cpp"
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
	VerifSeuil* Verif;
	Verif = new VerifSeuil;

	bool res = Verif->AllumeArrosage();

	if (res == true)
	{
		cout << "ok" << endl;
	}

	return 0;
}