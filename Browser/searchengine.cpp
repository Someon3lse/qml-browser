/****************************************************************************
*
* QmlBrowser - Web browser with QML page support
* Copyright (C) 2022 Denis Solomatin <toorion@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/
#include "searchengine.h"
#include <QUrlQuery>
#include <QHash>
#include <QPair>
#include "browsersettings.h"

static const QHash<QString,QPair<QString, QString>> searchEngines = {
    {"Google", {"https://google.com/search", "q"}},
    {"DuckDuckGo", {"https://duckduckgo.com/", "q"}},
    {"Yahoo",  {"https://search.yahoo.com/search", "p"}},
    {"Ecosia", {"https://www.ecosia.org/search", "q"}},
    {"Qwant", {"https://www.qwant.com/?q=", "q"}},
    {"Brave", {"https://search.brave.com/search", "q"}},
    {"Bing", {"https://www.bing.com/search", "q"}},
    {"PrivacyWall", {"https://search.privacywall.org/search", "q"}},
    {"Baidu", {"https://www.baidu.com/s", "wd"}},
    {"Yandex", {"https://yandex.com/search/", "text"}},
    {"Startpage", {"https://www.startpage.com/sp/search", "query"}}
};

QStringList SearchEngine::engineList = searchEngines.keys();


SearchEngine::SearchEngine(QObject *parent)
    : QObject{parent}
{

}

QUrl SearchEngine::searchUrl(QString text)
{
    QString engineName = browserSettings->searchEngine();
    QUrl url;
    QUrlQuery query;
    url.setUrl(searchEngines[engineName].first);
    query.addQueryItem(searchEngines[engineName].second, text);
    url.setQuery(query);
    return url;
}
