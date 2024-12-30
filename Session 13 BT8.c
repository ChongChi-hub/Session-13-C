#include <stdio.h>

//ucln(a, b) = ucln(b, a - b)
//vd: ucln(20, 30) = ucln(20, 10); ucln(20, 10) = ucln(10, 10) --> ucln(20, 30) = 10
int ucln(int a, int b){
    if(a == 0 || b == 0){
        return a + b;
    }
    while(a != b){
        if(a > b){
            a = a - b;
        } else{
            b = b - a;
        }
    }
    return a;
}

int main(){
    int a = 20, b = 30;
    int kq = ucln(a, b);
    printf("Uoc chung lon nhat cua (%d,%d) la: %d\n", a, b, kq);
    
    return 0;
}
