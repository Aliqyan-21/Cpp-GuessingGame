program Main;

{ returns random number between a and b }
function getRand(a, b: smallInt): smallInt;
begin
  randomize;
  getRand := random(b - a + 1) + a;
end;

{ usage infor. }
procedure usage();
begin
  if ParamCount < 1 then
  begin
    writeln('Usage: ./main <mode[easy, medium, hard]>');
    halt(1);
  end
end;

{ main game loop }
procedure game();
var randNum: smallInt;
begin
  // todo: implement game function
end;

{ entry point }
var
  mode: string;
begin
  usage();
  mode := ParamStr(1);
end.
