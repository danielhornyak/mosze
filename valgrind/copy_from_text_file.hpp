#pragma once
#include <string>

using namespace std;

class CopyTextFromAFile
{
  int wich_chapter_are_you_want;

public:
  string copy_given_chapter(int wichChapter);
  CopyTextFromAFile()
  {
    wich_chapter_are_you_want = 0;
  }
};