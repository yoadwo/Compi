integer foo()
{
    integer a;
    a = 23;
    if (a == 23)
        a = 10;
    else
        a = 19;
    return a;
}

integer fee(integer a, integer b)
{
    integer sum1, sum2;
    sum1 = 0;
    sum2 = 0;
    while (a < b)
    {
        if (a / 2 == 0 || a*b < 100 && sum1 == sum2)
            sum1 = sum1 + a;
        else
            sum2 = sum2 + 1;
        a = a + 1;
    }
    return sum1 + sum2;
}


void Main()
{
    integer a;
    integer b;
    a = 0;
    while(a < 10)
    {
        b = foo();
        a = a + b;
        a = a + fee(a, b);
    }
}