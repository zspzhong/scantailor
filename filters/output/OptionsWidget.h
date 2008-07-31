/*
    Scan Tailor - Interactive post-processing tool for scanned pages.
    Copyright (C) 2007-2008  Joseph Artsimovich <joseph_a@mail.ru>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OUTPUT_OPTIONSWIDGET_H_
#define OUTPUT_OPTIONSWIDGET_H_

#include "ui_OutputOptionsWidget.h"
#include "FilterOptionsWidget.h"
#include "IntrusivePtr.h"
#include "PageId.h"
#include "Params.h"
#include "Scope.h"
#include <QColor>
#include <QPixmap>

class QIcon;
class Dpi;

namespace output
{

class Settings;

class OptionsWidget
	: public FilterOptionsWidget, private Ui::OutputOptionsWidget
{
	Q_OBJECT
public:
	OptionsWidget(IntrusivePtr<Settings> const& settings);
	
	virtual ~OptionsWidget();
	
	void preUpdateUI(PageId const& page_id);
	
	void postUpdateUI();
signals:
	void tonesChanged(QColor const& light, QColor const& dark);
private slots:
	void changeDpiButtonClicked();
	
	void dpiChanged(Dpi const& dpi, Scope scope);
	
	void colorModeChanged(int idx);
	
	void thresholdModeChanged(int idx);
	
	void lightColorButtonClicked();
	
	void darkColorButtonClicked();
private:
	static QIcon createIcon(QPixmap const& pixmap);
	
	void updateDpiDisplay(Dpi const& dpi);
	
	IntrusivePtr<Settings> m_ptrSettings;
	PageId m_pageId;
	Params m_pageParams;
	QColor m_lightColor;
	QColor m_darkColor;
	QPixmap m_lightColorPixmap;
	QPixmap m_darkColorPixmap;
};

} // namespace output

#endif