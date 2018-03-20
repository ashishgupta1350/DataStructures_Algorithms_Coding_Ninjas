///template
template<typename T,typename V>

class Pair{
    T x;
    V y;
public:
    T getX()const{
        return x;
    }
    V getY()const
    {
        return y;
    }
    void setX(T x)
    {
        this->x=x;

    }
    void setY(V y)
    {
        this->y=y;

    }
};
