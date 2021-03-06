/* packet_comment_dialog.cpp
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "packet_comment_dialog.h"
#include <ui_packet_comment_dialog.h>

#include "wireshark_application.h"

PacketCommentDialog::PacketCommentDialog(bool isEdit, QWidget *parent, QString comment) :
    GeometryStateDialog(parent),
    pc_ui_(new Ui::PacketCommentDialog)
{

    QString title = isEdit
        ? tr("Edit Packet Comment")
        : tr("Add Packet Comment");

    pc_ui_->setupUi(this);
    loadGeometry();
    setWindowTitle(wsApp->windowTitleString(title));

    pc_ui_->commentTextEdit->setPlainText(comment);
}

PacketCommentDialog::~PacketCommentDialog()
{
    delete pc_ui_;
}

QString PacketCommentDialog::text()
{
    return pc_ui_->commentTextEdit->toPlainText();
}

void PacketCommentDialog::on_buttonBox_helpRequested()
{
//    wsApp->helpTopicAction(HELP_PACKET_COMMENT_DIALOG);
}
