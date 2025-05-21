Solution 1:


Time Complexity: O(N)
Space Complexity: O(1)

Code:
int compress(vector<char>& chars) {
        // Append a sentinel character to handle the last group easily
        chars.push_back('~');
        
        int n = chars.size();
        int write_index = 0;  // Position to write the compressed character
        int count = 1;        // Count of current character group
        
        // Start from second character and iterate through the vector
        for (int read_index = 1; read_index < n; read_index++) {
            if (chars[read_index] == chars[read_index - 1]) {
                // Same character as previous, increase count
                count++;
            } else {
                // Different character found, write the previous character
                chars[write_index] = chars[read_index - 1];
                write_index++;
                
                // If count > 1, write its digits as characters
                if (count >= 2) {
                    string count_str = to_string(count);
                    for (char c : count_str) {
                        chars[write_index] = c;
                        write_index++;
                    }
                }
                // Reset count for the new character
                count = 1;
            }
        }
        // Return the length of compressed string
        return write_index;
}