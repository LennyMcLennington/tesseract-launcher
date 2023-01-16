#pragma once

#include <QJsonObject>
#include <QJsonArray>
#include <map>
#include <string>
#include <functional>
#include <utility>

#define RULES_DISALLOW(rules) rules.find("allow") != rules.cend() && !rules["allow"]

namespace Tesseract::Launcher {

    class AbstractRule {
    public:
        virtual void parseJson(QJsonObject& json) { };
        virtual bool evaluate() { return false; };
    };

    struct ManifestRule {
        QString action;
        std::vector<std::shared_ptr<AbstractRule>> rules;
    };

    using ParserRegistry = std::map<QString, std::function<std::shared_ptr<AbstractRule>()>>;
    using RuleSet = std::vector<ManifestRule>;
    using RuleResults = std::map<QString, bool>;

    class RulesParser {
    private:
        const ParserRegistry RULES_PARSERS = createRuleParsers();
        static ParserRegistry createRuleParsers();
    public:
        RuleSet parseRules(const QJsonArray& array);
        static RuleResults evaluateRules(const RuleSet& array);
    };
}
