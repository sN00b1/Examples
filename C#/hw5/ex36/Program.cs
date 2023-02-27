var integers = Console.ReadLine()
                .Split(new[] {" "}, StringSplitOptions.RemoveEmptyEntries)
                .Select(Int32.Parse);
int ans = 0;
int i = 1;
foreach(var n in integers)
{
    if(i % 2 == 0)
        ans += n;
    i++;
}
Console.WriteLine(ans);