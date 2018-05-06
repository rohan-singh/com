#include "stdafx.h"

#include "Library.h"

int main()
{
	IHen* hen = CreateHen();
	hen->Cluck();

	IHen2* hen2 = static_cast<IHen2*>(hen->As("IHen2"));
	if (hen2)
	{
		hen2->Forage();
		hen2->Release();
	}

	IOfflineChicken* offline = static_cast<IOfflineChicken*>(hen->As("IOfflineChicken"));
	if (offline)
	{
		offline->Save("filename");
		offline->Release();
	}

	hen->Release();
	return 0;
}
