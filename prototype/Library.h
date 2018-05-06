#pragma once

struct IObject
{
	virtual void _stdcall AddRef() = 0;
	virtual void _stdcall Release() = 0;

	virtual void* _stdcall As(char const* type) = 0;
};

struct IHen : IObject
{
	virtual void _stdcall Cluck() = 0;
	virtual void _stdcall Roost() = 0;
};

struct IHen2 : IHen
{
	virtual void _stdcall Forage() = 0;
};

struct IOfflineChicken : IObject
{
	virtual void _stdcall Load(char const* file) = 0;
	virtual void _stdcall Save(char const* file) = 0;
};

IHen* _stdcall CreateHen();
