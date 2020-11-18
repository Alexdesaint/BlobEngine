#pragma once

#include <array>
#include <cmath>
#include <list> // TODO: remove this
#include <ostream>
#define PI 3.141592653589793238462643383279502884L

namespace Blob::Maths {

template<typename T = float>
class Vec2 {
public:
    T x = 0, y = 0;

    // Constructors
    inline Vec2() = default;

    inline Vec2(T x, T y) : x(x), y(y) {}

    inline explicit Vec2(T xy) : x(xy), y(xy) {}

    inline Vec2(const Vec2 &v) : x(v.x), y(v.y) {}

    inline Vec2(const Vec2 &point1, const Vec2 &point2) {
        x = point2.x - point1.x;
        y = point2.y - point1.y;
    }

    // operator with Vec2
    inline bool operator==(const Vec2 &v) const { return x == v.x && y == v.y; }

    inline bool operator!=(const Vec2 &v) const { return x != v.x || y != v.y; }

    inline Vec2 operator-(const Vec2 &v) const { return {x - v.x, y - v.y}; }

    inline Vec2 operator+(const Vec2 &v) const { return {x + v.x, y + v.y}; }

    inline void operator+=(const Vec2 &v) {
        x += v.x;
        y += v.y;
    }

    inline void operator-=(const Vec2 &v) {
        x -= v.x;
        y -= v.y;
    }

    inline Vec2 &operator=(const Vec2 &v) {
        x = v.x;
        y = v.y;
        return *this;
    }

    // operator with T
    inline Vec2 operator+(T a) const { return {a + x, a + y}; }

    inline Vec2 operator-(T a) const { return {x - a, y - a}; }

    inline Vec2 operator*(T a) const { return {a * x, a * y}; }

    inline Vec2 operator/(T a) const { return {x / a, y / a}; }

    inline void operator+=(T a) {
        x += a;
        y += a;
    }

    inline void operator-=(T a) {
        x -= a;
        y -= a;
    }

    inline void operator*=(T a) {
        x *= a;
        y *= a;
    }

    inline void operator/=(T a) {
        x /= a;
        y /= a;
    }

    inline Vec2 &operator=(const T a) {
        x = a;
        y = a;
        return *this;
    }

    // Functions
    [[nodiscard]] inline T length2() const { return x * x + y * y; }

    [[nodiscard]] inline T length() const { return std::sqrt(x * x + y * y); };

    // [[nodiscard]] inline T scalar(const Vec2 &B) const { return x * B.x + y * B.y; }

    [[nodiscard]] inline T dot(const Vec2 &B) const { return x * B.x + y * B.y; }

    // [[nodiscard]] inline Vec2 cross(const Vec2 &B) const { return {y, -x}; }

    [[nodiscard]] inline Vec2 normalize() const { return operator/(std::sqrt(x * x + y * y)); }

    inline Vec2 setLength(T newLength) { return *this = *this / std::sqrt(x * x + y * y) * newLength; }

    [[nodiscard]] inline Vec2 rotate() const { return {y, -x}; }

    [[nodiscard]] inline Vec2 negate() const { return {-x, -y}; }

    [[nodiscard]] inline double getOrientation() const { return std::atan2(y, x); }

    [[nodiscard]] inline double getOrientationDeg() const { return std::atan2(y, x) * 180 / PI; }

    [[nodiscard]] inline bool isNull() const { return ((x == 0) && (y == 0)); }

    template<typename U>
    inline Vec2<U> cast() const {
        return {(U) x, (U) y};
    }

    // Print operator
    friend std::ostream &operator<<(std::ostream &os, const Vec2 &dt) {
        os << dt.x << ", " << dt.y;
        return os;
    }
};

template<typename T = float>
class Vec3 {
public:
    T x = 0, y = 0, z = 0;

    // Constructors
    Vec3() = default;

    explicit Vec3(T xyz) : x(xyz), y(xyz), z(xyz) {}

    Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    explicit Vec3(T xyz[3]) : x(xyz[0]), y(xyz[1]), z(xyz[2]) {}

    Vec3(const Vec2<T> &v, T u) : x(v.x), y(v.y), z(u) {}

    Vec3(const Vec3 &v) : x(v.x), y(v.y), z(v.z) {}

    Vec3(const Vec3 &point1, const Vec3 &point2) {
        x = point2.x - point1.x;
        y = point2.y - point1.y;
        z = point2.z - point1.z;
    }

    // operator with Vec3
    bool operator==(const Vec3 &v) const { return x == v.x && y == v.y && z == v.z; }

    bool operator!=(const Vec3 &v) const { return x != v.x || y != v.y || z != v.z; }

    Vec3 operator-(const Vec3 &v) const { return {x - v.x, y - v.y, z - v.z}; }

