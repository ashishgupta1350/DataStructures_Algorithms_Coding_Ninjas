class Fraction{

  private:
      int numerator;
      int denominator;
  public:
    //constructor
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }
    Fraction(){};

    int getNumerator()const
    {
        return numerator;
    }
    int getDenominator() const
    {
        return denominator;
    }
    void setNumerator(int n){
    this->numerator=n;

    }
    void setDenominator(int n)
    {
        this->denominator=n;


    }
    void print()/// 1/2 and 3/4
    {
        cout<<this->numerator<<" / "<<this->denominator<<endl;
    }
    void simplify()
    {
        int x=numerator;int y=denominator;
        int j=min(x,y),gcd=0;
        FORN(i,1,j){
            if(x%i==0&&y%i==0)
            {
                gcd=i;
            }

        }
       this-> numerator/=gcd;
       this-> denominator/=gcd;


    }

    Fraction operator*(Fraction const&f2) const
    {
        Fraction f(1,1);
        f.numerator=f2.numerator*this->numerator;
        f.denominator=f2.denominator*this->denominator;
        f.simplify();
        return f;
    }

    void multiply(Fraction const& f2)
    {
        numerator=f2.numerator*this->numerator;

        denominator=f2.denominator*this->denominator;

        simplify();
    }
    Fraction operator+(Fraction const&f2)const {
        Fraction f(1,1);
        f.numerator=(this->numerator*f2.denominator)+(this->denominator*f2.numerator);
        f.denominator=this->denominator*f2.denominator;
        f.simplify();
        return f;

    }
    void add( const Fraction &f2){
///      f2.setNumerator(10);
        numerator=(this->numerator*f2.denominator)+(this->denominator*f2.numerator);
        denominator=this->denominator*f2.denominator;

        simplify();
    }
   /* void operator++(){
        numerator+=denominator;

    }*/
   Fraction operator++(){
        this->numerator=this->numerator+this->denominator;
        return *this;

   }
   Fraction& operator++(int){
    Fraction fNew(numerator,denominator);
    numerator+=denominator;
    fNew.simplify();
    simplify();
    return fNew;

   }

};
