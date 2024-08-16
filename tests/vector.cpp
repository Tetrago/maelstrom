#include <gtest/gtest.h>

#include <maelstrom/vec.hpp>

using namespace ml;

TEST(vec2, add)
{
	vec2 x = {0, 1};
	vec2 y = {1, 0};
	vec2 o = x + y;

	EXPECT_EQ(o->x, 1);
	EXPECT_EQ(o->y, 1);
}

TEST(vec2, sub)
{
	vec2 x = {0, 1};
	vec2 y = {1, 0};
	vec2 o = x - y;

	EXPECT_EQ(o->x, -1);
	EXPECT_EQ(o->y, 1);
}

TEST(vec2, mul)
{
	vec2 x = {0, 1};
	vec2 o = x * 5.0f;

	EXPECT_EQ(o->x, 0);
	EXPECT_EQ(o->y, 5);
}

TEST(vec2, mag)
{
	vec2 x = {1, 0};
	EXPECT_EQ(mag(x), 1);
}

TEST(vec2, sum)
{
	vec2 x = {1, 2};
	EXPECT_EQ(sum(x), 3);
}

TEST(vec2, dot)
{
	vec2 x = {1, 0};
	vec2 y = {0, 1};
	EXPECT_EQ(dot(x, y), 0);
}
