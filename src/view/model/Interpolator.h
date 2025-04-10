#ifndef INTERPOLATOR_H
#define INTERPOLATOR_H

// Szablon
template <typename T>
class Interpolator {
public:
    static T lerp(const T& a, const T& b, double t) {
        return a + (b - a) * t;
    }
};

#endif
