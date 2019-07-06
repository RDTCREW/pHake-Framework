#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h> 

namespace ph
{
	class Memory
	{
	private:
		MODULEENTRY32 mEntry;
		PROCESSENTRY32 pEntry;

	public:
		HANDLE hProcess;
		DWORD_PTR dwBase;
		DWORD dwPID;

		bool    get_process(const char* ProcessName);
		DWORD64 get_module(const char* lModule);

	};
	extern Memory mem;
}