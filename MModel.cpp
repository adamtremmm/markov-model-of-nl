#include "MModel.hpp"

MModel::MModel(std::string text, int k) {
	text_ = text;
	length_ = text_.size();
	k_ = k;

	for (int i = 0; i < length_; ++i) {
		// build temp string
		std::string k_gram;
		for (int j = i; j < i + k_; ++j) {
			k_gram.push_back(j % length_);
		}
		++symbolTable_[k_gram].frequency;
		++symbolTable_[k_gram].next[text_.at((i + k_) % length_)];
	}
}

int MModel::freq(std::string kgram) {
	checkKGramLength(kgram.size());

	return symbolTable_[kgram].frequency;
}

int MModel::freq(std::string kgram, char c) {
	checkKGramLength(kgram.size());

	return symbolTable_[kgram].next[c];
}

void MModel::checkKGramLength(int length) {
	if (length != k_) {
		// throw runtime error or something
	}
}