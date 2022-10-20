#include "copy_from_text_file.hpp"
#include <string>
#include <fstream>
#include <iostream>

const string SEPARATOR = "chapter ";

string CopyTextFromAFile::copy_given_chapter(int wichChapter)
{
    string myChar;
    string myText("");
    string stringCopiedText;
    char copiedtext[200] = " ";
    int copylenght;
    ifstream MyReadFile("story.txt");
    if (MyReadFile.is_open())
    {
        while (MyReadFile)
        {
            myChar = MyReadFile.get();
            myText += myChar;
        }
    }
    string wichChapterSrting = SEPARATOR + to_string(wichChapter);
    size_t chapterStartCharacterNumeber = myText.find(wichChapterSrting) + 1;
    if (chapterStartCharacterNumeber != 0)
    {
        int wichChapterSrtingLenght = wichChapterSrting.length() + 1;
        size_t line;
        if (myText.find(SEPARATOR + to_string(wichChapter + 1)) != -1)
        {
            line = myText.find(SEPARATOR + to_string(wichChapter + 1));
            copylenght = line - (chapterStartCharacterNumeber + wichChapterSrtingLenght+2);
        }
        else
        {
            line = myText.length();
            copylenght = line - (chapterStartCharacterNumeber + wichChapterSrtingLenght + 1);
        }
        myText.copy(copiedtext, copylenght, (chapterStartCharacterNumeber + wichChapterSrtingLenght));
        stringCopiedText = copiedtext;
    }
    else
    {
        stringCopiedText = "nincs ilyen chapter";
    }
    return stringCopiedText;
}
