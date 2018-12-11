#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include "Fibonacci.h"

using namespace std;
Fibonacci calculate_Fibonacci(int n){
int value;
int b=1;
value =0;
for(int i=0;i<n;i++)
{
    int temp = value;
    value=b;
    b=temp+b;
}

return Fibonacci{value};



}

