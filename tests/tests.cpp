#include <vector>

#include <gtest/gtest.h>

#include <SeidelsMethod.h>

struct Item
{
    size_t x, y;
    float_t value;
};

constexpr sfe::SeidelsMethod setupAndCompute(size_t vars, float_t accuracy, const std::vector<Item>& dataset)
{
    sfe::SeidelsMethod seidelsMethod(vars, accuracy);

    for(auto data : dataset)
    {
        seidelsMethod.add(data.x, data.y, data.value);
    }

    seidelsMethod.compute();

    return seidelsMethod;
}

TEST(SeidelsMethod, n_2_0001f)
{
    const auto expected = std::vector<float_t>{-3.998f, 4.499f};
    const auto dataset = std::vector<Item> {
        {0, 0, 1}, {1, 0, 2}, {2, 0, 5},
        {0, 1, 3}, {1, 1, 4}, {2, 1, 6}
    };

    const auto n = 2;
    const auto accuracy = 0.0001f;

    auto seidelsMethod = setupAndCompute(n, accuracy, dataset);

    EXPECT_EQ(expected.size(), seidelsMethod.result().size());

    for (size_t i = 0; i < expected.size(); ++i)
    {
        EXPECT_FLOAT_EQ(expected[i], seidelsMethod.result()[i]);
    }
}

TEST(SeidelsMethod, n_3_0001f)
{
    const auto expected = std::vector<float_t>{3.934f, -24.667f, 19.133f};
    const auto dataset = std::vector<Item> {
        {0, 0, 1}, {1, 0, 2}, {2, 0, 3}, {2, 0, 12},
        {0, 1, 0}, {1, 1, 4}, {2, 1, 5}, {2, 1, -3},
        {0, 2, 6}, {1, 2, 7}, {2, 2, 8}, {2, 2, 4}
    };

    const auto n = 3;
    const auto accuracy = 0.0001f;

    auto seidelsMethod = setupAndCompute(n, accuracy, dataset);

    EXPECT_EQ(expected.size(), seidelsMethod.result().size());

    for (size_t i = 0; i < expected.size(); ++i)
    {
        EXPECT_FLOAT_EQ(expected[i], seidelsMethod.result()[i]);
    }
}

TEST(SeidelsMethod, n_4_0001f)
{
    const auto expected = std::vector<float_t>{-6.372f, 0.779f, 1.558f, 4.285f};
    const auto dataset = std::vector<Item> {
        {0, 0, 1}, {1, 0, 2}, {2, 0, 3}, {3, 0, 4}, {4, 0, 17},
        {0, 1, 5}, {1, 1, 6}, {2, 1, 7}, {3, 1, 8}, {4, 1, 18},
        {0, 2, 9}, {1, 2, 10}, {2, 2, 11}, {3, 2, 12}, {4, 2, 19},
        {0, 3, 13}, {1, 3, 14}, {2, 3, 15}, {3, 3, 16}, {4, 3, 20}
    };

    const auto n = 4;
    const auto accuracy = 0.0001f;

    auto seidelsMethod = setupAndCompute(n, accuracy, dataset);

    EXPECT_EQ(expected.size(), seidelsMethod.result().size());

    for (size_t i = 0; i < expected.size(); ++i)
    {
        EXPECT_FLOAT_EQ(expected[i], seidelsMethod.result()[i]);
    }
}

TEST(SeidelsMethod, n_5_0001f)
{
    const auto expected = std::vector<float_t>{-7.451f, 0.492f, 0.832f, 1.665f, 4.662f};
    const auto dataset = std::vector<Item> {
        {0, 0, 1}, {1, 0, 2}, {2, 0, 3}, {3, 0, 4}, {4, 0, 5}, {5, 0, 26},
        {0, 1, 6}, {1, 1, 7}, {2, 1, 8}, {3, 1, 9}, {4, 1, 10}, {5, 1, 27},
        {0, 2, 11}, {1, 2, 12}, {2, 2, 13}, {3, 2, 14}, {4, 2, 15}, {5, 2, 28},
        {0, 3, 16}, {1, 3, 17}, {2, 3, 18}, {3, 3, 19}, {4, 3, 20}, {5, 3, 29},
        {0, 4, 21}, {1, 4, 22}, {2, 4, 23}, {3, 4, 24}, {4, 4, 25}, {5, 4, 30}
    };

    const auto n = 5;
    const auto accuracy = 0.0001f;

    auto seidelsMethod = setupAndCompute(n, accuracy, dataset);

    EXPECT_EQ(expected.size(), seidelsMethod.result().size());

    for (size_t i = 0; i < expected.size(); ++i)
    {
        EXPECT_FLOAT_EQ(expected[i], seidelsMethod.result()[i]);
    }
}

