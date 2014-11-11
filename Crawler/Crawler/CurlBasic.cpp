//#include <iostream>
//#include <stdio.h> 
//#include <curl/curl.h> 

#include <iostream>
#include <windows.h>

typedef int(*AddFunc)(int, int);
typedef void(*FunctionFunc)();

int main()
{
	AddFunc _AddFunc;
	FunctionFunc _FunctionFunc;
	HINSTANCE hInstLibrary = LoadLibrary("libcurl.dll");

	if (hInstLibrary)
	{
		_AddFunc = (AddFunc)GetProcAddress(hInstLibrary, "Add");
		_FunctionFunc = (FunctionFunc)GetProcAddress(hInstLibrary,
			"Function");

		if (_AddFunc)
		{
			std::cout << "23 = 43 = " << _AddFunc(23, 43) << std::endl;
		}
		if (_FunctionFunc)
		{
			_FunctionFunc();
		}

		FreeLibrary(hInstLibrary);
	} else
	{
		std::cout << "DLL Failed To Load!" << std::endl;
	}

	std::cin.get();

	return 0;
}
/*
int main(void)
{
	
	HMODULE WINAPI LoadLibrary(
		_In_  LPCTSTR libcurl
	);

	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	//if (curl) {
	//	curl_easy_setopt(curl, CURLOPT_URL, "http://google.com");
	//	res = curl_easy_perform(curl);

		/* always cleanup */
		//curl_easy_cleanup(curl);
	//}
	//return 0;
//}