    Vec3 operator+(const Vec3 &v) const { return {x + v.x, y + v.y, z + v.z}; }

    Vec3 operator*(const Vec3 &v) const { return {x * v.x, y * v.y, z * v.z}; }

    Vec3 operator/(const Vec3 &v) const { return {x / v.x, y / v.y, z / v.z}; }

    void operator+=(const Vec3 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
    }

    void operator-=(const Vec3 &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
    }

    void operator*=(const Vec3 &v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
    }

    void operator/=(const Vec3 &v) {
        x /= v.x;
        y /= v.y;
        z /= v.z;
    }

    Vec3 &operator=(const Vec3 &v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    Vec3 &operator=(const Vec2<T> &v) {
        x = v.x;
        y = v.y;
        return *this;
    }

    // operator with T
    Vec3 operator+(const T &a) const { return {a + x, a + y, a + z}; }

    Vec3 operator-(const T &a) const { return {x - a, y - a, a - z}; }

    Vec3 operator*(const T &a) const { return {a * x, a * y, a * z}; }

    Vec3 operator/(const T &a) const { return {x / a, y / a, z / a}; }

    void operator+=(const T &a) {
        x += a;
        y += a;
        z += a;
    }

    void operator-=(const T &a) {
        x -= a;
        y -= a;
        z -= a;
    }

    void operator*=(const T &a) {
        x *= a;
        y *= a;
        z *= a;
    }

    void operator/=(const T &a) {
        x /= a;
        y /= a;
        z /= a;
    }

    Vec3 &operator=(const T &a) {
        x = a;
        y = a;
        z = a;
        return *this;
    }

    // Functions
    [[nodiscard]] T length2() const { return x * x + y * y + z * z; }

    [[nodiscard]] double length() const { return std::sqrt(x * x + y * y + z * z); };

    [[nodiscard]] T scalar(const Vec3 &B) const { return x * B.x + y * B.y + z * B.z; }

    [[nodiscard]] T dot(const Vec3 &B) const { return x * B.x + y * B.y + z * B.z; }

    [[nodiscard]] Vec3 cross(const Vec3 &B) const { return {y * B.z - B.y * z, z * B.x - B.z * x, x * B.y - B.x * y}; }

    Vec3 normalize() const {
        float t = 1.f / (std::sqrt(x * x + y * y + z * z));
        return {x * t, y * t, z * t};
    }

    [[nodiscard]] Vec3<T> getNormal() const { return operator/(std::sqrt(x * x + y * y + z * z)); }

    Vec3<T> setLength(double newLength) { return operator=(operator/=(std::sqrt(x * x + y * y + z * z)) * newLength); }

    [[nodiscard]] bool isNull() const { return (x == 0) && (y == 0) && (z == 0); }

    template<typename U>
    Vec3<U> cast() const {
        return {(U) x, (U) y, (U) z};
    }

    // Print operator
    friend std::ostream &operator<<(std::ostream &os, const Vec3 &dt) {
        os << dt.x << ", " << dt.y << ", " << dt.z;
        return os;
    }
};

template<typename T = float>
class Vec4 {
public:
    T x = 0, y = 0, z = 0, w = 0;

    // Constructors
    Vec4() = default;

    explicit Vec4(T xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}

    explicit Vec4(T xyzw[4]) : x(xyzw[0]), y(xyzw[1]), z(xyzw[2]), w(xyzw[3]) {}

    Vec4(T x, T y, T z, T w = 1) : x(x), y(y), z(z), w(w) {}

