#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
#define LL long long int
#define FOR(a,b,c)   for (int (a)=(b); (a)<(c); (a)++)
#define FORN(a,b,c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c)  for (int (a)=(b); (a)>=(c); (a)--)
#define REP(i,n)     FOR(i,0,n)
#define REPN(i,n)    FORN(i,1,n)
#define REPD(i,n)    FORD(i,n,1)
#include"StudentClass.cpp"

void print(int *a,int size)
{
    FOR(i,0,size) cout<<a[i]<< " ";cout<<endl;
}

int main() {
    Student s;
    s.setage(10);
    s.setroll(100);
    s.display();
    cout<<s.totalStudents;


    return 0;
}
