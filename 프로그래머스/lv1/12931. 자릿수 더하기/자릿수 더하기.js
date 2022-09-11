function solution(n)
{
    return n.toString().split('').map(x => Number(x)).reduce((a, b) => a + b, 0);
}