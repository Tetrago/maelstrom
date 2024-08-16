#include <gtest/gtest.h>

#include <maelstrom/vec.hpp>
#include <type_traits>

using namespace ml;

TEST(ind, make_ind)
{
	bool v = std::is_same_v<meta::ind<0, 1, 2>, meta::make_ind<3>>;
	EXPECT_TRUE(v);
}

TEST(ind, size)
{
	EXPECT_EQ(meta::make_ind<0>::size(), 0);
	EXPECT_EQ(meta::make_ind<1>::size(), 1);
	EXPECT_EQ(meta::make_ind<2>::size(), 2);
	EXPECT_EQ(meta::make_ind<3>::size(), 3);
}
