using System;  
public class Fibonacci  
{      public static int fibonacci(int N)  
    {  
        int a=0,b=1;    
        for(int i=0;i<N;i++)  
        {    
            temp = a;   
            a=b;    
            b=temp+b;    
        }
        return a;    
    }  
}  