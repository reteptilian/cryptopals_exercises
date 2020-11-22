#include "gtest/gtest.h"

#include "exercises/message.h"

TEST(message_test,content)
{
  EXPECT_EQ(get_message(),"Hello World!");
}
