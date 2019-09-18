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

//=======================================================
//== Includes
//=======================================================

// Qt
#include <QPainter>

// Own
#include "radialbar.h"

//=======================================================
//== Constructors
//=======================================================

RadialBar::RadialBar(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    setWidth(200);
    setHeight(200);
    setSmooth(true);
    setAntialiasing(true);
}

//=======================================================
//== Methods
//=======================================================

void RadialBar::paint(QPainter *painter)
{
    // Predefine variables
    double startAngle = -90 - this->startAngle;
    double spanAngle = FullDial != dialType ? 0 - this->spanAngle : -360;

    // Define size
    qreal size = qMin(this->width(), this->height());
    setWidth(size);
    setHeight(size);
    QRectF rect = this->boundingRect();

    // Prepare painter
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen = painter->pen();
    pen.setCapStyle(penStyle);

    //Draw outer dial
    painter->save();
    pen.setWidth(dialWidth);
    pen.setColor(foregroundColor);
    painter->setPen(pen);
    qreal offset = dialWidth / 2;
    if(dialType == MinToMax) painter->drawArc(rect.adjusted(offset, offset, -offset, -offset), static_cast< int >(startAngle * 16), static_cast< int >(spanAngle * 16));
    else if(dialType == FullDial) painter->drawArc(rect.adjusted(offset, offset, -offset, -offset), -90 * 16, -360 * 16);
    painter->restore();

    //Draw background
    painter->save();
    painter->setBrush(backgroundColor);
    painter->setPen(backgroundColor);
    qreal inner = offset * 2;
    painter->drawEllipse(rect.adjusted(inner, inner, -inner, -inner));
    painter->restore();

    //Draw progress text with suffix
    painter->save();
    painter->setFont(textFont);
    pen.setColor(textColor);
    painter->setPen(pen);
    if(showText) painter->drawText(rect.adjusted(offset, offset, -offset, -offset), Qt::AlignCenter,QString::number(value) + suffixText);
    else painter->drawText(rect.adjusted(offset, offset, -offset, -offset), Qt::AlignCenter, suffixText);
    painter->restore();

    //Draw progress bar
    painter->save();
    pen.setWidth(dialWidth);
    pen.setColor(progressColor);
    qreal valueAngle = ((value - minValue)/(maxValue - minValue)) * spanAngle;  //Map value to angle range
    painter->setPen(pen);
    painter->drawArc(rect.adjusted(offset, offset, -offset, -offset), static_cast< int >(startAngle * 16), static_cast< int >(valueAngle * 16));
    painter->restore();
}
