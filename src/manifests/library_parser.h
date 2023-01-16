#pragma once

#include "rules_parser.h"

#include <string>
#include <QJsonObject>

namespace Tesseract::Launcher {

    struct LibraryEntry {
        ManifestRule rule;
        QString name;
        QString path;
        QString hash;
        long fileSize;
        QString url;
    };

    struct MainJarEntry {
        QString hash;
        long fileSize;
        QString url;
    };

    class LibraryParser {
    private:
        static LibraryEntry parseEntry(QJsonObject& json);
    public:
        static std::vector<LibraryEntry> parseEntries(RulesParser& ruleParser, QJsonArray& json);
        static MainJarEntry parseJar(QJsonObject& json);
    };
}
