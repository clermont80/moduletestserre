#include "VerifSeuil.h"
#include <ctime>

float VerifSeuil::Get_TempInt()
{
	return this->SeuilTempInt;
}

float VerifSeuil::Get_TempExt()
{
	return this->SeuilTempExt;
}

int VerifSeuil::Get_Hygro()
{
	return this->SeuilHygro;
}

int VerifSeuil::Get_HumiSol()
{
	return this->SeuilHumiSol;
}

int* VerifSeuil::Get_PlageHoraire()
{
	int horaire[2];
	
	horaire[0] = this->Plageheure; //indice 0 pour heure
	horaire[1] = this->Plageminute; //indice 1 pour minute
	horaire[2] = this->Plageseconde; //indice 2 pour seconde

	return horaire;

}

bool VerifSeuil::AllumeVasistas()
{
	if (this->Hygro >= 85 && this->TempExt >= 10 || this->TempExt >= this->TempInt && this->TempInt <= 10 || this->TempInt >= 25)
	{
		return true;
	}

		return false;
}

bool VerifSeuil::AllumeBrumi()
{
	if (this->TempInt >= 25 || this->Hygro <= 50 && this->TempInt >= 5)
	{
		return true;
	}

		return false;
}

bool VerifSeuil::AllumeChauffage()
{
	if (this->TempInt <= 1)
	{
		return true;
	}
		
		return false;
}

bool VerifSeuil::AllumeArrosage()
{
	
	struct tm newtime;
	time_t dateheureactuelle = time(NULL);
	localtime_s(&newtime, &dateheureactuelle); //on recupere l'heure et la date actuelle
	int heure = newtime.tm_hour;

	if (this->HumiSol < 50 && heure >= 17 || heure <= 11)
	{
		return true;
	}
		return false;
}