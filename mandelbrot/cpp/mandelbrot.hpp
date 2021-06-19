template <typename T>
int isBounded(const T x, const T y) {
    const T cRe = x;
    const T cIm = y;
    T zRe = 0.;
    T zIm = 0.;

    const T threshold = 4;
    const int maxIterations = 50;

    for (int i = 0; i < maxIterations; ++i) {
        T zReTemp = zRe * zRe - zIm * zIm + cRe;
        zIm = 2 * zRe * zIm + cIm;
        zRe = zReTemp;
        if (zRe * zRe + zIm * zIm > threshold) {
            return i;
        }
    }
    return maxIterations;
}

template<typename T>
T map(const T x, const T x1, const T x2, const T y1, const T y2) {
    return (x - x1) * (y2 - y1) / (x2 - x1) + y1;
}

template<typename A, typename B>
void zoom(A& x0, A& x1, const B f) {
    x0 = x0 + (x1 - x0) / 2 - f * (x1 - x0) / 2;
    x1 = x0 + (x1 - x0) / 2 + f * (x1 - x0) / 2;
}