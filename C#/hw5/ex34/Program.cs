var integers = Console.ReadLine()
                .Split(new[] {" "}, StringSplitOptions.RemoveEmptyEntries)
                .Select(Int32.Parse);
int ans = 0;
foreach(var n in integers)
    if(n % 2 == 0)
        ans++;
Console.WriteLine(ans);