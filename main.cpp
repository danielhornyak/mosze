#include "copy_from_text_file.cpp"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    while (true)
    {
        CopyTextFromAFile object1;
        int number;
        cin >> number;
        string print = object1.copy_given_chapter(number);
        cout << print;
    }
    return 0;
}