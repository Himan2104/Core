#pragma once

#include <Core/Definitions.hpp>
#include <cassert>

namespace Core
{
namespace Math
{
    template <typename T>
    class Vector4
    {
    public:
        constexpr Vector4() = default;
        constexpr Vector4(T x, T y, T z, T w);

        template <typename U>
        constexpr explicit operator Vector4<U>() const;

        [[nodiscard]] constexpr T Length() const;
        [[nodiscard]] constexpr T SquaredLength() const;
        [[nodiscard]] constexpr Vector4 Normalized() const;

        T x{};
        T y{};
        T z{};
        T w{};
    };

    // Operator Overloads

    template <typename T>
    [[nodiscard]] constexpr Vector4<T> operator-(Vector4<T> operand)
    {
        return Vector4<T>(-operand.x, -operand.y, -operand.z, -operand.w);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector4<T> operator+(Vector4<T> lhs, Vector4<T> rhs)
    {
        return Vector4<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector4<T> operator-(Vector4<T> lhs, Vector4<T> rhs)
    {
        return Vector4<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector4<T> operator*(Vector4<T> lhs, Vector4<T> rhs)
    {
        return Vector4<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector4<T> operator*(T lhs, Vector4<T> rhs)
    {
        return Vector4<T>(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.w * lhs);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector4<T> operator*(Vector4<T> lhs, T rhs)
    {
        return Vector4<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector4<T> operator/(Vector4<T> lhs, T rhs)
    {
        assert((rhs != 0) && "Division By Zero");
        return Vector4<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
    }

    template <typename T>
    constexpr Vector4<T>& operator+=(Vector4<T>& lhs, Vector4<T> rhs)
    {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        lhs.z += rhs.z;
        lhs.w += rhs.w;
        return lhs;
    }

    template <typename T>
    constexpr Vector4<T>& operator-=(Vector4<T>& lhs, Vector4<T> rhs)
    {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        lhs.z -= rhs.z;
        lhs.w -= rhs.w;
        return lhs;
    }

    template <typename T>
    constexpr Vector4<T>& operator*=(Vector4<T>& lhs, T rhs)
    {
        lhs.x *= rhs;
        lhs.y *= rhs;
        lhs.z *= rhs;
        lhs.w *= rhs;
        return lhs;
    }

    template <typename T>
    constexpr Vector4<T>& operator/=(Vector4<T>& lhs, T rhs)
    {
        assert((rhs != 0) && "Division by Zero");
        lhs.x /= rhs;
        lhs.y /= rhs;
        lhs.z /= rhs;
        lhs.w /= rhs;
        return lhs;
    }

    template <typename T>
    [[nodiscard]] constexpr bool operator==(Vector4<T> lhs, Vector4<T> rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
    }

    template <typename T>
    [[nodiscard]] constexpr bool operator!=(Vector4<T> lhs, Vector4<T> rhs)
    {
        return !(lhs == rhs);
    }

    // Helper Functions

    template <typename T>
    [[nodiscard]] constexpr T Dot(const Vector4<T>& lhs, const Vector4<T>& rhs)
    {
        return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w);
    }

} // namespace Math
} // namespace Core
