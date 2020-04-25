#ifndef RTC_VEC_H
#define RTC_VEC_H
#include <cmath>
#include <ostream>

namespace rtc{
    constexpr auto EPSILON = 1e-9f;

    struct vec{
        float m_x;
        float m_y;
        float m_z;
        float m_w=1.0;

        vec(const float x, const float y, const float z): m_x(x), m_y(y), m_z(z){};
        vec(const float x, const float y, const float z, const float w): m_x{x}, m_y{y}, m_z{z}, m_w{w} {};

        [[nodiscard]] inline bool is_point() const { return this->m_w > 0.0f;}

        bool operator==(const vec& other) const;
        bool operator!=(const vec& other) const;
        vec operator+(const vec& other) const;
        vec operator-(const vec& other) const;
        vec operator-() const;

    };

    inline vec point(float x, float y, float z){
        return vec{x, y, z};
    }
    inline vec vector(float x, float y, float z){
        return vec{x, y, z, 0.0};
    }

    std::ostream& operator<<(std::ostream& stream, const vec& vec);
}
#endif
