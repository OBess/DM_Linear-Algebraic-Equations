#ifndef SEIDELSMETHOD_H
#define SEIDELSMETHOD_H

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

    constexpr void compute() noexcept
    {
        for (auto& v : _matrix)
            v.pop_back();

        _result = gauss_seidel(matrix(), vector(), _accuracy);
    }

    constexpr const std::vector<float_t> &vector() const noexcept
    {
      return _vector;
    }

    constexpr const float_matrix &matrix() const noexcept
    {
      return _matrix;
    }

    constexpr const auto &result() const noexcept
    {
      return _result;
    }

  private:
    std::vector<float_t> gauss_seidel(const float_matrix& A, const std::vector<float_t>& B, float_t delta)
    {
        const size_t dimension = B.size();
        const size_t iterations = 20;

        std::vector<float_t> X(dimension, 0);
        std::vector<float_t> X0(dimension, 0);
        std::vector<float_t> eps(dimension, 0);
        std::vector<float_t> ksi(dimension, 0);

        float_t eps_max = 0.0f;
        float_t ksi_max = 0.0f;

        for (size_t k = 0; k < iterations; ++k)
        {
            for (size_t i = 0; i < dimension; ++i)
            {
                X[i] = B[i];

                for (size_t j = 0; j < dimension; ++j)
                    if (i != j)
                        X[i] = X[i] - A[i][j] * X[j];

                X[i] = X[i] / A[i][i];
            }

            eps.clear();
            ksi.clear();

            for (size_t i = 0; i < dimension; ++i)
            {
                eps.push_back(std::abs(X[i] - X0[i]));
                ksi.push_back(eps[i] / (std::abs(X[i]) + delta));
            }

            X0 = X;

            eps_max = 0.0f;
            ksi_max = 0.0f;

            for (size_t i = 0; i < dimension; ++i)
            {
                if (eps_max < eps[i]) eps_max = eps[i];
                if (ksi_max < ksi[i]) ksi_max = ksi[i];
            }

            if (eps_max < delta && ksi_max < delta)
                break;
        }

        return X;
    }

    float_matrix _matrix;
    std::vector<float_t> _vector;
    std::vector<float_t> _result;

    float_t _accuracy = 0.0f;
  };

}

#endif // SEIDELSMETHOD_H
