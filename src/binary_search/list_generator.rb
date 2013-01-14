#!/usr/bin/env ruby

# Make a list of numbers between 1 and 100 and sort it
list = []
Random.rand(100..10000).times do
  list << Random.rand(0..100)
end
list.sort!

# Make a key for the number list
# Contains the number each time one of the numbers occurs
key = []
list.each do |num|
  key[num] ||= 0
  key[num] += 1
end

# Write the number list and key
File.open(File.expand_path("numbers.txt"), 'w') do |f|
  f.puts list.length
  f.puts list
end

File.open(File.expand_path("key.txt"), 'w') do |f|
  f.puts "Total elements: #{list.length}"
  key.each_with_index do |num, index|
    f.puts "#{index} : #{num}"
  end
end
