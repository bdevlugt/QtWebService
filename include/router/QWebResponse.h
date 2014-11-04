/*
 * Copyright 2014 kevin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef QWEBRESPONSE_H
#define QWEBRESPONSE_H

#include "private/qtwebserviceapi.h"
#include "private/qtwebservicefwd.h"

#include <functional>

#include <QObject>
#include <QSharedPointer>
#include <QHash>
#include <QStringList>
#include <QFile>
#include <QJsonDocument>
#include <QDomDocument>

#include <QHttpServer/qhttpresponse.h>

class QTWEBSERVICE_API QWebResponse : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief create Create a new instance of %QWebRequest
     * @param httpReq %QHttpRequest as the base
     * @param urlParams Any parameters that were stored in the url
     * @param splat If a wildcard was used in the URL, this will be matches
     *      from the wildcard.
     * @param parent QObject parent
     * @return Shared pointer
     */
    static QSharedPointer<QWebResponse> create(QHttpResponse *httpResp,
                                      QObject *parent = 0);

    /**
     * @brief writeFile Enqueues the %QFile to be written to the output stream as a byte array. This is done by reading
     * the file to a bytestream, and writing it after.
     * @param file File that will be read, this will emit the signal to middleware hooks
     * @return
     */
    bool writeFile(const QFile &file);

    bool writeText(const QString &text);

//    bool writeText(const QByteArray &text);

//    bool writeJSON(const QJsonDocument &doc);

//    bool writeXML(const QDomDocument &doc);

    /**
     * @brief isValidResponse returns true if a response was queued to be written
     * @return
     */
    bool isValidResponse();

    virtual
    ~QWebResponse();

signals:

public slots:

private:
    explicit QWebResponse(QHttpResponse *httpResp,
                         QObject *parent = 0);

    QHttpResponse * const m_resp;
    std::function<void()> m_outFunc;

};

#endif // QWEBRESPONSE_H