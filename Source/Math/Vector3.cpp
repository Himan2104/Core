#include <Core/Math/Vector3.hpp>
#include <cmath>

namespace Core
{
namespace Math
{
    template <typename T>
    constexpr Vector3<T>::Vector3(T x, T y, T z)
        : x(x)
        , y(y)
        , z(z)
    {
    }

    template <typename T>
    template <typename U>
    constexpr Vector3<T>::operator Vector3<U>() const
    {
        return Vector3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z));
    }

    template <typename T>
    constexpr T Vector3<T>::Length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    template <typename T>
    constexpr T Vector3<T>::SquaredLength() const
    {
        return x * x + y * y + z * z;
    }

    template <typename T>
    constexpr Vector3<T> Vector3<T>::Normalized() const
    {
        return *this / Length();
    }
} // namespace Math
} // namespace Core
