#include <map>
#include <string>

struct Frequency {
	int frequency = 0;
	std::map<char, int> next;
};

class MModel {
 public:
 	// Assume that text has length at least k.
 	MModel(std::string text, int k);

 	// order k of Markov model
 	int kOrder() { return k_; };

 	// number of occurrences of kgram in text
 	// (throw an exception if kgram is not of length k)
 	int freq(std::string kgram);

 	// number of times that character c follows kgram
	// if order=0, return num of times char c appears
	// (throw an exception if kgram is not of length k)
	int freq(std::string kgram, char c);

	// random character following given kgram
	// (Throw an exception if kgram is not of length k.
	// Throw an exception if no such kgram.)
	char kRand(std::string kgram);

	// generate a string of length L characters
	// by simulating a trajectory through the corresponding
	// Markov chain. The first k characters of the newly
	// generated string should be the argument kgram.
	// Throw an exception if kgram is not of length k.
	// Assume that L is at least k.
	std::string generate(std::string kgram, int L);

 private:
 	std::map<std::string, Frequency> symbolTable_;
 	std::string text_;
 	int length_;
 	int k_;

 	void checkKGramLength(int length);
};