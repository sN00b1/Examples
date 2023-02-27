var integers = Console.ReadLine()
                .Split(new[] {" "}, StringSplitOptions.RemoveEmptyEntries)
                .Select(Int32.Parse);
int min = int.MaxValue;
int max = int.MinValue;
foreach(var n in integers)
{
    if(min > n)
        min = n;
    if(max < n)
        max = n;
}
Console.WriteLine(max-min);