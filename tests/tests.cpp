#include <vector>

#include <gtest/gtest.h>

#include <SeidelsMethod.h>

struct Item
{
    size_t x, y;
    float_t value;
};

constexpr sfe::SeidelsMethod setup(size_t vars, float_t accuracy, const std::vector<Item>& dataset)
{
    sfe::SeidelsMethod seidelsMethod(vars, accuracy);

    for(auto data : dataset)
    {
        seidelsMethod.add(data.x, data.y, data.value);
    }

    return seidelsMethod;
}

constexpr sfe::SeidelsMethod setupAndCompute(size_t vars, float_t accuracy, const std::vector<Item>& dataset)
{
    auto seidelsMethod = setup(vars, accuracy, dataset);

    seidelsMethod.compute();

    return seidelsMethod;
}

TEST(SeidelsMethod, n_2_0001f)
{
    const auto expected = std::vector<float_t>{0.917f, 0.208f};
    const auto dataset = std::vector<Item> {
        {0, 0, 5}, {1, 0, 2}, {2, 0, 5},
        {0, 1, 3}, {1, 1, 6}, {2, 1, 4}
    };

    const auto n = 2;
    const auto accuracy = 1e-4f;
    const auto eps = 1e-1f;

    auto seidelsMethod = setupAndCompute(n, accuracy, dataset);

    EXPECT_EQ(expected.size(), seidelsMethod.result().size());

    for (size_t i = 0; i < expected.size(); ++i)
    {
        EXPECT_NEAR(expected[i], seidelsMethod.result()[i], eps);
    }
}

TEST(SeidelsMethod, n_3_0001f)
{
    const auto expected = std::vector<float_t>{0.243f, 0.34f, 0.0359f};
    const auto dataset = std::vector<Item> {
        {0, 0, 8}, {1, 0, 3}, {2, 0, 2}, {3, 0, 3},
        {0, 1, 1}, {1, 1, 8}, {2, 1, 1}, {3, 1, 3},
        {0, 2, 3}, {1, 2, 3}, {2, 2, 7}, {3, 2, 2}
    };

    const auto n = 3;
    const auto accuracy = 1e-4f;
    const auto eps = 1e-1f;

    auto seidelsMethod = setupAndCompute(n, accuracy, dataset);

    EXPECT_EQ(expected.size(), seidelsMethod.result().size());

    for (size_t i = 0; i < expected.size(); ++i)
    {
        EXPECT_NEAR(expected[i], seidelsMethod.result()[i], eps);
    }
}

TEST(SeidelsMethod, n_4_0001f)
{
    const auto expected = std::vector<float_t>{0.0149f, 0.124f, 0.0995f, 0.791f};
    const auto dataset = std::vector<Item> {
        {0, 0, 8}, {1, 0, 0}, {2, 0, 3}, {3, 0, 2}, {4, 0, 2},
        {0, 1, 5}, {1, 1, 10}, {2, 1, 1}, {3, 1, 2}, {4, 1, 3},
        {0, 2, 4}, {1, 2, 3}, {2, 2, 12}, {3, 2, 3}, {4, 2, 4},
        {0, 3, 2}, {1, 3, 1}, {2, 3, 1}, {3, 3, 6}, {4, 3, 5}
    };

    const auto n = 4;
    const auto accuracy = 1e-4f;
    const auto eps = 1e-1f;

    auto seidelsMethod = setupAndCompute(n, accuracy, dataset);

    EXPECT_EQ(expected.size(), seidelsMethod.result().size());

    for (size_t i = 0; i < expected.size(); ++i)
    {
        EXPECT_NEAR(expected[i], seidelsMethod.result()[i], eps);
    }
}

TEST(SeidelsMethod, exception_n_2_0001f)
{
    const auto expected = std::vector<float_t>{-3.998f, 4.499f};
    const auto dataset = std::vector<Item> {
        {0, 0, 1}, {1, 0, 2}, {2, 0, 5},
        {0, 1, 3}, {1, 1, 4}, {2, 1, 6}
    };

    const auto n = 2;
    const auto accuracy = 1e-4f;

    auto seidelsMethod = setup(n, accuracy, dataset);

    EXPECT_ANY_THROW(seidelsMethod.compute());

    EXPECT_EQ(expected.size(), seidelsMethod.result().size());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
