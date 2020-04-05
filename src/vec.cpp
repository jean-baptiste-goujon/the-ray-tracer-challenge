#include "vec.hpp"

namespace rtc{
    bool vec::operator==(const vec& other) const{
        return std::abs(this->m_x - other.m_x) < EPSILON && std::abs(this->m_y - other.m_y) < EPSILON && std::abs(this->m_z - other.m_z) < EPSILON && std::abs(this->m_w - other.m_w) < EPSILON;
    }
    
    bool vec::operator!=(const vec& other) const {
        return !(*this == other);
    }
    
    std::ostream& operator<<(std::ostream& os, const vec& vec){
        os << vec.m_x << ' ' << vec.m_y << ' ' << vec.m_z << ' ' << vec.m_w;
        return os;
    }
}
