#include "word_entry.h"

namespace Imprint {
    WordEntry::WordEntry(std::string word) : word_(word) {}

    std::string_view WordEntry::ConvertPartOfSpeechToString(PartOfSpeech pos) {
        static const std::unordered_map<PartOfSpeech, std::string_view> pos_map = {
            {PartOfSpeech::NOUN, "Interp_Noun"},
            {PartOfSpeech::VERB, "Interp_Verb"},
            {PartOfSpeech::ADJ, "Interp_Adj"},
            {PartOfSpeech::ADV, "Interp_Adv"},
            {PartOfSpeech::PRON, "Interp_Pron"},
            {PartOfSpeech::PREP, "Interp_Prep"},
            {PartOfSpeech::CONJ, "Interp_Conj"},
            {PartOfSpeech::INTJ, "Interp_Intj"},
            {PartOfSpeech::ART, "Interp_Art"},
            {PartOfSpeech::DET, "Interp_Det"},
            {PartOfSpeech::NUM, "Interp_Num"},
            {PartOfSpeech::AUX, "Interp_Aux"},
            {PartOfSpeech::OTHERS, "Interp_Others"}};
        return pos_map.count(pos) ? pos_map.at(pos) : pos_map.at(PartOfSpeech::OTHERS);
    }

    PartOfSpeech WordEntry::ConvertStringToPartOfSpeech(std::string_view pos) {
        for (int i = static_cast<int>(PartOfSpeech::NOUN); i <= static_cast<int>(PartOfSpeech::OTHERS); ++i) {
            if (pos == WordEntry::ConvertPartOfSpeechToString(static_cast<PartOfSpeech>(i))) {
                return static_cast<PartOfSpeech>(i);
            }
        }
        return PartOfSpeech::OTHERS;
    }

} // namespace Imprint