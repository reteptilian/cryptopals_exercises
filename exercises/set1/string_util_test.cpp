#include "gtest/gtest.h"

#include "exercises/set1/string_util.h"

namespace {

using cryptopals::ConvertHexToBase64;
using cryptopals::ConvertHexToBytes;
using cryptopals::ConvertHexToInt;

TEST(ConvertHexToInt, ConvertOne) {
  EXPECT_EQ(ConvertHexToInt('1'), 1);
}

TEST(ConvertHexToInt, ConvertA) {
  EXPECT_EQ(ConvertHexToInt('A'), 10);
}

TEST(ConvertHexToBytes, Convert01) {
  EXPECT_EQ(ConvertHexToBytes("01"), "\x01");
}

TEST(ConvertHexToBase64Test, Convert0x000001) {
  const char test_input[] = "000001";
  const char expected[] = "AAAB";
  EXPECT_EQ(ConvertHexToBase64(test_input), expected);
}

TEST(ConvertHexToBase64Test, Exercise1) {
  const char test_input[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  const char expected[] = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
  EXPECT_EQ(ConvertHexToBase64(test_input), expected);
}

}  // namespace
