// Copyright 2020 Adam Tremblay

#include <math.h>
#include <random>
#include <iostream>
#include <vector>
#include "MModel.hpp"

const double EPSILON = 0.001;

MModel::MModel(std::string text, int k) {
    text_ = text;
    length_ = text_.size();
    k_ = k;

    for (int i = 0; i < length_; ++i) {
        // build temp string for k-gram
        std::string k_gram;
        for (int j = i; j < i + k_; ++j) {
            k_gram.push_back(text_.at(j % length_));
        }

        // update frequency of k-gram itself
        ++symbolTable_[k_gram].frequency;

        // update frequency of char coming after k-gram
        ++symbolTable_[k_gram].next[text_.at((i + k_) % length_)];
    }
}

int MModel::freq(std::string kgram) {
    if (kgram.size() != k_) {
        std::string error = "freq: kgram is not of length k";
        throw std::runtime_error(error);
    }

    return symbolTable_[kgram].frequency;
}

int MModel::freq(std::string kgram, char c) {
    if (k_ == 0) {
        return symbolTable_[""].next[c];
    } else if (kgram.size() != k_) {
        std::string error = "freq: kgram is not of length k";
        throw std::runtime_error(error);
    }

    return symbolTable_[kgram].next[c];
}

char MModel::kRand(std::string kgram) {
    std::random_device rd;
    std::mt19937 gen(rd());

    if (kgram.size() != k_) {
        std::string error = "kRand: kgram is not of length k";
        throw std::runtime_error(error);
    }

    double maxProb = 0.0;
    std::vector<char> maxChars;

    for (auto const& x : symbolTable_[kgram].next) {
        double prob = x.second / static_cast<double>(freq(kgram));
        if (prob > maxProb) {
            maxProb = prob;
        }
    }

    for (auto const& x : symbolTable_[kgram].next) {
        double prob = x.second / static_cast<double>(freq(kgram));
        if (std::abs(prob - maxProb) < EPSILON) {
            maxChars.push_back(x.first);
        }
    }

    std::uniform_int_distribution<int> dis(0, maxChars.size() - 1);
    int random = dis(gen);

    return maxChars[random];
}

std::string MModel::generate(std::string kgram, int L) {
    std::string temp;
    L -= kgram.size();

    for (int j = 0; j < kgram.size(); ++j) {
        temp.push_back(kgram.at(j));
    }

    for (int i = 0; i < L; ++i) {
        char nextChar = kRand(kgram);
        temp.push_back(nextChar);
        kgram.erase(0, 1);
        kgram.push_back(nextChar);
    }

    return temp;
}