    Vec4(const Vec4 &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

    Vec4(const Vec4 &point1, const Vec4 &point2) {
        x = point2.x - point1.x;
        y = point2.y - point1.y;
        z = point2.z - point1.z;
        w = point2.w - point1.w;
    }

    // operator with Vec4
    bool operator==(const Vec4 &v) const { return x == v.x && y == v.y && z == v.z && w == v.w; }

    bool operator!=(const Vec4 &v) const { return x != v.x || y != v.y || z != v.z || w != v.w; }

    Vec4 operator-(const Vec4 &v) const { return {x - v.x, y - v.y, z - v.z, w - v.w}; }

    Vec4 operator+(const Vec4 &v) const { return {x + v.x, y + v.y, z + v.z, w + v.w}; }

    Vec4 operator*(const Vec4 &a) const { return {a.x * x, a.y * y, a.z * z, a.w * w}; }

    void operator+=(const Vec4 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
    }

    void operator-=(const Vec4 &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
    }

    Vec4 &operator=(const Vec4 &v) {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }

    // operator with T
    Vec4 operator+(const T &a) const { return {a + x, a + y, a + z, a + w}; }

    Vec4 operator-(const T &a) const { return {x - a, y - a, a - z, a - w}; }

    Vec4 operator*(const T &a) const { return {a * x, a * y, a * z}; }

    Vec4 operator/(const T &a) const { return {x / a, y / a, z / a, w / a}; }

    void operator+=(const T &a) {
        x += a;
        y += a;
        z += a;
        w += a;
    }

    void operator-=(const T &a) {
        x -= a;
        y -= a;
        z -= a;
        w -= a;
    }

    void operator*=(const T &a) {
        x *= a;
        y *= a;
        z *= a;
        w *= a;
    }

    void operator/=(const T &a) {
        x /= a;
        y /= a;
        z /= a;
        w /= a;
    }

    Vec4 &operator=(const T &a) {
        x = a;
        y = a;
        z = a;
        w = a;
        return *this;
    }

    explicit operator Vec3<T>() const { return {x, y, z}; }

    // Functions
    [[nodiscard]] T length2() const { return x * x + y * y + z * z + w * w; }

    [[nodiscard]] double length() const { return std::sqrt(x * x + y * y + z * z + w * w); };

    [[nodiscard]] T scalar(const Vec4 &B) const { return x * B.x + y * B.y + z * B.z + w * B.w; }

    [[nodiscard]] T dot(const Vec4 &B) const { return x * B.x + y * B.y + z * B.z + w * B.w; }

    /*
               [[nodiscard]] Vec4<T> getNormal() const { return operator/(std::sqrt(x * x + y * y + z * z)); }

               Vec4<T> setLength(double newLength) { return operator=(operator/=(std::sqrt(x * x + y * y + z * z)) * newLength); }

               */

    Vec4 normalize() const {
        float t = 1.f / (std::sqrt(x * x + y * y + z * z + w * w));
        return {x * t, y * t, z * t, w * t};
    }

    [[nodiscard]] bool isNull() const { return (x == 0) && (y == 0) && (z == 0) && (w == 1); }

    template<typename U>
    Vec4<U> cast() const {
        return {(U) x, (U) y, (U) z, (U) z};
    }

    // Print operator
    friend std::ostream &operator<<(std::ostream &os, const Vec4 &dt) {
        os << dt.x << ", " << dt.y << ", " << dt.z << ", " << dt.w;
        return os;
    }
};

class Mat3 {
public:
    float a11 = 1, a12 = 0, a13 = 0;
    float a21 = 0, a22 = 1, a23 = 0;
    float a31 = 0, a32 = 0, a33 = 1;

    Mat3() noexcept = default;

    Mat3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33) noexcept
        : a11(a11), a12(a12), a13(a13), a21(a21), a22(a22), a23(a23), a31(a31), a32(a32), a33(a33) {}

    explicit Mat3(const std::array<float, 9> &mat) noexcept
        : a11(mat[0]), a12(mat[1]), a13(mat[2]), a21(mat[3]), a22(mat[4]), a23(mat[5]), a31(mat[6]), a32(mat[7]), a33(mat[8]) {}

    void load(const std::array<float, 9> &mat) {
        a11 = mat[0];
        a12 = mat[1];
        a13 = mat[2];
        a21 = mat[3];
        a22 = mat[4];
        a23 = mat[5];
        a31 = mat[6];
        a32 = mat[7];
        a33 = mat[8];
    }

    Mat3 operator+(const Mat3 &v) const {
        return {a11 + v.a11, a12 + v.a12, a13 + v.a13, a21 + v.a21, a22 + v.a22, a23 + v.a23, a31 + v.a31, a32 + v.a32, a33 + v.a33};
    }

    Mat3 operator-(const Mat3 &v) const {
        return {a11 - v.a11, a12 - v.a12, a13 - v.a13, a21 - v.a21, a22 - v.a22, a23 - v.a23, a31 - v.a31, a32 - v.a32, a33 - v.a33};
    }

    Mat3 operator*(const Mat3 &v) const {
        return {a11 * v.a11 + a12 * v.a21 + a13 * v.a31, a11 * v.a12 + a12 * v.a22 + a13 * v.a32, a11 * v.a13 + a12 * v.a23 + a13 * v.a33,
                a21 * v.a11 + a22 * v.a21 + a23 * v.a31, a21 * v.a12 + a22 * v.a22 + a23 * v.a32, a21 * v.a13 + a22 * v.a23 + a23 * v.a33,
                a31 * v.a11 + a32 * v.a21 + a33 * v.a31, a31 * v.a12 + a32 * v.a22 + a33 * v.a32, a31 * v.a13 + a32 * v.a23 + a33 * v.a33};
    }

