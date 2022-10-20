#include "copy_from_text_file.cpp"
#include <gtest/gtest.h>

TEST(copytextfromtxt, Handelsallinputs) {
  CopyTextFromAFile object1;
  EXPECT_EQ(object1.copy_given_chapter(0),"nincs ilyen chapter");
  EXPECT_EQ(object1.copy_given_chapter(1),"sdtfgzudszgafgzesd");
  EXPECT_EQ(object1.copy_given_chapter(2),"sdatzfzufsda");
  EXPECT_EQ(object1.copy_given_chapter(3),"fzuestgauihsaedfzu");
}


