/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, leading_single_letter)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, leading_double_letter)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, alternating_letter_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ZzZ");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, middle_mix)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ZZZaaZZZ");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, non_characters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("$%!@");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mixed_empty_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, start_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aA");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, only_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("a$");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, invalid_password)
{
	Password my_password;
	my_password.set("a$");
	bool actual = my_password.authenticate("a$");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, valid_password)
{
	Password my_password;
	my_password.set("DDigimon");
	bool actual = my_password.authenticate("DDigimon");
	ASSERT_EQ(false, actual);
}