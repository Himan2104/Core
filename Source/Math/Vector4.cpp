#include <Core/Math/Vector4.hpp>
#include <cmath>

namespace Core
{
namespace Math
{
    template <typename T>
    constexpr Vector4<T>::Vector4(T x, T y, T z, T w)
        : x(x)
        , y(y)
        , z(z)
        , w(w)
    {
    }

    template <typename T>
    template <typename U>
    constexpr Vector4<T>::operator Vector4<U>() const
    {
        return Vector4<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z), static_cast<U>(w));
    }

    template <typename T>
    constexpr T Vector4<T>::Length() const
    {
        return std::sqrt(x * x + y * y + z * z + w * w);
    }

    template <typename T>
    constexpr T Vector4<T>::SquaredLength() const
    {
        return x * x + y * y + z * z + w * w;
    }

    template <typename T>
    constexpr Vector4<T> Vector4<T>::Normalized() const
    {
        return *this / Length();
    }
} // namespace Math
} // namespace Core
