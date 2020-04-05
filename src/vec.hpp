#include <cmath>

namespace rtc{
    constexpr auto EPSILON = 1e-9;
    struct vec{
        float m_x;
        float m_y;
        float m_z;
        float m_w=1.0;

        vec(float x, float y, float z): m_x(x), m_y(y), m_z(z){};
        vec(float x, float y, float z, float w): m_x{x}, m_y{y}, m_z{z}, m_w{w} {};

        [[nodiscard]] inline bool is_point() const { return this->m_w > 0.0;};

        bool operator==(const vec& other) const {
           return std::abs(this->m_x - other.m_x) < EPSILON && std::abs(this->m_y - other.m_y) < EPSILON && std::abs(this->m_z - other.m_z) < EPSILON && std::abs(this->m_w - other.m_w) < EPSILON;};

        bool operator!=(const vec& other) const {
            return !(*this == other);
        };

        friend std::ostream& operator<<(std::ostream& stream, const vec& vec);
    };

    std::ostream& operator<<(std::ostream& os, const vec& vec){
        os << vec.m_x << ' ' << vec.m_y << ' ' << vec.m_z << ' ' << vec.m_w;
        return os;
    };


    vec point(float x, float y, float z){
        return vec{x, y, z};
    };

    vec vector(float x, float y, float z){
        return vec{x, y, z, 0.0};
    };
}
