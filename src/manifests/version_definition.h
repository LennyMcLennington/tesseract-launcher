#pragma once

#include "library_parser.h"
#include "argument_parser.h"
#include "rules_parser.h"

#include <string>
#include <optional>
#include <utility>
#include <vector>

#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace Tesseract::Launcher {

    enum ReleaseType { RELEASE, SNAPSHOT, OLD_BETA, OLD_ALPHA };

    struct JavaVersion {
        QString component;
        short majorVersion;
    };

    class CLIArg {
    private:
        QString key;
        std::optional<QString> value;
    public:
        explicit CLIArg(QString key, std::optional<QString> value = std::nullopt) : key(std::move(key)), value(std::move(value)) { };
        QString serialize();
    };

    struct StartingArgs {
        std::vector<CLIArg> game, jvm;
    };

    class VersionDefinition {

    private:
        RulesParser rulesParser;
        LibraryParser libraryParser;

    public:
        QString mainClass, version;
        ReleaseType releaseType;
        JavaVersion java;
        StartingArgs args;
        MainJarEntry client, server;
        std::vector<LibraryEntry> libraries;
        QDateTime releaseTime;

        VersionDefinition() = default;
        VersionDefinition(QByteArrayView jsonData);
        void parseJson(const QJsonDocument& doc);
    };


}
