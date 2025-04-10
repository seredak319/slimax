#ifndef INTERPOLATOR_H
#define INTERPOLATOR_H

/**
 * @class Interpolator
 * @brief Szablon do liniowej interpolacji między dwiema wartościami.
 *
 * Umożliwia obliczenie wartości pośredniej między a i b w zależności od współczynnika t.
 * Wartość t powinna być w zakresie [0,1].
 *
 * @tparam T Typ wartości, dla której możliwa jest interpolacja (musi obsługiwać operatory -, + oraz mnożenie przez double).
 *
 * @example
 * Poniższy przykład pokazuje, jak interpolować wartości typu double:
 * @code
 * double start = 10.0;
 * double end = 20.0;
 * double mid = Interpolator<double>::lerp(start, end, 0.5);
 * // mid wynosi 15.0
 * @endcode
 */
template <typename T>
class Interpolator {
public:
    /**
     * @brief Oblicza liniową interpolację.
     *
     * Oblicza wartość pośrednią między a i b przy użyciu współczynnika t.
     *
     * @param a Wartość początkowa.
     * @param b Wartość końcowa.
     * @param t Współczynnik interpolacji (0.0 - 1.0).
     * @return Wartość pośrednia między a i b.
     */
    static T lerp(const T& a, const T& b, double t) {
        return a + (b - a) * t;
    }
};

#endif
