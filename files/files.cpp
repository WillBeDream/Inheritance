// files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

//#define WRITE_TO_FILE


int main()
{
    setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
    cout << "Hello World" << endl;

    std::ofstream fout("file.txt", std::ios::app);
    fout << "Connecting people" << endl;
    fout.close();

    system("notepad file.txt");
#endif // WRITE_TO_FILE
    
    const int SIZE = 10240;
    char buffer[SIZE] = {};

    std::ifstream fin;
    fin.open("file.txt");
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin.getline(buffer, SIZE) >> buffer;
            cout << buffer << endl;
        }
    }
    else
    {
        std::cerr << "Error: file not found";
    }

    fin.close();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
