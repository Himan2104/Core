#include <Core/Math/Vector2.hpp>
#include <cmath>
#include <sys/stat.h>

namespace Core
{
namespace Math
{

    template <typename T>
    constexpr Vector2<T>::Vector2(T x, T y)
        : x{x}
        , y{y}
    {
    }

    template <typename T>
    template <typename U>
    constexpr Vector2<T>::operator Vector2<U>() const
    {
        return Vector2<U>(static_cast<U>(x), static_cast<U>(y));
    }

    template <typename T>
    constexpr T Vector2<T>::SquaredLength() const
    {
        return (x * x) + (y * y);
    }

    template <typename T>
    constexpr T Vector2<T>::Length() const
    {
        return std::sqrt((x * x) + (y * y));
    }

    template <typename T>
    constexpr Vector2<T> Vector2<T>::Normalized() const
    {
        return *this / Length();
    }

    template <typename T>
    constexpr Vector2<T> Vector2<T>::Perpendicular() const
    {
        return Vector2<T>(-y, x);
    }

} // namespace Math
} // namespace Core
