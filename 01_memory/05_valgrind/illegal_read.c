int* func()
{
    int a  = 10;
    return &a;
}

int main()
{
    int* x = func();
    volatile int y = *x;
    return 0;
}