/** @file
 *
 * Taken from https://wiki.qt.io/Clickable_QLabel and adapted for usage
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef CLICKABLE_LABEL_H_
#define CLICKABLE_LABEL_H_

#include <QLabel>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(QWidget* parent=0);

signals:
    void clicked();
    void clickedAt(const QPoint &global_pos, Qt::MouseButton button);

protected:
    void mouseReleaseEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
};

#endif /* CLICKABLE_LABEL_H_ */
