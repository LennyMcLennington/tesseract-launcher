#include "version_definition.h"

#include "qstringliteral.h"
#include "utils/os_utils.h"
#include "utils/json_utils.h"
#include "rules_parser.h"
#include <QJsonArray>
#include <QJsonObject>
#include <map>

#include <QStringLiteral>

namespace Tesseract::Launcher {

    QString CLIArg::serialize() {
        return "--" + key + (value.has_value() ? " " + value.value() : "");
    }

    void VersionDefinition::parseJson(const QJsonDocument& doc) {
        mainClass = JsonUtils::jsonString(doc.object(), "mainClass");
        version =  JsonUtils::jsonString(doc.object(), "id");

        QJsonObject javaObj = doc.object()["javaVersion"].toObject();
        java = {
                .component =  JsonUtils::jsonString(javaObj, "component"),
                .majorVersion = static_cast<short>(javaObj["majorVersion"].toInt())};

        QJsonArray libs = doc.object()["libraries"].toArray();
        libraries = libraryParser.parseEntries(rulesParser, libs);
    }
}




