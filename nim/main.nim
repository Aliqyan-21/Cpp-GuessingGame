import os
import random as rnd
import strutils

rnd.randomize()

# proc name(param): return =
proc usage() =
  if os.paramCount() < 1:
    echo "Usage: main <mode[easy/medium/hard]>"
    quit(1)

proc getRand(a, b: uint16): uint16 = 
  return rnd.rand(a .. b)

proc game(min, max: uint16) =
  var randNum: uint16 = getRand(min, max)
  var userGuess: uint16
  var count: uint64 = 0
  var choice: string
  var mode: string

  stdout.write("Guess the number I am thinking of between " & $min & " and " & $max & "...\n")
  stdout.write("Your Guess: ")
  userGuess = (uint16)(parseUint(readLine(stdin)))

  while true:
    if userGuess > randNum:
      count+=1
      stdout.write("I am thinking of a smaller number than that...\n")
      stdout.write("Try again\n")
      stdout.write("Your Guess: ")
      userGuess = (uint16)(parseUint(readLine(stdin)))
    elif userGuess < randNum:
      count+=1
      stdout.write("I am thinking of a greater number than that...\n")
      stdout.write("Try again\n")
      stdout.write("Your Guess: ")
      userGuess = (uint16)(parseUint(readLine(stdin)))
    else:
      stdout.write("Yes, you guessed it right " & $userGuess & " is the number I was thinking of!\n")
      stdout.write("Total number of tries you took: " & $count & "\n")
      stdout.write("Play again? [y/n]: ")
      choice = readLine(stdin)
      if choice.toLower == "y":
        stdout.write("Difficulty mode [easy/medium/hard]: ")
        mode = readLine(stdin)
        case mode.toLower()
          of "easy":
            game(0, 100)
          of "medium":
            game(0, 200)
          of "hard":
            game(0, 300)
          else:
            echo "Invalid mode"
            quit(1)
      else:
        quit(0)

while isMainModule:
  usage()
  var mode:string = os.paramStr(1)
  
  case mode.toLower()
    of "easy":
      game(0, 100)
    of "medium":
      game(0, 200)
    of "hard":
      game(0, 300)
    else:
      echo "Invalid mode"
      quit(1)
