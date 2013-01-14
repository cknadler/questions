# Endianness

Write a program that determines the endianness of a system.

## Explanation

The endianness of a system refers to the order in which the system stores data in memory.

There are two formats, big endian and little endian.

#### Big Endian

Words are stored with the most significant byte first.

For example: 1000 is stored as `[03] [E8]`.

#### Little Endian

Words are stored with the most significant byte last.

For example: 1000 is stored as `[E8] [03]`.

## Solution

Create a 32-bit integer with a value of 1 on a system.
If the first byte (lowest address in memory) has a value of 1, the system is little endian. If the value is 0, the system is big endian.

## More Information

* [Wikipedia](http://en.wikipedia.org/wiki/Endianness)
