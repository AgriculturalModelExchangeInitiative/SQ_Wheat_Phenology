#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
#include "Fibonacci.h"

using namespace std;
Fibonacci Calculate_Fibonacci(int n){
int result;
int b=1;
result =0;
for(int i=0;i<n;i++)
{
    int temp = result;
    result=b;
    b=temp+b;
}

return Fibonacci{result};



}

