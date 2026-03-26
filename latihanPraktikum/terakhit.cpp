#include <bits/stdc++.h>

using namespace std;

class pemain
{
protected:
    string nama;
    int koin, exp, tt, baseExp, baseCoin;

public:
    pemain(string a, int b)
    {
        nama = a;
        tt = b;
        exp = 0;
        koin = 0;
    }
    virtual void hunt();
    virtual void info();
};

class pemainSolo : public pemain
{

public:
    pemainSolo(string a, int b): pemain(a,b);
    void hunt()
    {
        koin += baseCoin;
        exp = baseExp * (1 + tt);
    }
};

class pemainParty:public pemain{
public:
    pemainParty(string a  , int b):pemain(a,b);
    void hunt(){
        koin+=baseCoin;
        exp = baseExp * (1+tt);

    }
}

int
main()
{

    return 0;
}