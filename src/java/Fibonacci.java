package pheno2;
public class fibonacci
{
    public int value;
    public fibonacci(int _value)
    {
        this.value=_value;
    }
}

class Estimation_fibonacci
{
    public static fibonacci Calculatefibonacci(int n)
    {


/*
     fibonacci function

    Author: 
    Reference:  to write in package
    Instituton: INRA Montpellier
    Abstract: see documentation
    
*/
        int value;

        int b=1; 
        value=0;  
        for(int i=0;i<n;i++)  
        {    
            int temp = value;   
            value=b;    
            b=temp+b;    
        }
        return new fibonacci(value);
    }

}
