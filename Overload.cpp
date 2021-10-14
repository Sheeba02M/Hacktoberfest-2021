#include <iostream>

using namespace std;

class Fraction {
        int num;
        int denom;
    public:
        Fraction() {        
        }
        Fraction(int num, int denom) {
            this -> num = num;
            this -> denom = denom;
        }
        void simplify() {
            int gcd = 1;
            int j = min(num, denom);
            for(int i = 1 ; i <= j ; i++)
                if(num % i == 0 && denom % i == 0)
                    gcd = i;
            num /= gcd;
            denom /= gcd;
        }
        friend Fraction operator+(Fraction const &, Fraction const &);
        Fraction operator-(Fraction const &f) {
            int lcm = denom * f.denom;
            int x = lcm / denom;
            int y = lcm / f.denom;
            int n = x * num - (y * f.num);
            Fraction fNew(n, lcm);
            fNew.simplify();
            return fNew;
        }
        Fraction operator*(Fraction const &f) {  
            int lcm = denom * f.denom;
            int n = num * f.num;
            Fraction fNew(n, lcm);
            fNew.simplify();
            return fNew;
        }
        Fraction operator/(Fraction const &f) {
            int lcm = denom * f.num;
            int n = num * f.denom;
            Fraction fNew(n, lcm);
            fNew.simplify();
            return fNew;
        }
        friend ostream &operator<<(ostream &out, Fraction const &f);
        friend istream &operator>>(istream &in, Fraction &f);
};

Fraction operator+(Fraction const &f1, Fraction const &f2) {
    int lcm = f1.denom * f2.denom;
    int x = lcm / f1.denom;
    int y = lcm / f2.denom;
    int n = x * f1.num + (y * f2.num);
    Fraction fNew(n, lcm);
    fNew.simplify();
    return fNew;
}

ostream &operator<<(ostream &out, Fraction const &f) {
    out<<f.num<<" / "<<f.denom<<endl;
    return out;
}

istream &operator>>(istream &in, Fraction &f) {
    in>>f.num>>f.denom;
    return in;
}

int main() {
    Fraction f1, f2;
    cout<<"Enter the numerator and the denominator of the first fraction(F1): ";
    cin>>f1;
    cout<<"Enter the numerator and the denominator of the second fraction(F2): ";
    cin>>f2;
    Fraction f3 = f1 + f2;
    cout<<"F1 + F2 = ";
    cout<<f3;
    f3 = f1 - f2;
    cout<<"F1 - F2 = ";
    cout<<f3;
    f3 = f1 * f2;
    cout<<"F1 * F2 = ";
    cout<<f3;
    f3 = f1 / f2;
    cout<<"F1 / F2 = ";
    cout<<f3;
    return 0;
}
