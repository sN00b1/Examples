int a;
a = Convert.ToInt32(Console.ReadLine());
if(a < 100)
{
    Console.WriteLine("третьей цифры нет");
}
else
{
    Console.WriteLine(a / 100 % 10);
}