TEST(SeidelsMethod, n_6_0001f)
{
    const auto expected = std::vector<float_t>{-8.52f, 0.35f, 0.534f, 0.9f, 1.801f, 5.102f};
    const auto dataset = std::vector<Item> {
        {0, 0, 1}, {1, 0, 2}, {2, 0, 3}, {3, 0, 4}, {4, 0, 5}, {5, 0, 6}, {6, 0, 37},
        {0, 1, 7}, {1, 1, 8}, {2, 1, 9}, {3, 1, 10}, {4, 1, 11}, {5, 1, 12}, {6, 1, 38},
        {0, 2, 13}, {1, 2, 14}, {2, 2, 15}, {3, 2, 16}, {4, 2, 17}, {5, 2, 18}, {6, 2, 39},
        {0, 3, 19}, {1, 3, 20}, {2, 3, 21}, {3, 3, 22}, {4, 3, 23}, {5, 3, 24}, {6, 3, 40},
        {0, 4, 25}, {1, 4, 26}, {2, 4, 27}, {3, 4, 28}, {4, 4, 29}, {5, 4, 30}, {6, 4, 41},
        {0, 5, 31}, {1, 5, 32}, {2, 5, 33}, {3, 5, 34}, {4, 5, 35}, {5, 5, 36}, {6, 5, 42}
    };

    const auto n = 6;
    const auto accuracy = 0.0001f;

    auto seidelsMethod = setupAndCompute(n, accuracy, dataset);

    EXPECT_EQ(expected.size(), seidelsMethod.result().size());

    for (size_t i = 0; i < expected.size(); ++i)
    {
        EXPECT_FLOAT_EQ(expected[i], seidelsMethod.result()[i]);
    }
}

TEST(SeidelsMethod, n_7_0001f)
{
    const auto expected = std::vector<float_t>{-9.584f, 0.268f, 0.381f, 0.579f, 0.975f, 1.95f, 5.573f};
    const auto dataset = std::vector<Item> {
        {0, 0, 1}, {1, 0, 2}, {2, 0, 3}, {3, 0, 4}, {4, 0, 5}, {5, 0, 6}, {6, 0, 7}, {7, 0, 50},
        {0, 1, 8}, {1, 1, 9}, {2, 1, 10}, {3, 1, 11}, {4, 1, 12}, {5, 1, 13}, {6, 1, 14}, {7, 1, 51},
        {0, 2, 15}, {1, 2, 16}, {2, 2, 17}, {3, 2, 18}, {4, 2, 19}, {5, 2, 21}, {6, 2, 21}, {7, 2, 52},
        {0, 3, 23}, {1, 3, 24}, {2, 3, 25}, {3, 3, 26}, {4, 3, 27}, {5, 3, 28}, {6, 3, 29}, {7, 3, 53},
        {0, 4, 30}, {1, 4, 31}, {2, 4, 32}, {3, 4, 33}, {4, 4, 34}, {5, 4, 35}, {6, 4, 36}, {7, 4, 54},
        {0, 5, 37}, {1, 5, 38}, {2, 5, 39}, {3, 5, 40}, {4, 5, 41}, {5, 5, 42}, {6, 5, 43}, {7, 5, 55},
        {0, 6, 43}, {1, 6, 44}, {2, 6, 45}, {3, 6, 46}, {4, 6, 47}, {5, 6, 48}, {6, 6, 49}, {7, 6, 56}
    };

    const auto n = 7;
    const auto accuracy = 0.0001f;

    auto seidelsMethod = setupAndCompute(n, accuracy, dataset);

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
