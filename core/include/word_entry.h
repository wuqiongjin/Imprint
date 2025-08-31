#pragma once
#include <memory>
#include <string>
#include <unordered_map>

#include "logger.h"

namespace Imprint {

    enum class PartOfSpeech {
        NOUN = 1,
        VERB,
        ADJ,
        ADV,
        PRON,
        PREP,
        CONJ,
        INTJ,
        ART,
        DET,
        NUM,
        AUX,
        OTHERS
    };

    struct WordEntry {
    public:
        WordEntry(std::string word);
        static std::string_view ConvertPartOfSpeechToString(PartOfSpeech pos);
        static PartOfSpeech ConvertStringToPartOfSpeech(std::string_view pos);


        std::string word_;
        std::string phonetic_UK_;
        std::string phonetic_US_;
        std::unordered_map<PartOfSpeech, std::string> interpretations_;
    private:
        std::unique_ptr<Logger> logger_ = std::make_unique<Logger>("WordEntry");
    };
} // namespace Imprint