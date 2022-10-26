#ifndef SEIDELSMETHOD_H
#define SEIDELSMETHOD_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

namespace sfe
{

class SeidelsMethod
{
public:
    using float_matrix = std::vector<std::vector<float_t>>;

    constexpr SeidelsMethod() = default;

    constexpr SeidelsMethod(size_t n, float_t accuracy)
        : _matrix(n, std::vector<float_t>(n + 1)), _vector(n), _result(n), _accuracy{accuracy}
    {
    }

    constexpr void add(size_t x, size_t y, float_t value) noexcept
    {
        _matrix[y][x] = value;
        _vector[y] = _matrix[y].back();
    }

    constexpr void compute()
    {
        if (_cached == false)
        {
            for (auto& v : _matrix)
                v.pop_back();

            _result = gauss_seidel(matrix(), vector(), _accuracy);
            _cached = true;
        }
    }

    constexpr const std::vector<float_t> &vector() const noexcept
    {
        return _vector;
    }

    constexpr const float_matrix &matrix() const noexcept
    {
        return _matrix;
    }

    constexpr const std::vector<float_t> &result() const noexcept
    {
        return _result;
    }

private:
    inline bool converge(const std::vector<float_t>& X, const std::vector<float_t>& P, float_t eps)
    {
        for (size_t i = 0; i < P.size(); ++i)
            if ((std::fabs(P[i] - X[i]) / X[i]) >= eps)
                return false;

        return true;
    }

    inline bool diagonal(const float_matrix& A)
    {
        const size_t dimension = A.size();

        for (size_t i = 0; i < dimension; ++i)
        {
            const float_t sum = std::accumulate(std::cbegin(A[i]), std::cend(A[i]), 0.0f) - std::abs(A[i][i]);

            if (sum > A[i][i])
            {
                return false;
            }
        }

        return true;
    }

    inline std::vector<float_t> gauss_seidel(const float_matrix& A, const std::vector<float_t>& B, float_t eps)
    {
        const size_t dimension = B.size();

        std::vector<float_t> X(dimension, 1);
        std::vector<float_t> P(dimension, 1);

        if (diagonal(A))
        {
            do
            {
                P = X;

                for (size_t i = 0; i < dimension; ++i)
                {
                    float_t var = 0;

                    for (size_t j = 0; j < dimension; ++j)
                        if(j != i)
                            var += (A[i][j] * X[j]);

                    X[i] = (B[i] - var) / A[i][i];
                }
            } while (!converge(X, P, eps));
        }
        else
        {
            throw std::runtime_error("Invalid matrix");
        }

        return X;
    }

    float_matrix _matrix;
    std::vector<float_t> _vector;
    std::vector<float_t> _result;
    bool _cached = false;

    float_t _accuracy = 0.0f;
};

}

#endif // SEIDELSMETHOD_H
