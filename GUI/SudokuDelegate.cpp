// SudokuDelegate.cpp
#include "SudokuDelegate.h"
#include <QPainter>

void SudokuDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const {
    QStyledItemDelegate::paint(painter, option, index);

    QRect rect = option.rect;
    QPen pen(Qt::black, 1);
    QPen thickPen(Qt::black, 3);

    // 畫格線（左、上、右、下）
    painter->save();
    painter->setPen(pen);

    // 左邊框 - 每三列畫粗
    if (index.column() % 3 == 0) {
        painter->setPen(thickPen);
        painter->drawLine(rect.topLeft(), rect.bottomLeft());
        painter->setPen(pen);
    }

    // 上邊框 - 每三行畫粗
    if (index.row() % 3 == 0) {
        painter->setPen(thickPen);
        painter->drawLine(rect.topLeft(), rect.topRight());
        painter->setPen(pen);
    }

    // 右邊框 - 最右一列畫粗
    if (index.column() == 8) {
        painter->setPen(thickPen);
        painter->drawLine(rect.topRight(), rect.bottomRight());
    } else {
        painter->drawLine(rect.topRight(), rect.bottomRight());
    }

    // 下邊框 - 最下面一行畫粗
    if (index.row() == 8) {
        painter->setPen(thickPen);
        painter->drawLine(rect.bottomLeft(), rect.bottomRight());
    } else {
        painter->drawLine(rect.bottomLeft(), rect.bottomRight());
    }

    painter->restore();
}
