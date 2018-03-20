#include<iostream>
using namespace std;

#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
#include"Fraction_class.cpp"
int main()
{
  /*  Fraction const f(20,7);
    cout<<f.getNumerator()<<endl;
    cout<<f.getDenominator()<<endl;

    Fraction f1(1,2);
    Fraction const f2(1,2);
    f1.multiply(f2);
    f1.print();
    Fraction f3=f1*f2;
    f3.print();
    f3=f1+f2;
    f3.print();
    ++f3;
    f3.print();
    Fraction f4=++f3;///copy constructor called man
    */
   /* Fraction f(1,5);
    Fraction f2(1,2);
    Fraction f3=++(++f);
    f.print();f3.print();
    ++f;++f;
    f3.print();
    f.print();
*/
    Fraction f(10,2);

    Fraction f3(1,1);
    f3=(f++)++;
    f.print();
    f3.print();
    int a,b;
    a=5;
    b=(a++)++;
    cout<<a<<" "<<b<<endl;
    return 0;


}
