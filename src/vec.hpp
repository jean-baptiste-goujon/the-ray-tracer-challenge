namespace rtc{
    struct vec{
        float m_x;
        float m_y;
        float m_z;
        float m_w=1.0;

        vec(float x, float y, float z): m_x(x), m_y(y), m_z(z){};
        vec(float x, float y, float z, float w): m_x{x}, m_y{y}, m_z{z}, m_w{w} {};

        [[nodiscard]] inline bool is_point() const { return this->m_w > 0.0;};
    };


    vec point(float x, float y, float z){
        return vec{x, y, z};
    };

    vec vector(float x, float y, float z){
        return vec{x, y, z, 0.0};
    };
}
