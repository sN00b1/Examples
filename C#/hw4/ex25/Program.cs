int a = Convert.ToInt32(Console.ReadLine());
int b = Convert.ToInt32(Console.ReadLine());
int ans = 1;
for(int i = 0 ; i < b ; i++)
    ans = ans * a;
Console.WriteLine(ans);