#ifndef GLOBAL_H
#define GLOBAL_H

#include <QObject>
#include <QColor>

class Global : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QColor color_theme1 READ color_theme1 WRITE setColor_theme1 NOTIFY color_theme1Changed FINAL)
    Q_PROPERTY(QColor color_theme2 READ color_theme2 WRITE setColor_theme2 NOTIFY color_theme2Changed FINAL)
    Q_PROPERTY(QColor color_bg1 READ color_bg1 WRITE setColor_bg1 NOTIFY color_bg1Changed FINAL)
    Q_PROPERTY(QColor color_bg2 READ color_bg2 WRITE setColor_bg2 NOTIFY color_bg2Changed FINAL)
    Q_PROPERTY(QColor color_text1 READ color_text1 WRITE setColor_text1 NOTIFY color_text1Changed FINAL)
    Q_PROPERTY(QColor color_text2 READ color_text2 WRITE setColor_text2 NOTIFY color_text2Changed FINAL)

    Q_PROPERTY(int appWidth READ appWidth WRITE setAppWidth NOTIFY appWidthChanged FINAL)
    Q_PROPERTY(int appHeight READ appHeight WRITE setAppHeight NOTIFY appHeightChanged FINAL)
    Q_PROPERTY(int appMinWidth READ appMinWidth WRITE setAppMinWidth NOTIFY appMinWidthChanged FINAL)
    Q_PROPERTY(int appMinHeight READ appMinHeight WRITE setAppMinHeight NOTIFY appMinHeightChanged FINAL)
    Q_PROPERTY(int selectionBarHeight READ selectionBarHeight WRITE setSelectionBarHeight NOTIFY selectionBarHeightChanged FINAL)
    Q_PROPERTY(int fontSize1 READ fontSize1 WRITE setFontSize1 NOTIFY fontSize1Changed FINAL)
    Q_PROPERTY(int fontSize2 READ fontSize2 WRITE setFontSize2 NOTIFY fontSize2Changed FINAL)
    Q_PROPERTY(int fontSize3 READ fontSize3 WRITE setFontSize3 NOTIFY fontSize3Changed FINAL)
    Q_PROPERTY(int fontSize4 READ fontSize4 WRITE setFontSize4 NOTIFY fontSize4Changed FINAL)
    Q_PROPERTY(int fontSize5 READ fontSize5 WRITE setFontSize5 NOTIFY fontSize5Changed FINAL)


    Q_PROPERTY(int featuresCount READ featuresCount WRITE setFeaturesCount NOTIFY featuresCountChanged FINAL)
public:
    explicit Global(QObject *parent = nullptr);

    QColor color_bg1() const;
    void setColor_bg1(const QColor &newColor_bg1);

    QColor color_bg2() const;
    void setColor_bg2(const QColor &newColor_bg2);

    QColor color_theme1() const;
    void setColor_theme1(const QColor &newColor_theme1);

    QColor color_theme2() const;
    void setColor_theme2(const QColor &newColor_theme2);

    int appWidth() const;
    void setAppWidth(int newAppWidth);

    int appHeight() const;
    void setAppHeight(int newAppHeight);

    int appMinWidth() const;
    void setAppMinWidth(int newAppMinWidth);

    int appMinHeight() const;
    void setAppMinHeight(int newAppMinHeight);

    int selectionBarHeight() const;
    void setSelectionBarHeight(int newSelectionBarHeight);

    int fontSize1() const;
    void setFontSize1(int newFontSize1);

    int fontSize2() const;
    void setFontSize2(int newFontSize2);

    int featuresCount() const;
    void setFeaturesCount(int newFeaturesCount);

    QColor color_text1() const;
    void setColor_text1(const QColor &newColor_text1);

    QColor color_text2() const;
    void setColor_text2(const QColor &newColor_text2);

    int fontSize3() const;
    void setFontSize3(int newFontSize3);

    int fontSize4() const;
    void setFontSize4(int newFontSize4);

    int fontSize5() const;
    void setFontSize5(int newFontSize5);

signals:
    void color_bg1Changed();

    void color_bg2Changed();

    void color_theme1Changed();

    void color_theme2Changed();

    void appWidthChanged();

    void appHeightChanged();

    void appMinWidthChanged();

    void appMinHeightChanged();

    void selectionBarHeightChanged();

    void fontSize1Changed();

    void fontSize2Changed();

    void featuresCountChanged();

    void color_text1Changed();

    void color_text2Changed();

    void fontSize3Changed();

    void fontSize4Changed();

    void fontSize5Changed();

private:
    QColor m_color_bg1;
    QColor m_color_bg2;
    QColor m_color_theme1;
    QColor m_color_theme2;
    int m_appWidth;
    int m_appHeight;
    int m_appMinWidth;
    int m_appMinHeight;
    int m_selectionBarHeight;
    int m_fontSize1;
    int m_fontSize2;
    int m_featuresCount;
    QColor m_color_text1;
    QColor m_color_text2;
    int m_fontSize3;
    int m_fontSize4;
    int m_fontSize5;
};

#endif // GLOBAL_H
