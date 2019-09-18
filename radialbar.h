/*************************************************************************************
** The MIT License (MIT)
**
** RadialBar is a free Qt and QML based component.
** Copyright (c) 2017 Arun PK
** Email: mailztopk@gmail.com
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
************************************************************************************/

#pragma once

//=======================================================
//== Includes
//=======================================================

#include <QQuickPaintedItem>

//=======================================================
//== Class-Definition
//=======================================================

class RadialBar : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(qreal size               MEMBER size             NOTIFY sizeChanged)
    Q_PROPERTY(qreal startAngle         MEMBER startAngle       NOTIFY startAngleChanged)
    Q_PROPERTY(qreal spanAngle          MEMBER spanAngle        NOTIFY spanAngleChanged)
    Q_PROPERTY(qreal minValue           MEMBER minValue         NOTIFY minValueChanged)
    Q_PROPERTY(qreal maxValue           MEMBER maxValue         NOTIFY maxValueChanged)
    Q_PROPERTY(qreal value              MEMBER value            NOTIFY valueChanged)
    Q_PROPERTY(int dialWidth            MEMBER dialWidth        NOTIFY dialWidthChanged)
    Q_PROPERTY(QColor backgroundColor   MEMBER backgroundColor  NOTIFY backgroundColorChanged)
    Q_PROPERTY(QColor foregroundColor   MEMBER foregroundColor  NOTIFY foregroundColorChanged)
    Q_PROPERTY(QColor progressColor     MEMBER progressColor    NOTIFY progressColorChanged)
    Q_PROPERTY(QColor textColor         MEMBER textColor        NOTIFY textColorChanged)
    Q_PROPERTY(QString suffixText       MEMBER suffixText       NOTIFY suffixTextChanged)
    Q_PROPERTY(bool showText            MEMBER showText         NOTIFY showTextChanged)
    Q_PROPERTY(Qt::PenCapStyle penStyle MEMBER penStyle         NOTIFY penStyleChanged)
    Q_PROPERTY(DialType dialType        MEMBER dialType         NOTIFY dialTypeChanged)
    Q_PROPERTY(QFont textFont           MEMBER textFont         NOTIFY textFontChanged)

public:

    //=======================================================
    //== Enums

    enum DialType { FullDial, MinToMax, NoDial };
    Q_ENUM(DialType)

    //=======================================================
    //== Constructor

    RadialBar(QQuickItem *parent = nullptr);

    //=======================================================
    //== Methods

    virtual void paint(QPainter *painter) override;

private:

    //=======================================================
    //== Properties

    DialType dialType = DialType::MinToMax;
    QColor backgroundColor = Qt::transparent;
    QColor foregroundColor = QColor(80,80,80);
    QColor progressColor = QColor(135,26,5);
    QColor textColor = QColor(20, 20, 20);
    QFont textFont;
    QString suffixText;
    Qt::PenCapStyle penStyle = Qt::FlatCap;
    bool showText = true;
    int dialWidth = 15;
    qreal maxValue = 100;
    qreal minValue = 0;
    qreal size = 200;
    qreal spanAngle = 280;
    qreal startAngle = 40;
    qreal value = 50;

signals:
    void backgroundColorChanged();
    void dialTypeChanged();
    void dialWidthChanged();
    void foregroundColorChanged();
    void maxValueChanged();
    void minValueChanged();
    void penStyleChanged();
    void progressColorChanged();
    void showTextChanged();
    void sizeChanged();
    void spanAngleChanged();
    void startAngleChanged();
    void suffixTextChanged();
    void textColorChanged();
    void textFontChanged();
    void valueChanged();
};
