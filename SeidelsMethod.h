#ifndef SEIDELSMETHOD_H
#define SEIDELSMETHOD_H

#include <vector>

namespace sfe
{

class SeidelsMethod
{
public:
    SeidelsMethod(size_t n, float_t accuracy)
        : _matrix{std::vector<float_t>(n)}, _vector(n), _result(n), _accuracy{accuracy}
    {
    }

    inline void add(size_t x, size_t y, float_t value) noexcept
    {
    }

    inline void compute() noexcept
    {
    }

    inline const auto& vector() const noexcept
    {
        return _vector;
    }

    inline const auto& matrix() const noexcept
    {
        return _matrix;
    }

    inline const auto& result() const noexcept
    {
        return _result;
    }

private:
    std::vector<std::vector<float_t>> _matrix;
    std::vector<float_t> _vector;
    std::vector<float_t> _result;

    float_t _accuracy = 0.0f;
};

}

#endif // SEIDELSMETHOD_H
