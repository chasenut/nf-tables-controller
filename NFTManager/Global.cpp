#include "Global.h"

Global::Global(QObject *parent)
    : QObject{parent}
{
    setColor_theme1(QColor(120, 0, 164));
    setColor_theme2(QColor(161, 0, 194));
    setColor_bg1(QColor(40, 40, 40));
    setColor_bg2(QColor(30, 30, 30));
    setColor_text1(QColor(255, 255, 255));
    setColor_text2(QColor(175, 175, 175));
    setAppWidth(1200);
    setAppHeight(700);
    setAppMinWidth(700);
    setAppMinHeight(500);
    setSelectionBarHeight(55);
    setFontSize1(18);
    setFontSize2(22);
    setFontSize3(26);
    setFontSize4(30);
    setFontSize5(34);
    setFeaturesCount(7);
}

QColor Global::color_bg1() const
{
    return m_color_bg1;
}

void Global::setColor_bg1(const QColor &newColor_bg1)
{
    if (m_color_bg1 == newColor_bg1)
        return;
    m_color_bg1 = newColor_bg1;
    emit color_bg1Changed();
}

QColor Global::color_bg2() const
{
    return m_color_bg2;
}

void Global::setColor_bg2(const QColor &newColor_bg2)
{
    if (m_color_bg2 == newColor_bg2)
        return;
    m_color_bg2 = newColor_bg2;
    emit color_bg2Changed();
}

QColor Global::color_theme1() const
{
    return m_color_theme1;
}

void Global::setColor_theme1(const QColor &newColor_theme1)
{
    if (m_color_theme1 == newColor_theme1)
        return;
    m_color_theme1 = newColor_theme1;
    emit color_theme1Changed();
}

QColor Global::color_theme2() const
{
    return m_color_theme2;
}

void Global::setColor_theme2(const QColor &newColor_theme2)
{
    if (m_color_theme2 == newColor_theme2)
        return;
    m_color_theme2 = newColor_theme2;
    emit color_theme2Changed();
}

int Global::appWidth() const
{
    return m_appWidth;
}

void Global::setAppWidth(int newAppWidth)
{
    if (m_appWidth == newAppWidth)
        return;
    m_appWidth = newAppWidth;
    emit appWidthChanged();
}

int Global::appHeight() const
{
    return m_appHeight;
}

void Global::setAppHeight(int newAppHeight)
{
    if (m_appHeight == newAppHeight)
        return;
    m_appHeight = newAppHeight;
    emit appHeightChanged();
}

int Global::appMinWidth() const
{
    return m_appMinWidth;
}

void Global::setAppMinWidth(int newAppMinWidth)
{
    if (m_appMinWidth == newAppMinWidth)
        return;
    m_appMinWidth = newAppMinWidth;
    emit appMinWidthChanged();
}

int Global::appMinHeight() const
{
    return m_appMinHeight;
}

void Global::setAppMinHeight(int newAppMinHeight)
{
    if (m_appMinHeight == newAppMinHeight)
        return;
    m_appMinHeight = newAppMinHeight;
    emit appMinHeightChanged();
}

int Global::selectionBarHeight() const
{
    return m_selectionBarHeight;
}

void Global::setSelectionBarHeight(int newSelectionBarHeight)
{
    if (m_selectionBarHeight == newSelectionBarHeight)
        return;
    m_selectionBarHeight = newSelectionBarHeight;
    emit selectionBarHeightChanged();
}

int Global::fontSize1() const
{
    return m_fontSize1;
}

void Global::setFontSize1(int newFontSize1)
{
    if (m_fontSize1 == newFontSize1)
        return;
    m_fontSize1 = newFontSize1;
    emit fontSize1Changed();
}

int Global::fontSize2() const
{
    return m_fontSize2;
}

void Global::setFontSize2(int newFontSize2)
{
    if (m_fontSize2 == newFontSize2)
        return;
    m_fontSize2 = newFontSize2;
    emit fontSize2Changed();
}

int Global::featuresCount() const
{
    return m_featuresCount;
}

void Global::setFeaturesCount(int newFeaturesCount)
{
    if (m_featuresCount == newFeaturesCount)
        return;
    m_featuresCount = newFeaturesCount;
    emit featuresCountChanged();
}

QColor Global::color_text1() const
{
    return m_color_text1;
}

void Global::setColor_text1(const QColor &newColor_text1)
{
    if (m_color_text1 == newColor_text1)
        return;
    m_color_text1 = newColor_text1;
    emit color_text1Changed();
}

QColor Global::color_text2() const
{
    return m_color_text2;
}

void Global::setColor_text2(const QColor &newColor_text2)
{
    if (m_color_text2 == newColor_text2)
        return;
    m_color_text2 = newColor_text2;
    emit color_text2Changed();
}

int Global::fontSize3() const
{
    return m_fontSize3;
}

void Global::setFontSize3(int newFontSize3)
{
    if (m_fontSize3 == newFontSize3)
        return;
    m_fontSize3 = newFontSize3;
    emit fontSize3Changed();
}

int Global::fontSize4() const
{
    return m_fontSize4;
}

void Global::setFontSize4(int newFontSize4)
{
    if (m_fontSize4 == newFontSize4)
        return;
    m_fontSize4 = newFontSize4;
    emit fontSize4Changed();
}

int Global::fontSize5() const
{
    return m_fontSize5;
}

void Global::setFontSize5(int newFontSize5)
{
    if (m_fontSize5 == newFontSize5)
        return;
    m_fontSize5 = newFontSize5;
    emit fontSize5Changed();
}
