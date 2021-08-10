2sum problem 

Problem Statement : Accept an array of elements, target element.

Output : 1. Return pair of elements that sum up to target,
            do not print duplicate pairs for single pair 
            of elements.
         2. If there are n pairs in input, print n pairs in output

Solution - Problem has been solved using hash map to store the repeated 
keys and its frequency. The key is the diff between target and current
iterated number. The value is the frequency that the diff is calculated.
We iterate over each element of the array and put the diff's on the 
hash map along with number of times it occurs. If the other number of the 
pair that makes up the hash map is found then we print the pair, decrement 
the frequency (value) for the key. If value is 0 we will delete the entry
from the hash table.

Alternative apporach is sorting the list and using two pointers (starting
from start and end of the array) to calculate sum and match against target.
If it doesn't match we increment/decrement the low and high pointers resp.
