#pragma once

#include <Core/Definitions.hpp>
#include <cassert>

namespace Core
{
namespace Math
{
    template <typename T>
    class Vector3
    {
    public:
        constexpr Vector3() = default;
        constexpr Vector3(T x, T y, T z);

        template <typename U>
        constexpr explicit operator Vector3<U>() const;

        [[nodiscard]] constexpr T Length() const;
        [[nodiscard]] constexpr T SquaredLength() const;
        [[nodiscard]] constexpr Vector3 Normalized() const;

        T x{};
        T y{};
        T z{};
    };

    // Operator Overloads

    template <typename T>
    [[nodiscard]] constexpr Vector3<T> operator-(Vector3<T> operand)
    {
        return Vector3<T>(-operand.x, -operand.y, -operand.z);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector3<T> operator+(Vector3<T> lhs, Vector3<T> rhs)
    {
        return Vector3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector3<T> operator-(Vector3<T> lhs, Vector3<T> rhs)
    {
        return Vector3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector3<T> operator*(Vector3<T> lhs, Vector3<T> rhs)
    {
        return Vector3<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector3<T> operator*(T lhs, Vector3<T> rhs)
    {
        return Vector3<T>(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector3<T> operator*(Vector3<T> lhs, T rhs)
    {
        return Vector3<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector3<T> operator/(Vector3<T> lhs, T rhs)
    {
        assert((rhs != 0) && "Division By Zero");
        return Vector3<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
    }

    template <typename T>
    constexpr Vector3<T>& operator+=(Vector3<T>& lhs, Vector3<T> rhs)
    {
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        lhs.z += rhs.z;
        return lhs;
    }

    template <typename T>
    constexpr Vector3<T>& operator-=(Vector3<T>& lhs, Vector3<T> rhs)
    {
        lhs.x -= rhs.x;
        lhs.y -= rhs.y;
        lhs.z -= rhs.z;
        return lhs;
    }

    template <typename T>
    constexpr Vector3<T>& operator*=(Vector3<T>& lhs, T rhs)
    {
        lhs.x *= rhs;
        lhs.y *= rhs;
        lhs.z *= rhs;
        return lhs;
    }

    template <typename T>
    constexpr Vector3<T>& operator/=(Vector3<T>& lhs, T rhs)
    {
        assert((rhs != 0) && "Division by Zero");
        lhs.x /= rhs;
        lhs.y /= rhs;
        lhs.z /= rhs;
        return lhs;
    }

    template <typename T>
    [[nodiscard]] constexpr bool operator==(Vector3<T> lhs, Vector3<T> rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
    }

    template <typename T>
    [[nodiscard]] constexpr bool operator!=(Vector3<T> lhs, Vector3<T> rhs)
    {
        return !(lhs == rhs);
    }

    // Helper Functions

    template <typename T>
    [[nodiscard]] constexpr T Dot(const Vector3<T>& lhs, const Vector3<T>& rhs)
    {
        return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
    }

    template <typename T>
    [[nodiscard]] constexpr Vector3<T> Cross(const Vector3<T>& lhs, const Vector3<T>& rhs)
    {
        return Vector3<T>((lhs.y * rhs.z) - (lhs.z * rhs.y), (lhs.z * rhs.x) - (lhs.x * rhs.z), (lhs.x * rhs.y) - (lhs.y * rhs.x));
    }

} // namespace Math
} // namespace Core
