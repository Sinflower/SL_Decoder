#include <iostream>
#include <sstream>
#include <fstream>
#include <codecvt>

std::wstring readFile(std::string fN)
{
	std::wifstream wif(fN);
	wif.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
	std::wstringstream wss;
	wss << wif.rdbuf();
	wif.close();
	return wss.str();
}

void writeFile(std::string fN, std::wstring wstr)
{
	std::wofstream wof(fN);
	wof.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
	wof << wstr;
	wof.close();
}

std::wstring decode(std::wstring wstr)
{
	for(int i = 0; i < wstr.length(); i++)
		wstr[i] ^= 0xFF;

	return wstr;
}

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		std::cout << "Usage: " << argv[0] << ": <sl-file[s]>" << std::endl;
		return 0;
	}
	
	std::string appName(argv[0]);

	for(int i = 1; i < argc; i++)
	{
		std::string fN = argv[i];

		// Skip the application in case wildcards are used
		// and the application is in the same directory
		if(fN == appName) continue;
		
		std::string fNOut = fN.substr(0, fN.find_last_of("."));

		if(fN.find(".sl") != std::string::npos)
			fNOut.append(".txt");
		else if(fN.find(".txt") != std::string::npos)
			fNOut.append(".sl");
		else
			continue;

		std::cout << "Processing: " << fN << "..." << std::endl;

		std::wstring wstr = readFile(fN);

		writeFile(fNOut, decode(wstr));
	}

	return 0;
}