    friend std::ostream &operator<<(std::ostream &os, const Mat3 &m) {
        os << m.a11 << ", " << m.a12 << ", " << m.a13 << std::endl;
        os << m.a21 << ", " << m.a22 << ", " << m.a23 << std::endl;
        os << m.a31 << ", " << m.a32 << ", " << m.a33 << std::endl;
        return os;
    }
};

class Mat4 {
public:
    float a11 = 1, a12 = 0, a13 = 0, a14 = 0;
    float a21 = 0, a22 = 1, a23 = 0, a24 = 0;
    float a31 = 0, a32 = 0, a33 = 1, a34 = 0;
    float a41 = 0, a42 = 0, a43 = 0, a44 = 1;

    Mat4() noexcept = default;

    explicit Mat4(float val)
        : a11(val), a12(val), a13(val), a14(val), a21(val), a22(val), a23(val), a24(val), a31(val), a32(val), a33(val), a34(val), a41(val), a42(val),
          a43(val), a44(val) {}

    Mat4(const Vec4<float> &a1, const Vec4<float> &a2, const Vec4<float> &a3, const Vec4<float> &a4)
        : a11(a1.x), a12(a1.y), a13(a1.z), a14(a1.w), a21(a2.x), a22(a2.y), a23(a2.z), a24(a2.w), a31(a3.x), a32(a3.y), a33(a3.z), a34(a3.w),
          a41(a4.x), a42(a4.y), a43(a4.z), a44(a4.w) {}

    Mat4(float a11, float a12, float a13, float a14, float a21, float a22, float a23, float a24, float a31, float a32, float a33, float a34,
         float a41, float a42, float a43, float a44) noexcept
        : a11(a11), a12(a12), a13(a13), a14(a14), a21(a21), a22(a22), a23(a23), a24(a24), a31(a31), a32(a32), a33(a33), a34(a34), a41(a41), a42(a42),
          a43(a43), a44(a44) {}

    Mat4(const Mat4 &mat) noexcept = default;

    explicit Mat4(const std::array<float, 16> &mat) noexcept
        : a11(mat[0]), a12(mat[1]), a13(mat[2]), a14(mat[3]), a21(mat[4]), a22(mat[5]), a23(mat[6]), a24(mat[7]), a31(mat[8]), a32(mat[9]),
          a33(mat[10]), a34(mat[11]), a41(mat[12]), a42(mat[13]), a43(mat[14]), a44(mat[15]) {}

    void load(const std::array<float, 16> &mat) {
        a11 = mat[0];
        a12 = mat[1];
        a13 = mat[2];
        a14 = mat[3];
        a21 = mat[4];
        a22 = mat[5];
        a23 = mat[6];
        a24 = mat[7];
        a31 = mat[8];
        a32 = mat[9];
        a33 = mat[10];
        a34 = mat[11];
        a41 = mat[12];
        a42 = mat[13];
        a43 = mat[14];
        a44 = mat[15];
    }

    Mat4 operator+(float val) const {
        return {a11 + val, a12 + val, a13 + val, a14 + val, a21 + val, a22 + val, a23 + val, a24 + val,
                a31 + val, a32 + val, a33 + val, a34 + val, a41 + val, a42 + val, a43 + val, a44 + val};
    }
    Mat4 operator-(float val) const {
        return {a11 - val, a12 - val, a13 - val, a14 - val, a21 - val, a22 - val, a23 - val, a24 - val,
                a31 - val, a32 - val, a33 - val, a34 - val, a41 - val, a42 - val, a43 - val, a44 - val};
    }
    Mat4 operator*(float val) const {
        return {a11 * val, a12 * val, a13 * val, a14 * val, a21 * val, a22 * val, a23 * val, a24 * val,
                a31 * val, a32 * val, a33 * val, a34 * val, a41 * val, a42 * val, a43 * val, a44 * val};
    }
    Mat4 operator/(float val) const {
        return {a11 / val, a12 / val, a13 / val, a14 / val, a21 / val, a22 / val, a23 / val, a24 / val,
                a31 / val, a32 / val, a33 / val, a34 / val, a41 / val, a42 / val, a43 / val, a44 / val};
    }

    Vec4<float> operator*(const Vec4<float> &val) const {
        return {
            a11 * val.x + a12 * val.y + a13 * val.z + a14 * val.w,
            a21 * val.x + a22 * val.y + a23 * val.z + a24 * val.w,
            a31 * val.x + a32 * val.y + a33 * val.z + a34 * val.w,
            a41 * val.x + a42 * val.y + a43 * val.z + a44 * val.w,
        };
    }

    Mat4 operator+(const Mat4 &v) const {
        return {a11 + v.a11, a12 + v.a12, a13 + v.a13, a14 + v.a14, a21 + v.a21, a22 + v.a22, a23 + v.a23, a24 + v.a24,
                a31 + v.a31, a32 + v.a32, a33 + v.a33, a34 + v.a34, a41 + v.a41, a42 + v.a42, a43 + v.a43, a44 + v.a44};
    }

