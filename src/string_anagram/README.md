# string anagram

Write a function to determine if a string if a string is an anagram of another string.

## Additional information

* The strings are in ASCII.
* The length of the strings are less than 256 characters each.
* Spaces matter and are treated as normal characters.

## Solution

Make an array ints of size 256 (number of ascii characters).
If the two strings are different sizes, they cant be anagrams.
If they are the same size, add each occurance of a character in one string to the array.
Subtract all occurances of characters in the second string from the array.
If any element in the array reaches < 0, the second string is not an anagram.
Otherwise, it is.

## Other possible solutions

If you can modify the strings, an easy solution is to sort both of them and then compare each character to make sure they are the same. This isn't as fast but is dead simple and super easy to understand.
