program Multiples;

var
i, result, isMOD: integer;
prevDone: boolean;

begin
    result := 0;
    i := 1;
    for i := 1 to 999 do
    begin
        isMOD := i mod 3;
        if isMOD = 0 then
            result := result + i;
            prevDone := false;
        isMOD := i mod 5;
        if prevDone = true then
            if isMOD = 0 then
                result := result + i;
    end;
    writeln(result);
end.