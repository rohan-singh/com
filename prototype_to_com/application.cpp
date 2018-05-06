#include "Library.h"

int main()
{
	IHen* hen;

	if (S_OK != CreateHen(&hen))
	{
		return 0;
	}
	hen->Cluck();

	IHen2* hen2;
	//if (S_OK == hen->QueryInterface(__uuidof(IHen2), reinterpret_cast<void**>(&hen2)))
	if (S_OK == hen->QueryInterface(&hen2))
	{
		hen2->Forage();
		hen2->Release();
	}

	IOfflineChicken* offline;
	if (S_OK == hen->QueryInterface(&offline))
	{
		offline->Save("filename");
		offline->Release();
	}

	hen->Release();
	return 0;
}
