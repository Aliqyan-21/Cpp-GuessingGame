program Main;

procedure game();
begin
  // todo: implement game function
end

procedure usage();
begin
  writeln('Usage: ./main <mode[easy, medium, hard]>');
  halt(1);
end;

var
  mode: string;

begin
  if ParamCount < 1 then
    usage();

  mode := ParamStr(1);
  game(mode);
end.
