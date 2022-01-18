template <typename T, typename V>

class Pair {

    T X;
    V Y;
    
    public:

    T getX() {
        return X;
    }

    V getY() {
        return Y;
    }

    void setX(T x) {
        X = x;
    }

    void setY(V y) {
        Y = y;
    }
};