    Mat4 operator-(const Mat4 &v) const {
        return {a11 - v.a11, a12 - v.a12, a13 - v.a13, a14 - v.a14, a21 - v.a21, a22 - v.a22, a23 - v.a23, a24 - v.a24,
                a31 - v.a31, a32 - v.a32, a33 - v.a33, a34 - v.a34, a41 - v.a41, a42 - v.a42, a43 - v.a43, a44 - v.a44};
    }
    Mat4 operator*(const Mat4 &v) const {
        return {
            a11 * v.a11 + a12 * v.a21 + a13 * v.a31 + a14 * v.a41, a11 * v.a12 + a12 * v.a22 + a13 * v.a32 + a14 * v.a42,
            a11 * v.a13 + a12 * v.a23 + a13 * v.a33 + a14 * v.a43, a11 * v.a14 + a12 * v.a24 + a13 * v.a34 + a14 * v.a44,

            a21 * v.a11 + a22 * v.a21 + a23 * v.a31 + a24 * v.a41, a21 * v.a12 + a22 * v.a22 + a23 * v.a32 + a24 * v.a42,
            a21 * v.a13 + a22 * v.a23 + a23 * v.a33 + a24 * v.a43, a21 * v.a14 + a22 * v.a24 + a23 * v.a34 + a24 * v.a44,

            a31 * v.a11 + a32 * v.a21 + a33 * v.a31 + a34 * v.a41, a31 * v.a12 + a32 * v.a22 + a33 * v.a32 + a34 * v.a42,
            a31 * v.a13 + a32 * v.a23 + a33 * v.a33 + a34 * v.a43, a31 * v.a14 + a32 * v.a24 + a33 * v.a34 + a34 * v.a44,

            a41 * v.a11 + a42 * v.a21 + a43 * v.a31 + a44 * v.a41, a41 * v.a12 + a42 * v.a22 + a43 * v.a32 + a44 * v.a42,
            a41 * v.a13 + a42 * v.a23 + a43 * v.a33 + a44 * v.a43, a41 * v.a14 + a42 * v.a24 + a43 * v.a34 + a44 * v.a44,
        };
    }

    [[nodiscard]] Mat4 inverse() const {
        float Coef00 = (a33 * a44 - a43 * a34);
        float Coef02 = (a23 * a44 - a43 * a24);
        float Coef03 = (a23 * a34 - a33 * a24);

        float Coef04 = (a32 * a44 - a42 * a34);
        float Coef06 = (a22 * a44 - a42 * a24);
        float Coef07 = (a22 * a34 - a32 * a24);

        float Coef08 = (a32 * a43 - a42 * a33);
        float Coef10 = (a22 * a43 - a42 * a23);
        float Coef11 = (a22 * a33 - a32 * a23);

        float Coef12 = (a31 * a44 - a41 * a34);
        float Coef14 = (a21 * a44 - a41 * a24);
        float Coef15 = (a21 * a34 - a31 * a24);

        float Coef16 = (a31 * a43 - a41 * a33);
        float Coef18 = (a21 * a43 - a41 * a23);
        float Coef19 = (a21 * a33 - a31 * a23);

        float Coef20 = (a31 * a42 - a41 * a32);
        float Coef22 = (a21 * a42 - a41 * a22);
        float Coef23 = (a21 * a32 - a31 * a22);

        Vec4<float> Fac0(Coef00, Coef00, Coef02, Coef03);
        Vec4<float> Fac1(Coef04, Coef04, Coef06, Coef07);
        Vec4<float> Fac2(Coef08, Coef08, Coef10, Coef11);
        Vec4<float> Fac3(Coef12, Coef12, Coef14, Coef15);
        Vec4<float> Fac4(Coef16, Coef16, Coef18, Coef19);
        Vec4<float> Fac5(Coef20, Coef20, Coef22, Coef23);

        Vec4<float> vec0(a21, a11, a11, a11);
        Vec4<float> vec1(a22, a12, a12, a12);
        Vec4<float> vec2(a23, a13, a13, a13);
        Vec4<float> vec3(a24, a14, a14, a14);

        Vec4<float> Inv0(vec1 * Fac0 - vec2 * Fac1 + vec3 * Fac2);
        Vec4<float> Inv1(vec0 * Fac0 - vec2 * Fac3 + vec3 * Fac4);
        Vec4<float> Inv2(vec0 * Fac1 - vec1 * Fac3 + vec3 * Fac5);
        Vec4<float> Inv3(vec0 * Fac2 - vec1 * Fac4 + vec2 * Fac5);

        Vec4<float> SignA(+1, -1, +1, -1);
        Vec4<float> SignB(-1, +1, -1, +1);
        Mat4 Inverse(Inv0 * SignA, Inv1 * SignB, Inv2 * SignA, Inv3 * SignB);

        Vec4<float> Row0(Inverse.a11, Inverse.a21, Inverse.a31, Inverse.a41);

        Vec4<float> Dot0(Vec4<float>(a11, a21, a31, a41) * Row0);
        float Dot1 = (Dot0.x + Dot0.y) + (Dot0.z + Dot0.w);

        float OneOverDeterminant = 1.f / Dot1;

        return Inverse * OneOverDeterminant;
    }

