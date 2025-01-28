1. Game Selection:
	a)random Wordle; 	
	b)Wordle of the day;
		Checking whether the word of the day was guessed before choosing 
		the game, or after choosing the word of the day.
		Availability of the function after 24 hours (not good) 
		or reset the word every (00:00 UTC or 00:00 local time)

2. PC choice randon word || daily word
	Select any word (pseudo random) || At the first launch, you need to select 
	a random word from the list,add it to the document, indicate that it can 
	no longer be taken, whenthe words run out, start over (use a binary algorithm for speed):
		- the user, having a common list of words, can take advantage 
		of the vulnerability of calculating the word for the following days,
		and also in theory the words will be after the end of the list will 
		go in the same order as in the first iteration.
 
3. Input and validation input:
    if entered an output value, then the cycle ends with the output of statistics
	only lettets(upper_case/lower_case) 
	if input(4) < letters in a word(5) - output invalid;
	if input (6) > letters in a word(5) - cut or output invalid;
		-no number;
		-no special symbol;
	transform input to upper_case
 
4. Comparing a word with input:
	comparison algorithm.

5. Output * or if there is a match then a small letter in a random
   place or if the place is correct then a large letter.

6. Statistics output

...


Future:

1. Game level:
	low - word > 5 letters
	medium - word: 5 - 6 - 7 letters
	high - word: 7 - 8 - 9 letters
	very high - word: more than 9 - 10 letters.

2. System of accumulating points and spending them on a hint

3. GUI.

...