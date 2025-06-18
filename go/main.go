package main

import (
	"fmt"
	"math/rand"
	"os"
	"strings"
)

func game(min int, max int) {
	var randNum int = rand.Intn(max-min) + min
	var userGuess int
	var count int

	fmt.Printf("Guess the number I am thinking of between %d and %d...\n", min, max)
	fmt.Printf("Your Guess: ")
	fmt.Scan(&userGuess)

	for true {
		if userGuess > randNum {
			count++
			fmt.Printf("I am thinking of a smaller number than that...\n")
			fmt.Printf("Try again:\n")
			fmt.Printf("Your Guess: ")
			fmt.Scan(&userGuess)
		} else if userGuess < randNum {
			count++
			fmt.Printf("I am thinking of a greater number than that...\n")
			fmt.Printf("Try again:\n")
			fmt.Printf("Your Guess: ")
			fmt.Scan(&userGuess)
		} else {
			fmt.Printf("Yes, you guessed it right %d is the number I was thinking of!\n", userGuess)
			fmt.Printf("Total number of tries you took: %d\n", count)
			fmt.Printf("Play again? [y/n]: ")
			var choice string
			fmt.Scan(&choice)
			if strings.ToLower(choice) == "y" {
				var mode string
				fmt.Printf("Difficulty mode [easy/medium/hard]: ")
				fmt.Scan(&mode)
				switch mode {
				case "easy":
					game(1, 100)
					break
				case "medium":
					game(1, 200)
					break
				case "hard":
					game(1, 300)
					break
				default:
					fmt.Printf("The mode %s is not supported\n", mode)
					os.Exit(1)
				}
			} else {
				os.Exit(0)
			}
		}
	}
}

func usage() {
	if len(os.Args) == 1 {
		fmt.Printf("Usage: %s <mode[easy, medium, hard]>\n", os.Args[0])
		os.Exit(1)
	}
}

func main() {
	usage()

	var mode string = os.Args[1]

	switch mode {
	case "easy":
		game(1, 100)
		break
	case "medium":
		game(1, 200)
		break
	case "hard":
		game(1, 300)
		break
	default:
		fmt.Printf("The mode %s is not supported\n", mode)
		os.Exit(1)
	}
}