    friend std::ostream &operator<<(std::ostream &os, const Mat4 &m) {
        os << m.a11 << ", " << m.a12 << ", " << m.a13 << ", " << m.a14 << ", "; // << std::endl;
        os << m.a21 << ", " << m.a22 << ", " << m.a23 << ", " << m.a24 << ", "; // << std::endl;
        os << m.a31 << ", " << m.a32 << ", " << m.a33 << ", " << m.a34 << ", "; // << std::endl;
        os << m.a41 << ", " << m.a42 << ", " << m.a43 << ", " << m.a44;         // << std::endl;
        return os;
    }
};

class ModelTransform : public Mat4 {
private:
    Vec3<float> scale = {1, 1, 1};
    Mat3 rotation;

    void compute() {
        a11 = rotation.a11 * scale.x;
        a12 = rotation.a12 * scale.x;
        a13 = rotation.a13 * scale.x;
        // a14 = 0.f
        a21 = rotation.a21 * scale.y;
        a22 = rotation.a22 * scale.y;
        a23 = rotation.a23 * scale.y;
        // a24 = 0.f;
        a31 = rotation.a31 * scale.z;
        a32 = rotation.a32 * scale.z;
        a33 = rotation.a33 * scale.z;
        // a34 = 0.f;
        // a41 = translation.x;
        // a42 = translation.y;
        // a43 = translation.z;
        // a44 = 1.f;
    }

public:
    using Mat4::Mat4;

    explicit ModelTransform(const Mat4 &mat4) : Mat4(mat4) {}

    void setPosition(const Vec3<float> &xyz) {
        a41 = xyz.x;
        a42 = xyz.y;
        a43 = xyz.z;
    }

    void setPosition(const Vec2<float> &xy, float z) {
        a41 = xy.x;
        a42 = xy.y;
        a43 = z;
    }

    void setPosition(const Vec2<float> &xy) {
        a41 = xy.x;
        a42 = xy.y;
    }

    void move(const Vec3<float> &xyz) {
        a41 += xyz.x;
        a42 += xyz.y;
        a43 += xyz.z;
    }

    void setRotation(float angle, const Vec3<float> &xyz) {
        const float c = std::cos(angle);
        const float s = std::sin(angle);

        auto n = xyz.getNormal();
        float axis[3] = {n.x, n.y, n.z};
        float temp[3] = {axis[0] * (1.f - c), axis[1] * (1.f - c), axis[2] * (1.f - c)};

        rotation.a11 = c + temp[0] * axis[0];
        rotation.a12 = temp[0] * axis[1] + s * axis[2];
        rotation.a13 = temp[0] * axis[2] - s * axis[1];

        rotation.a21 = temp[1] * axis[0] - s * axis[2];
        rotation.a22 = c + temp[1] * axis[1];
        rotation.a23 = temp[1] * axis[2] + s * axis[0];

        rotation.a31 = temp[2] * axis[0] + s * axis[1];
        rotation.a32 = temp[2] * axis[1] - s * axis[0];
        rotation.a33 = c + temp[2] * axis[2];

        compute();
    }

    void rotate(float angle, const Vec3<float> &xyz) {
        const float c = std::cos(angle);
        const float s = std::sin(angle);

        auto n = xyz.getNormal();
        float axis[3] = {n.x, n.y, n.z};
        float temp[3] = {axis[0] * (1.f - c), axis[1] * (1.f - c), axis[2] * (1.f - c)};

        Mat3 Rotate;
        Rotate.a11 = c + temp[0] * axis[0];
        Rotate.a12 = temp[0] * axis[1] + s * axis[2];
        Rotate.a13 = temp[0] * axis[2] - s * axis[1];

        Rotate.a21 = temp[1] * axis[0] - s * axis[2];
        Rotate.a22 = c + temp[1] * axis[1];
        Rotate.a23 = temp[1] * axis[2] + s * axis[0];

        Rotate.a31 = temp[2] * axis[0] + s * axis[1];
        Rotate.a32 = temp[2] * axis[1] - s * axis[0];
        Rotate.a33 = c + temp[2] * axis[2];

        rotation = rotation * Rotate;
        compute();
    }

