#include <vector>

#include <gtest/gtest.h>

#include "SeidelsMethod.h"

TEST(SeidelsMethod, n_2_003f)
{
    const std::vector<float_t> expected {0};

    sfe::SeidelsMethod seidelsMethod(2, 0.003f);
    seidelsMethod.compute();

    EXPECT_EQ(expected.size(), seidelsMethod.result().size());

    for (size_t i = 0; i < expected.size(); ++i)
    {
        EXPECT_FLOAT_EQ(expected[i], seidelsMethod.result()[i]);
    }
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
