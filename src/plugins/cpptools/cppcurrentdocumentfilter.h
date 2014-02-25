/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/
#ifndef CPPCURRENTDOCUMENTFILTER_H
#define CPPCURRENTDOCUMENTFILTER_H

#include "searchsymbols.h"

#include <coreplugin/locator/ilocatorfilter.h>

namespace Core { class IEditor; }

namespace CppTools {
namespace Internal {

class CppModelManager;

class CppCurrentDocumentFilter : public  Core::ILocatorFilter
{
    Q_OBJECT

public:
    explicit CppCurrentDocumentFilter(CppModelManager *manager,
                                      StringTable &stringTable);
    ~CppCurrentDocumentFilter() {}

    QList<Core::LocatorFilterEntry> matchesFor(QFutureInterface<Core::LocatorFilterEntry> &future, const QString &entry);
    void accept(Core::LocatorFilterEntry selection) const;
    void refresh(QFutureInterface<void> &future);

private slots:
    void onDocumentUpdated(CPlusPlus::Document::Ptr doc);
    void onCurrentEditorChanged(Core::IEditor * currentEditor);
    void onEditorAboutToClose(Core::IEditor * currentEditor);

private:
    CppModelManager * m_modelManager;
    QString m_currentFileName;
    QList<ModelItemInfo> m_itemsOfCurrentDoc;
    SearchSymbols search;
};

} // namespace Internal
} // namespace CppTools

#endif // CPPCURRENTDOCUMENTFILTER_H
