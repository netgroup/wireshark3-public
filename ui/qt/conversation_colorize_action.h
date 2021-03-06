/** @file
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef CONVERSATIONCOLORIZEACTION_H
#define CONVERSATIONCOLORIZEACTION_H

#include <QAction>

struct conversation_filter_s;
struct _packet_info;

// Actions for "Conversation Filter" and "Colorize with Filter" menu items.

class ConversationAction : public QAction
{
    Q_OBJECT
public:
    ConversationAction(QObject *parent, struct conversation_filter_s *conv_filter = NULL);

    bool isFilterValid(struct _packet_info *pinfo);

    const QByteArray filter() { return filter_ba_; }

    void setColorNumber(int color_number) { color_number_ = color_number; }
    int colorNumber() { return color_number_; }

public slots:
    // Exactly one of these should be connected.
    void setPacketInfo(struct _packet_info *pinfo);
    void setFieldFilter(const QByteArray field_filter);

private:
    struct conversation_filter_s *conv_filter_;
    QByteArray filter_ba_;
    int color_number_;
};

class ColorizeAction : public QAction
{
    Q_OBJECT
public:
    ColorizeAction(QObject *parent) : QAction(parent),
        color_number_(-1)
    {}

    const QByteArray filter() { return filter_ba_; }

    void setColorNumber(int color_number) { color_number_ = color_number; }
    int colorNumber() { return color_number_; }

public slots:
    void setFieldFilter(const QByteArray field_filter) { filter_ba_ = field_filter; }

private:
    QByteArray filter_ba_;
    int color_number_;
};

#endif // CONVERSATIONCOLORIZEACTION_H
