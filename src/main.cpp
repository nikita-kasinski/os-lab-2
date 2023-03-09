#include <iostream>
#include <windows.h>
#include "thread-functions.h"
#include "arg-struct.h"

int main()
{
	int size = 0;
	std::cout << "Enter array size:\n";
	std::cin >> size;
	if (size < 0)
	{
		std::cerr << "Array size can't be negative\n";
		return 1;
	}
	else
	{
		int *array = new int[size];
		std::cout << "Enter " << size << " integers:\n";
		for (size_t i = 0; i < size; ++i)
		{
			std::cin >> array[i];
		}
		minmax_args m_args;
		m_args.array = array;
		m_args.size = size;

		average_args a_args;
		a_args.array = array;
		a_args.size = size;

		DWORD minmaxThreadId;
		HANDLE minmaxThread = CreateThread(NULL, 0, min_max, (void*) &m_args, 0, &minmaxThreadId);
		WaitForSingleObject(minmaxThread, INFINITE);
		CloseHandle(minmaxThread);

		DWORD averageThreadId;
		HANDLE averageThread = CreateThread(NULL, 0, average, (void*) &a_args, 0, &averageThreadId);
		WaitForSingleObject(averageThread, INFINITE);
		CloseHandle(averageThread);

		*m_args.min = a_args.average;
		*m_args.max = a_args.average;
		std::cout << "Modified array:\n";
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << array[i] << ' ';
		}
		std::cout << "\n";
		delete[] array;
	}
	return 0;
}
