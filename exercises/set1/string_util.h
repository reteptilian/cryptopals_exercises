#ifndef EXERCISES_SET1_STRING_UTIL_H
#define EXERCISES_SET1_STRING_UTIL_H

#include <string>

#include "absl/strings/string_view.h"

namespace cryptopals {

std::string ConvertHexToBytes(absl::string_view hex);
uint8_t ConvertHexToInt(char hex);
std::string ConvertHexToBase64(absl::string_view hex);

}  // namespace cryptopals

#endif // EXERCISES_SET1_STRING_UTIL_H
