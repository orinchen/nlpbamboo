#ifndef PREPARE_PROCESSOR_HXX
#define PREPARE_PROCESSOR_HXX

#include "processor.hxx"
#include "ilexicon.hxx"
#include "datrie.hxx"
#include "utf8.hxx"

class PrepareProcessor: public Processor {
protected:
	DATrie _chinese_punctuation;
	DATrie _chinese_number;
	DATrie _chinese_alpha;

	PrepareProcessor();
	bool _can_process(LexToken *token)
	{
		return (token->get_attr() == LexToken::attr_unknow);
	}
	void _process(LexToken *token, std::vector<LexToken *> &out);
	void _load_lexicon(DATrie &trie, const char *s)
	{
		size_t length, i;
		char uch[4];

		length = utf8::length(s);
		for (i = 0; i < length; i++) {
			utf8::sub(uch, s, i, 1);
			trie.insert(uch, i + 1);
		}
	}
public:
	PrepareProcessor(IConfig *config);
	~PrepareProcessor() {};
};

#endif // ASCII_PROCESSOR_HXX