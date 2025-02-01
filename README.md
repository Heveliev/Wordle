# Wordle - Word guessing game

---

## ./Wordle - we have:
	- README.md - main documentation.
	- code_style.md - features of writing code for this project.
	- todo.md - what needs to be implemented, what is planned for the future.
	- ./Wordle - main folder with code:
		- ./validation - user input validation, main project validation functions.
		- ./game_logic - game logic.
		- ./file_operations - working with files, reading, writing, etc.
		- ./time - working with time.
		- ./data - project data, word base, user settings, etc.
		- ./Wordle.cpp - main project file (main.cpp).
## Each function is described in its own file.

---

`The application is not implemented according to the initial idea, such as there were difficulties 
with reading the file, it was assumed that we can extract any line from the file, but this is not 
the case, we need to read the entire file each time. As a result, it was decided to make the file 
read once at the first launch of the application. and recording the necessary words (a list of n words 
for the random mode and a daily word). This will allow the application to work faster in subsequent launches, 
and if the user empties the array that was added in the first launch, only then the file is read again. 
To avoid repeated launches when emptying, user statistics were created. If the user guesses more than 10 words
per day, this is recorded and the average number is calculated, which allows more words to be read at once in 
the following days using the multiplier method, that is: 10 * the average number of function launches on the previous
day. This approach allows us to adapt to each user individually, ensuring speed: if a person guesses few words per day, 
then the first launch will work faster due to the fact that fewer words are needed, while if a person guesses many words, 
then his first launch will be a little slower, but during the game the function of reading the file of recording 
new words will not be called, and so on, which will allow you to immerse yourself in the game as much as possible 
without delays and lags.`

`Possible vulnerabilities and bugs:
the user can infiltrate files and change data, which will allow him to obtain words, other data,
in the future to increase his points illegally, and also lead to unexpected results and bugs.`

---

### Pros:
* Words with repeating letters are possible and their correct processing (input/output).
* Due to the implemented functions, it is easy to scale the application by introducing a level of word complexity.
* Most functions are independent of others and have their own checks (in the future, GameState::Bug can be used as a 
return type that will close the game if something goes wrong), which allows for better operation of individual components,
scaling where no one depends on each other, while the functions work more directly with data (links), without creating 
local copies, which in turn optimizes the use of RAM.

### Cons:
* Some algorithms are not very fast.
* Some elements of the implementation are not very intuitive.
* There is code repetition (possible corrections in the future).
* Checks are not present everywhere, which can lead to unexpected results.
* Checks implemented in functions for their independence are stubs, simply returning (nothing, standard value), 
which can lead to unexpected results or incorrect operation of the application.