    void rotate(const Vec4<float> &quaternion) {
        float sqx = quaternion.x * quaternion.x;
        float sqy = quaternion.y * quaternion.y;
        float sqz = quaternion.z * quaternion.z;
        float sqw = quaternion.w * quaternion.w;

        Mat3 Rotate;
        // invs (inverse square length) is only required if quaternion is not already normalised
        float invs = 1 / (sqx + sqy + sqz + sqw);
        Rotate.a11 = (sqx - sqy - sqz + sqw) * invs; // since sqw + sqx + sqy + sqz =1/invs*invs
        Rotate.a22 = (-sqx + sqy - sqz + sqw) * invs;
        Rotate.a33 = (-sqx - sqy + sqz + sqw) * invs;

        float tmp1 = quaternion.x * quaternion.y;
        float tmp2 = quaternion.z * quaternion.w;
        Rotate.a21 = 2.f * (tmp1 + tmp2) * invs;
        Rotate.a12 = 2.f * (tmp1 - tmp2) * invs;

        tmp1 = quaternion.x * quaternion.z;
        tmp2 = quaternion.y * quaternion.w;
        Rotate.a31 = 2.f * (tmp1 - tmp2) * invs;
        Rotate.a13 = 2.f * (tmp1 + tmp2) * invs;
        tmp1 = quaternion.y * quaternion.z;
        tmp2 = quaternion.x * quaternion.w;
        Rotate.a32 = 2.f * (tmp1 + tmp2) * invs;
        Rotate.a23 = 2.f * (tmp1 - tmp2) * invs;

        rotation = rotation * Rotate;
        compute();
    }

    void setRotation(const Vec4<float> &quaternion) {
        float sqx = quaternion.x * quaternion.x;
        float sqy = quaternion.y * quaternion.y;
        float sqz = quaternion.z * quaternion.z;
        float sqw = quaternion.w * quaternion.w;

        // invs (inverse square length) is only required if quaternion is not already normalised
        float invs = 1 / (sqx + sqy + sqz + sqw);

        rotation.a11 = (sqx - sqy - sqz + sqw) * invs; // since sqw + sqx + sqy + sqz =1/invs*invs
        rotation.a22 = (-sqx + sqy - sqz + sqw) * invs;
        rotation.a33 = (-sqx - sqy + sqz + sqw) * invs;

        float tmp1 = quaternion.x * quaternion.y;
        float tmp2 = quaternion.z * quaternion.w;
        rotation.a12 = 2.f * (tmp1 + tmp2) * invs;
        rotation.a21 = 2.f * (tmp1 - tmp2) * invs;

        tmp1 = quaternion.x * quaternion.z;
        tmp2 = quaternion.y * quaternion.w;
        rotation.a13 = 2.f * (tmp1 - tmp2) * invs;
        rotation.a31 = 2.f * (tmp1 + tmp2) * invs;
        tmp1 = quaternion.y * quaternion.z;
        tmp2 = quaternion.x * quaternion.w;
        rotation.a23 = 2.f * (tmp1 + tmp2) * invs;
        rotation.a32 = 2.f * (tmp1 - tmp2) * invs;

        compute();
    }

    void setScale(float xyz) {
        scale = xyz;
        compute();
    }

    void setScale(const Vec2<float> &xyz) {
        scale = xyz;
        compute();
    }

    void setScale(const Vec3<float> &xyz) {
        scale = xyz;
        compute();
    }

    void rescale(float xyz) {
        scale *= xyz;
        compute();
    }

    void rescale(const Vec3<float> &xyz) {
        scale *= xyz;
        compute();
    }

    friend std::ostream &operator<<(std::ostream &out, const ModelTransform &vec) {
        out << "ModelTransform: " << std::endl << (Mat4) vec << std::endl;
        return out;
    }
};

class ViewTransform : public Mat4 {
private:
    void compute() {
        const Vec3<float> f((cameraLookAt - cameraPosition).getNormal());
        const Vec3<float> s(f.cross(cameraUp).getNormal());
        const Vec3<float> u(s.cross(f));

        a11 = s.x;
        a21 = s.y;
        a31 = s.z;
        a12 = u.x;
        a22 = u.y;
        a32 = u.z;
        a13 = -f.x;
        a23 = -f.y;
        a33 = -f.z;
        a41 = -s.dot(cameraPosition);
        a42 = -u.dot(cameraPosition);
        a43 = f.dot(cameraPosition);
    }

public:
    Vec3<float> cameraPosition; /// Camera position in World Space
    Vec3<float> cameraLookAt;   /// and looks at the origin
    Vec3<float> cameraUp;       /// Head is up (set to 0,-1,0 to look upside-down)

