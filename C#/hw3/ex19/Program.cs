int a = Convert.ToInt32(Console.ReadLine());
if(a / 10000 == a % 10 && a / 1000 % 10 == a / 10 % 10)
    Console.WriteLine("Да");
else
    Console.WriteLine("Нет");