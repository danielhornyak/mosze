#include "copy_from_text_file.cpp"
#include <gtest/gtest.h>

TEST(copytextfromtxtc, Handelsallinputs) {
  CopyTextFromAFile object1;
  ASSERT_EQ(object1.copy_given_chapter(0),"nincs ilyen chapter");
  ASSERT_EQ(object1.copy_given_chapter(1),"\r\rsdtfgzudszgafgzesd\r\r");
  ASSERT_EQ(object1.copy_given_chapter(2),"\r\rsdatzfzufsda\r\r");
  ASSERT_EQ(object1.copy_given_chapter(3),"\r\rfzuestgauihsaedfzu");
}


