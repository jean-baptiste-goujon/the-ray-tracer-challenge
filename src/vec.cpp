#include "rtc/vec.hpp"
#include <algorithm>

bool rtc::vec::operator==(const rtc::vec& other) const{
    return std::abs(this->m_x - other.m_x) < EPSILON && std::abs(this->m_y - other.m_y) < EPSILON && std::abs(this->m_z - other.m_z) < EPSILON && std::abs(this->m_w - other.m_w) < EPSILON;
}
    
bool rtc::vec::operator!=(const rtc::vec& other) const {
    return !(*this == other);
}
    
rtc::vec rtc::vec::operator+(const rtc::vec& other) const {
    return vec{this->m_x + other.m_x, this->m_y + other.m_y, this->m_z + other.m_z, this->m_w + other.m_w};
}

rtc::vec rtc::vec::operator-(const rtc::vec& other) const {
    return vec{this->m_x - other.m_x, this->m_y - other.m_y, this->m_z - other.m_z, this->m_w - other.m_w};
}

rtc::vec rtc::vec::operator-() const {
    return vec{-this->m_x, -this->m_y, -this->m_z, -this->m_w};
}

std::ostream& rtc::operator<<(std::ostream& os, const rtc::vec& vec){
    os << vec.m_x << ' ' << vec.m_y << ' ' << vec.m_z << ' ' << vec.m_w;
    return os;
}

rtc::vec rtc::point(float x, float y, float z){
    return vec{x, y, z};
}

rtc::vec rtc::vector(float x, float y, float z){
    return rtc::vec{x, y, z, 0.0};
}
