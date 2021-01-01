#ifndef EXERCISES_SET1_SET_1_H
#define EXERCISES_SET1_SET_1_H

#include <string>

#include "absl/strings/string_view.h"

namespace cryptopals {

std::string ConvertHexToBytes(absl::string_view hex);
uint8_t ConvertHexToInt(char hex);
std::string ConvertHexToBase64(absl::string_view hex);
std::string XorHex(absl::string_view hex1, absl::string_view hex2);

}  // namespace cryptopals

#endif // EXERCISES_SET1_SET_1_H
