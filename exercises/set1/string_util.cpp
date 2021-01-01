#include "exercises/set1/string_util.h"

#include "absl/strings/string_view.h"

#include <iostream>

namespace cryptopals {
// namespace {

uint8_t ConvertHexToInt(char hex) {
  if (hex <= '9') {
    return hex - '0';
  }
  char hex_upper = toupper(hex);
  return hex_upper - 'A' + 10;
}

std::string ConvertHexToBytes(absl::string_view hex) {
  size_t num_bytes = hex.size() / 2;
  std::string result;
  for (int byte_index = 0; byte_index < num_bytes; ++byte_index) {
    result.push_back((ConvertHexToInt(hex[byte_index * 2]) << 4) +
                     ConvertHexToInt(hex[byte_index * 2 + 1]));
  }
  return result;
}

  const int kBitsPerByte = 8;
  const int kBitsPerBase64Char = 6;


void SetBit(char& byte, int index, bool val) {
  char mask = 0x1 << (kBitsPerByte - index - 1);
  if (val) {
    byte |= mask;
  } else {
    byte &= ~mask;
  }
}

bool GetBit(absl::string_view bytes, int bit_index) {
  int byte_index = bit_index / kBitsPerByte;
  int relative_bit_index = bit_index % kBitsPerByte;
  char mask = 0x1 << (kBitsPerByte - relative_bit_index - 1);
  bool val = (bytes[byte_index] & mask) >> (kBitsPerByte - relative_bit_index - 1);
  return val;
}

char ConvertByteToBase64Char(char val) {
  if (val < 26) {
    return 'A' + val;
  }
  if (val < 52) {
    return 'a' + (val - 26);
  }
  if (val < 62) {
    return '0' + (val - 52);
  }
  if (val == 62) {
    return '+';
  }
  return '/';
}

std::string ConvertBytesToBase64(absl::string_view bytes) {
  size_t num_b64_chars = bytes.size() * kBitsPerByte / kBitsPerBase64Char;
  std::string result;
  for (int b64_char_index = 0; b64_char_index < num_b64_chars; ++b64_char_index) {
    char val_to_encode = 0;
    for (int relative_bit_index = 0; relative_bit_index < kBitsPerBase64Char; ++relative_bit_index) {
      int bit_index = b64_char_index * kBitsPerBase64Char + relative_bit_index;
      SetBit(val_to_encode, 2 + relative_bit_index, GetBit(bytes, bit_index));
    }
    result.push_back(ConvertByteToBase64Char(val_to_encode));
  }
  return result;
}
  
// } // namespace

std::string ConvertHexToBase64(absl::string_view hex) {
  return ConvertBytesToBase64(ConvertHexToBytes(hex));
}

}  // namespace cryptopals
