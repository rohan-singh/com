#pragma once
#include <unknwn.h>

struct __declspec(uuid ("75216793-2e4f-4d17-bb4d-aafa5a3fb437"))
IHen : IUnknown
{
	virtual void _stdcall Cluck() = 0;
	virtual void _stdcall Roost() = 0;
};

struct __declspec(uuid ("60f508a2-629b-49cb-bf43-cab735b4414b"))
IHen2 : IHen
{
	virtual void _stdcall Forage() = 0;
};

struct __declspec(uuid ("8d257eb2-b471-477c-a347-a29165afc7e2"))
IOfflineChicken : IUnknown
{
	virtual void _stdcall Load(char const* file) = 0;
	virtual void _stdcall Save(char const* file) = 0;
};

HRESULT _stdcall CreateHen(IHen ** hen);
