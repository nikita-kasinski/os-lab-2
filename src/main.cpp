#include <iostream>
#include <windows.h>
#include "thread-functions.h"
#include "arg-struct.h"

int main()
{
	size_t size = 0;
	int initialSize;

	std::cout << "Enter array size:\n";
	std::cin >> initialSize;

	if (initialSize < 0)
	{
		std::cerr << "Array size can't be negative\n";
		return 1;
	}
	else
	{
		size = static_cast<size_t>(initialSize);

		int *array = new int[size];
		std::cout << "Enter " << size << " integers:\n";
		for (size_t i = 0; i < size; ++i)
		{
			std::cin >> array[i];
		}

		CRITICAL_SECTION *iocs = new CRITICAL_SECTION;
		InitializeCriticalSection(iocs);
		
		minmax_args m_args;
		m_args.array = array;
		m_args.size = size;
		m_args.iocs = iocs;

		average_args a_args;
		a_args.array = array;
		a_args.size = size;
		a_args.iocs = iocs;



		DWORD minmaxThreadId;
		HANDLE minmaxThread = CreateThread(NULL, 0, min_max, (void*) &m_args, 0, &minmaxThreadId);

		DWORD averageThreadId;
		HANDLE averageThread = CreateThread(NULL, 0, average, (void*) &a_args, 0, &averageThreadId);

		std::cout << "Created threads\n";

		WaitForSingleObject(minmaxThread, INFINITE);
		WaitForSingleObject(averageThread, INFINITE);
		CloseHandle(averageThread);
		CloseHandle(minmaxThread);

		array[m_args.indexMin] = a_args.average;
		array[m_args.indexMax] = a_args.average;

		std::cout << "Modified array:\n";
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << array[i] << ' ';
		}
		std::cout << "\n";

		delete[] array;
		delete iocs;
	}
	return 0;
}
