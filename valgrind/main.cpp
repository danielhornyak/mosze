#include "copy_from_text_file.cpp"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
        CopyTextFromAFile object1;
        string print = object1.copy_given_chapter(1);
        cout << print;
    return 0;
}