#include<stdio.h>
#include<stdbool.h>

/*
Sample Inputs and outputs
"abcdef", "cde" // "abcd" "b"
   ^
"abxdef", "defg"

"aaaab", "aaab"
  ^
*/

//Time Complexity O(n2)
char * substr (char *haystack, char *needle) {
    // NULL Check
    char *ans = NULL;
    if(haystack == NULL || needle == NULL) {
        return ans;
    }
  //  unsigned int lenNeedle = strlen(needle);
  //unsigned int lenHayStack = strlen(haystack);  
  bool reset = true;
  char *tneedle = needle;
  char *thaystack = haystack;
  char *nhaystack = haystack;
    // Both are non-NULL
    while(*nhaystack) {
        thaystack = nhaystack;
        ++nhaystack;
        tneedle = needle; 
        ans = NULL;
        while(*tneedle) {
            if(*tneedle == *thaystack) {
                if (reset == true) {
                    reset = false;
                    ans = thaystack;
                }
                ++tneedle;
                ++thaystack;
            } else {
		reset = true;
		break;
	    }
        }
        if(!(*tneedle)) {
             return ans;
        }
    }
    
    return ans;
}

// Main Function
int main() {
	char *haystack = "aaaam";
        char *needle = "aaam";
	puts(substr(haystack, needle));
	return 0;
}
