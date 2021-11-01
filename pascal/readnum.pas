program readnum;
var
  day: integer;

begin
  repeat
    write('Please enter a number (between 0 and 7) corresponding to the day of the week: ');
    readln(day);
  until (day>=1) and (day<=7);
  writeln('value of day: ', day);
end.