    ViewTransform() : cameraPosition(1, 0, 1), cameraLookAt(0, 0, 0), cameraUp(0, 0, 1) { compute(); }

    ViewTransform(const Vec3<float> &cameraPosition, const Vec3<float> &cameraLookAt, const Vec3<float> &cameraUp)
        : cameraPosition(cameraPosition), cameraLookAt(cameraLookAt), cameraUp(cameraUp) {
        compute();
    }

    void setPosition(const Vec3<float> &pos) {
        cameraPosition = pos;
        compute();
    }

    void move(const Vec3<float> &pos) {
        cameraPosition += pos;
        compute();
    }

    void move(const Vec3<float> &pos, float angle) {
        cameraPosition += pos;
        cameraLookAt = cameraPosition + Vec3<>(std::cos(angle), 0, std::sin(angle));
        compute();
    }

    void setLookAt(const Vec3<float> &lookAt) {
        cameraLookAt = lookAt;
        compute();
    }

    friend std::ostream &operator<<(std::ostream &out, const ViewTransform &vec) {
        out << "cameraPosition: " << vec.cameraPosition << std::endl;
        out << "cameraLookAt: " << vec.cameraLookAt << std::endl;
        out << "cameraUp: " << vec.cameraUp << std::endl;

        out << "ViewTransform: " << std::endl;
        out << "ViewTransform: " << std::endl << (Mat4) vec << std::endl;

        return out;
    }
};

class ProjectionTransform : public Mat4 {
private:
    float cameraAngle, ratio;

public:
    ProjectionTransform(float cameraAngle, const Vec2<int> &size, float closeRange, float longRange)
        : Mat4(0), cameraAngle(cameraAngle), ratio(size.x / (float) size.y) {
        setRange(closeRange, longRange);
        setAngle(cameraAngle);
    }

    ProjectionTransform(float cameraAngle, const Vec2<int> &size, float closeRange)
        : Mat4(0), cameraAngle(cameraAngle), ratio(size.x / (float) size.y) {
        setInfinitRange(closeRange);
        setAngle(cameraAngle);
    }

    void setInfinitRange(float closeRange) {
        a43 = closeRange;
        a33 = 0;
        a34 = -1.f;
    }

    void setRange(float closeRange, float longRange) {
        a43 = -(longRange * closeRange) / (closeRange - longRange);
        a33 = -((longRange) / (closeRange - longRange)) - 1;
        a34 = -1.f;
    }

    void setAngle(float _cameraAngle) {
        cameraAngle = _cameraAngle;
        const float tanHalfFovy = std::tan(cameraAngle / 2.f);

        if (ratio > 1.f) {
            a11 = 1.f / (tanHalfFovy);
            a22 = (ratio / tanHalfFovy);
        } else {
            a11 = 1.f / (ratio * tanHalfFovy);
            a22 = 1.f / (tanHalfFovy);
        }
    }

    void setRatio(const Vec2<int> &size) {
        ratio = size.x / (float) size.y;
        const float tanHalfFovy = std::tan(cameraAngle / 2.f);

        if (ratio > 1.f) {
            a11 = 1.f / (tanHalfFovy);
            a22 = (ratio / tanHalfFovy);
        } else {
            a11 = 1.f / (ratio * tanHalfFovy);
            a22 = 1.f / (tanHalfFovy);
        }
    }

    /*    void setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar) {
            // a11 = 1.f;
            a12 = 0.f;
            a13 = 0.f;
            a14 = 0.f;
            a21 = 0.f;
            // a22 = 1.f;
            a23 = 0.f;
            a24 = 0.f;
            a31 = 0.f;
            a32 = 0.f;
            // a33 = 1.f;
            a34 = 0.f;
            // a41 = 0.f;
            // a42 = 0.f;
            // a43 = 0.f;
            a44 = 1.f;

            a11 = 2.f / (right - left);
            a22 = 2.f / (top - bottom);
            a33 = -2.f / (zFar - zNear);
            a41 = -(right + left) / (right - left);
            a42 = -(top + bottom) / (top - bottom);
            a43 = -(zFar + zNear) / (zFar - zNear);
        }*/

    friend std::ostream &operator<<(std::ostream &out, const ProjectionTransform &vec) {
        out << "cameraAngle: " << vec.cameraAngle << std::endl;

        out << "ratio: " << vec.ratio << std::endl;

        //        out << "closeRange: " << vec.closeRange << std::endl;

        //        out << "longRange: " << vec.longRange << std::endl;

        out << "ProjectionTransform: " << std::endl << (Mat4) vec << std::endl;

        return out;
    }
};

}; // namespace Blob::Maths