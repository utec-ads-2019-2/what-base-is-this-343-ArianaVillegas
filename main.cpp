#include <iostream>
#include <cmath>

using namespace std;

unsigned long long convertBase(string num,int base){
    unsigned long long newNum=0;
    int size=num.size();
    for(int i=0;i<size;++i){
        int actual=num[size-i-1];
        if(actual>='0' && actual<='9'){
            newNum+=(int(actual)-48)*pow(base,i);
        }else{
            newNum+=(int(actual)-55)*pow(base,i);
        }
    }
    return newNum;
}

int minBase(string num){
    int base=2;
    int size=num.size();
    for(int i=0;i<size;++i){
        int actual=num[size-i-1];
        if(actual>='0' && actual<='9'){
            if(base<=(int(actual)-48)) base=int(actual)-47;
        }else{
            if(base<=(int(actual)-55)) base=int(actual)-54;
        }
    }
    return base;
}

int main() {
    string a, b;
    int minA,minB;
    unsigned long long valueA,valueB;
    while(cin >> a >> b) {
        minA = minBase(a);
        minB = minBase(b);
        do {
            valueA = convertBase(a, minA);
            valueB = convertBase(b, minB);
            if (valueA > valueB) {
                ++minB;
            } else if (valueA < valueB) {
                ++minA;
            }
        } while (valueA != valueB && minA<37 && minB<37);
        if(minA>36 || minB>36) cout << a << " is not equal to " << b << " in any base 2..36\n";
        else cout << a << " (base " << minA << ") = " << b << " (base " << minB << ")\n";
    }
    return 0;
}