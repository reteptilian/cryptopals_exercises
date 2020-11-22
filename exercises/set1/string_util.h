#ifndef EXERCISES_SET1_STRING_UTIL_H
#define EXERCISES_SET1_STRING_UTIL_H

#include <string>

#include "absl/strings/string_view.h"

std::string ConvertHexToBase64(absl::string_view hex);

#endif // EXERCISES_SET1_STRING_UTIL_H
