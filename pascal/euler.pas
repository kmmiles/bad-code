program Multiples;

var
i: integer;
sum: longint;

begin
    sum := 0;
    for i := 1 to 999 do
        if ( (i mod 5 = 0) or (i mod 3 = 0)) then
            sum := sum + i;
            //writeln(i);
    writeln(sum);
end.
