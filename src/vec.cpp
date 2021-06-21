#include "rtc/vec.hpp"
#include <cmath>
#include <algorithm>

namespace {
constexpr auto EPSILON = 1e-9;
}

bool rtc::vec::operator==(const rtc::vec& other) const
{
  return std::abs(this->m_x - other.m_x) < EPSILON && 
         std::abs(this->m_y - other.m_y) < EPSILON &&
         std::abs(this->m_z - other.m_z) < EPSILON &&
         std::abs(this->m_w - other.m_w) < EPSILON;
}
    
bool rtc::vec::operator!=(const rtc::vec& other) const 
{
  return !(*this == other);
}
    
rtc::vec rtc::vec::operator+(const rtc::vec& other) const 
{
  return vec{this->m_x + other.m_x, this->m_y + other.m_y, this->m_z + other.m_z, this->m_w + other.m_w};
}

rtc::vec rtc::vec::operator-(const rtc::vec& other) const 
{
  return vec{this->m_x - other.m_x, this->m_y - other.m_y, this->m_z - other.m_z, this->m_w - other.m_w};
}

rtc::vec rtc::vec::operator-() const 
{
  return vec{-this->m_x, -this->m_y, -this->m_z, -this->m_w};
}

rtc::vec rtc::vec::operator*(const double factor) const 
{
  return vec{factor * this->m_x, factor * this->m_y, factor * this->m_z, factor * this->m_w};
}

rtc::vec rtc::vec::operator/(const double factor) const 
{
  return vec{this->m_x / factor, this->m_y / factor, this->m_z / factor, this->m_w / factor};
}

std::ostream& rtc::operator<<(std::ostream& os, const rtc::vec& vec)
{
  os << vec.m_x << ' ' << vec.m_y << ' ' << vec.m_z << ' ' << vec.m_w;
  return os;
}

void rtc::vec::normalise()
{
  double factor=magnitude();
  m_x/=factor;
  m_y/=factor;
  m_z/=factor;
  m_w/=factor;
}

double rtc::vec::magnitude() const
{
  return std::hypot(m_x, m_y, m_z);
}
