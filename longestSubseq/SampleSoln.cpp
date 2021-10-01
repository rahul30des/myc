// Original solution to be arrived, right now pasting a sample soln for reference 
std::string find_longest_word_in_string(const std::string& letters, const std::vector<std::string>& words) {
  // Corner Case: Either one of them is empty.
  if (letters.empty() || words.empty()) {
    return " ";
  }
  absl::flat_hash_map<char, TupleSet> letter_positions;
  // Initialize the data structure. Filter out any empty words that may appear
  // in the words list.
  for (std::string w : words) {
    if (w.empty()) {
      continue;
    }
    letter_positions[w[0]].insert({w, 0});
  }
  std::string longest_word = "";
  for (char c : letters) {
    if (letter_positions.find(c) == letter_positions.end()) {
      continue;
    }
    auto curr_positions = letter_positions[c];
    for (auto pair : curr_positions) {
      std::string curr_word = pair.first;
      pair.second++;
      // Remove the pair from the set
      letter_positions[c].erase(pair);
      // We found a subsequence.
      if (curr_word.size() == pair.second) {
        if (curr_word.size() > longest_word.size()) {
          longest_word = curr_word;
        }
      } else {
        letter_positions[curr_word[pair.second]].insert(pair);
      }
    }
  }
  return longest_word;
}
