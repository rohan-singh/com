#include "Library.h"
//#include<iostream>

#include <windows.h> // for OutputDebugString
#define TRACE OutputDebugString

struct Hen : IHen2 , IOfflineChicken
{
	unsigned m_count;

	//ctor
	Hen() : m_count(0)
	{
		TRACE(L"Cheep!\n");
	}

	//dtor
	~Hen()
	{
		TRACE(L"Chicken Soup!\n");
	}

	//
	// IObject
	//
	void _stdcall AddRef()
	{
		++m_count;
	}

	void _stdcall Release()
	{
		if (0 == --m_count)
		{
			delete this;
		}
	}

	// We simply match the appropriate interfaces and then cast to the most derived interface. The resulting interface pointer
	// points to a v-table, which is simply a superset of what's required
	void* _stdcall As(char const* type)
	{
		if (0 == strcmp(type, "IHen2") ||
			0 == strcmp(type, "IHen") ||
			0 == strcmp(type, "IObject"))
		{
			AddRef();
			return static_cast<IHen2*>(this);
		}
		else if(0 == strcmp(type, "IOfflineChicken"))
		{
			AddRef();
			return static_cast<IOfflineChicken*>(this);
		}
		else
		{
			return 0; // basically null
		}
	}

	//
	// IHen
	//
	void _stdcall Cluck()
	{
		TRACE(L"Cluck\n");
	}

	void _stdcall Roost()
	{
		TRACE(L"Roost\n");
	}

	//
	// IHen2
	//
	void _stdcall Forage()
	{
		TRACE(L"Forage!\n");
	}

	//
	// IOfflineChicken
	//
	void _stdcall Load(char const* /*file*/)
	{
		TRACE(L"Cluck\n");
	}

	void _stdcall Save(char const* /*file*/)
	{
		TRACE(L"Roost\n");
	}

};
