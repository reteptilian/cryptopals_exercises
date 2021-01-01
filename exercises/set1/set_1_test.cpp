#include "gtest/gtest.h"

#include "exercises/set1/set_1.h"

namespace {

using cryptopals::ConvertHexToBase64;
using cryptopals::ConvertHexToBytes;
using cryptopals::ConvertHexToInt;
using cryptopals::XorHex;

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

TEST(Set1Test, Exercise1_ConvertHexToBase64) {
  const char test_input[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  const char expected[] = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
  EXPECT_EQ(ConvertHexToBase64(test_input), expected);
}

TEST(Set1Test, Exercise2_FixedXor) {
  EXPECT_EQ(XorHex("1c0111001f010100061a024b53535009181c", "686974207468652062756c6c277320657965"),
            "746865206b696420646f6e277420706c6179");
}

}  // namespace
