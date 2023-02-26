var integers = Console.ReadLine()
                .Split(new[] {" "}, StringSplitOptions.RemoveEmptyEntries)
                .Select(Int32.Parse);
foreach(var n in integers)
    Console.WriteLine(n);