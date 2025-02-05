#include <Windows.h>
#include <iostream>
#include <string>

using std::string;

void PrintDirectory(string directory, int depth);

void main()
{
    PrintDirectory("./", 0);
}

void PrintDirectory(string directory, int depth)
{
    HANDLE hFind;
    WIN32_FIND_DATAA data;

    string padding(depth + 1, ' ');

    string searchPath = directory + "\\*";

    hFind = FindFirstFileA(searchPath.c_str(), &data);
    if (hFind != INVALID_HANDLE_VALUE) {
        do 
        {
            // don't process the '.' or '..' entries
            if (strcmp(data.cFileName, ".") == 0 || strcmp(data.cFileName, "..") == 0)
                continue;

                std::cout << padding << data.cFileName << std::endl;

                if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)
                {
                    PrintDirectory(directory + "\\" + data.cFileName, depth + 1);
                }
        } 
        while (FindNextFileA(hFind, &data));
        FindClose(hFind);
    }
}