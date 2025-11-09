// What is Trie?
// Trie is a tree-like data structure that stores a dynamic set of strings,
// where the keys are usually strings. It is used for efficient retrieval of a key in a dataset of strings.
// The main idea is to store common prefixes of strings together in the same path of the tree

// The Trie data structure is used to store a set of keys represented as strings. It allows for efficient retrieval and storage of keys, making it highly effective in handling large datasets. Trie supports operations such as insertion, search, deletion of keys, and prefix searches.

class TrieNode {
    public:
    char data;
    TrieNode* children[26]; // Assuming only lowercase a-z
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;

    public:
    Trie() {
        root = new TrieNode('\0'); // Root node with null character
    }

    // Insert a word into the Trie
    void insertWord(const std::string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            int index = ch - 'a'; // Calculate index for the character
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode(ch);
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isTerminal = true; // Mark the end of the word
    }

    // Search for a word in the Trie
    bool searchWord(const std::string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                return false; // Character path does not exist
            }
            currentNode = currentNode->children[index];
        }
        return currentNode->isTerminal; // Return true if it's a terminal node
    }

    // Check if there is any word in the Trie that starts with the given prefix
    bool startsWith(const std::string& prefix) {
        TrieNode* currentNode = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                return false; // Character path does not exist
            }
            currentNode = currentNode->children[index];
        }
        return true; // All characters in the prefix are found
    }

}

int main() {

    return 0;
}