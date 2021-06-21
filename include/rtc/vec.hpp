#ifndef RTC_VEC_H
#define RTC_VEC_H
#include <ostream>

namespace rtc{
  struct vec{
    double m_x;
    double m_y;
    double m_z;
    double m_w=1.0;

    vec(const double x, const double y, const double z): m_x(x), m_y(y), m_z(z){};
    vec(const double x, const double y, const double z, const double w): m_x{x}, m_y{y}, m_z{z}, m_w{w} {};

    [[nodiscard]] inline bool is_point() const { return this->m_w > 0.0;}

    bool operator==(const vec& other) const;
    bool operator!=(const vec& other) const;
    vec operator+(const vec& other) const;
    vec operator-(const vec& other) const;
    vec operator-() const;
    vec operator*(const double factor) const;
    vec operator/(const double factor) const;

    void normalise();
    double magnitude() const;
  };

  inline vec point(double x, double y, double z){
      return vec{x, y, z};
  }
  inline vec vector(double x, double y, double z){
      return vec{x, y, z, 0.0};
  }

  std::ostream& operator<<(std::ostream& stream, const vec& vec);
}
#endif
