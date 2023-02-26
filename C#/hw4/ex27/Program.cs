int a = Convert.ToInt32(Console.ReadLine());
int ans = 0;
while(a > 0)
{
    int b = a % 10;
    ans += b;
    a = a / 10;
}
Console.WriteLine(ans);