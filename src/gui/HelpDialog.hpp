/*
 * Stellarium
 * Copyright (C) 2007 Matthew Gates
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA  02110-1335, USA.
 */

#ifndef HELPDIALOG_HPP
#define HELPDIALOG_HPP

#include <QString>
#include <QObject>
#include <QSettings>

#include "StelDialog.hpp"

class Ui_helpDialogForm;
class QListWidgetItem;

class HelpDialog : public StelDialog
{
	Q_OBJECT
public:
	HelpDialog(QObject* parent);
	~HelpDialog();

	//! Notify that the application style changed
	void styleChanged();


public slots:
	void retranslate();	

protected:
	//! Initialize the dialog widgets and connect the signals/slots
	virtual void createDialogContent();

	Ui_helpDialogForm* ui;

private slots:
	//! Show/bring to foreground the shortcut editor window.
	void showShortcutsWindow();
	
	//! On tab change, if the Log tab is selected, call refreshLog().
	void updateLog(int);

	//! Updated text in Help tab.
	void updateHelpText(void);

	//! Updated text in About tab.
	void updateAboutText(void);

	//! Sync the displayed log.
	void refreshLog();

	void changePage(QListWidgetItem *current, QListWidgetItem *previous);

};

#endif /*_HELPDIALOG_HPP*/

