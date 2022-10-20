#pragma once
#include <string>

using namespace std;

class CopyTextFromAFile
{
  string copied_string;
  int wich_chapter_are_you_want;

public:
  string copy_given_chapter(int wichChapter);
  CopyTextFromAFile()
  {
    copied_string = "text";
    wich_chapter_are_you_want = 0;
  }
};