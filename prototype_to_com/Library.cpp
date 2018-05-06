#include "Library.h"

#include<crtdbg.h>
#define ASSERT _ASSERTE

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
	// IUnknown
	//
	ULONG _stdcall AddRef()
	{
		return _InterlockedIncrement(&m_count);
	}

	ULONG _stdcall Release()
	{
		ULONG const result = _InterlockedDecrement(&m_count);
		if (0 == result)
		{
			delete this;
		}
		return result;
	}

	HRESULT __stdcall QueryInterface(IID const& id,
		void ** result)
	{
		ASSERT(result);

		if (id == __uuidof(IHen2) ||
			id == __uuidof(IHen) ||
			id == __uuidof(IUnknown))
		{
			*result = static_cast<IHen2*>(this);
		}
		else if (id == __uuidof(IOfflineChicken))
		{
			*result = static_cast<IOfflineChicken*>(this);
		}
		else
		{
			*result = 0; // basically null
			return E_NOINTERFACE;
		}

		static_cast<IUnknown*>(*result)->AddRef();
		return S_OK;
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

HRESULT __stdcall CreateHen(IHen ** result)
{
	ASSERT(result);
	*result = new(std::nothrow)Hen;

	if (0 == *result)
	{
		return E_OUTOFMEMORY;
	}

	(*result)->AddRef();
	return S_OK;
}
