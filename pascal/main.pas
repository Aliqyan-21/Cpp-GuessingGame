program Main;

{ returns random number between a and b }
function getRand(a, b: word): word;
begin
  getRand := random(b - a + 1) + a;
end;

{ usage infor. }
procedure usage();
begin
  if ParamCount < 1 then
  begin
    writeln('Usage: ./main <mode[easy, medium, hard]>');
    halt(1);
  end;
end;

{ main game loop }
procedure game(min, max: word);
var
  randNum: word;
  userGuess: word;
  count: word;
  choice: char;
  mode: string;
begin
  randNum := getRand(min, max);
  count := 1;
  writeln('Guess the number I am thinking of between ',  min, ' and ', max, '...');
  writeln('Your Guess: ');
  readln(userGuess);

  while true do
  begin
    if userGuess > randNum then
    begin
      count := count + 1;
      writeln('I am thinking of a smaller number than that...');
      writeln('Try again:');
      writeln('Your Guess: ');
      readln(userGuess)
    end
    else if userGuess < randNum then
    begin
      count := count + 1;
      writeln('I am thinking of a greater number than that...');
      writeln('Try again:');
      writeln('Your Guess: ');
      readln(userGuess)
    end
    else
    begin
      writeln('Yes, you guessed it right ', userGuess, ' is the number I was thinking of!');
      writeln('Total number of tries you took: ', count);
      writeln('Play again? [y/n]: ');
      readln(choice);
      if LowerCase(choice) = 'y' then
      begin
        writeln('Choose difficulty[easy, medium, hard]: ');
        readln(mode);
        if mode = 'easy' then
          game(0, 100)
        else if mode = 'medium' then
          game(100, 200)
        else if mode = 'hard' then
          game(200, 300)
        else
        begin
          writeln('Invalid mode: ', mode);
          halt(1);
        end;
      end
      else
        halt(0);
    end;
  end;
end;

{ entry point }
var
  mode: string;
begin
  usage();

  randomize;

  mode := ParamStr(1);
  if mode = 'easy' then
    game(0, 100)
  else if mode = 'medium' then
    game(100, 200)
  else if mode = 'hard' then
    game(200, 300)
  else
    writeln('Invalid mode: ', mode);
end.
